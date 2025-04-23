/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:49:56 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/23 17:08:16 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	*monitor_routine(void *arg)
{
	t_env	*env;
	int		counter_full_philos;
	
	env = (t_env *)arg;
	while(!(env->end_cycle))
	{
		counter_full_philos = 0;
		if (is_philo_dead(env))
			return (NULL);
		// if (is_all_philos_full())
		// 	return (NULL);
		if (env->meals_count > 0 && counter_full_philos == env->philo_amount)
		{
			env->end_cycle = 1;
			return (NULL);
		}
		ft_usleep(1000, env);
	}
	return (NULL);
}

static void	*routine(void *arg)
{
	t_env *env;

	env = (void *)arg;
	while(!env->end_cycle)
	{
		printf("pick forks\n");
		eating();
		printf("drop forks\n");
		sleeping();
		thinking();
	}
	return (NULL);
}

void	start_cycle(t_env *env)
{
	int	i;

	i = 0;
	pthread_create(&env->monitor, NULL, monitor_routine,  env);
	while (i < env->philo_amount)
	{
		printf("DEBUG: creating philo: %i\n", i + 1);
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
