/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:49:56 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/24 23:09:21 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	*monitor_routine(void *arg)
{
	t_env	*env;

	env = (t_env *)arg;
	while (sim_running(env))
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
	t_env	*env;

	philo = (t_philo *)arg;
	env = philo->environment;
	while (sim_running(env))
	{
		if (env->philo_amount == 1)
			return (handle_single_philo(philo), NULL);
		if (!take_forks(philo))
			continue ;
		eating(philo);
		drop_forks(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

void	launch_cycle(t_env *env)
{
	int	i;

	env->start_time = get_absolute_time();
	pthread_mutex_lock(&env->freeze_env);
	i = 0;
	while (i < env->philo_amount)
	{
		env->philos[i].last_meal_time = env->start_time;
		i++;
	}
	pthread_mutex_unlock(&env->freeze_env);
	pthread_create(&env->monitor, NULL, monitor_routine, env);
	i = 0;
	while (i < env->philo_amount)
	{
		pthread_create(&env->philos[i].thread_id, NULL,
			routine, &env->philos[i]);
		i++;
	}
	pthread_join(env->monitor, NULL);
	i = 0;
	while (i < env->philo_amount)
		pthread_join(env->philos[i++].thread_id, NULL);
}
