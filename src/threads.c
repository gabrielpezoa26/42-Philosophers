/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:49:56 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/24 00:38:52 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	*monitor_routine(void *arg)
{
	t_env	*env;

	env = (t_env *)arg;
	while (!env->end_cycle)
	{
		if (is_philo_dead(env))
			break ;
		if (is_philos_full(env))
		{
			pthread_mutex_lock(&env->monitor_mtx);
			env->end_cycle = true;
			pthread_mutex_unlock(&env->monitor_mtx);
			break ;
		}
		usleep(200);
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
			handle_single_philo(philo);
			return (NULL);
		}
		if (philo->environment->philo_amount > 1)
		{
			take_forks(philo);
			eating(philo);
			drop_forks(philo);
			sleeping(philo);
			thinking(philo);
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
	pthread_join(env->monitor, NULL);
	i = 0;
	while (i < (env->philo_amount))
	{
		pthread_join(env->philos[i].thread_id, NULL);
		i++;
	}
}
