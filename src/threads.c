/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:49:56 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/23 20:06:51 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	*monitor_routine(void *arg)
{
	t_env	*env;
	
	env = (t_env *)arg;
	while(!(env->end_cycle))
	{
		if (is_philo_dead(env))
		{
			printf("DEBUG: monitor:aaaaaaaaaaaaaaaa\n");
			env->end_cycle = true;
		}
		if (is_all_philos_full(env))
		{
			printf("DEBUG: bbbbbbbbbbbbbbb\n");
			env->end_cycle = true;
		}
	}
	return (NULL);
}

static void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->environment->end_cycle)
	{
		if (philo->environment->philo_amount == 1)
		{
			printf("%ld philo %d has taken a fork\n", get_time(philo->environment), philo->id);
			usleep(philo->environment->time_to_die * 1000);
			printf("%ld philo %i died\n", get_time(philo->environment), philo->id);
			philo->environment->end_cycle = true;
			break ;
		}
	}
	return (NULL);
}

void	start_cycle(t_env *env)
{
	int	i;

	env->start_time = get_absolute_time();
	pthread_create(&env->monitor, NULL, monitor_routine, env);
	i = 0;
	while (i < (env->philo_amount))
	{
		env->philos[i].last_meal_time = env->start_time;
		pthread_create(&env->philos[i].thread_id, NULL, routine,
			&env->philos[i]);
		i++;
	}
	pthread_join(env->monitor, NULL); // unitialised
	i = 0;
	while (i < (env->philo_amount))
	{
		pthread_join(env->philos[i].thread_id, NULL);
		i++;
	}
}
