/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:46:28 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/24 21:33:21 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	handle_single_philo(t_philo *philo)
{
	t_env	*env;
	long	start;

	env = philo->environment;
	pthread_mutex_lock(&philo->l_fork->fork);
	pthread_mutex_lock(&env->freeze_to_print);
	printf("%ld %d has taken a fork\n", get_time(env), philo->id);
	pthread_mutex_unlock(&env->freeze_to_print);
	start = get_time(env);
	while (!sim_stopped(env) && get_time(env) - start < env->time_to_die)
		usleep(200);
	pthread_mutex_unlock(&philo->l_fork->fork);
}

bool	is_philo_dead(t_env *env)
{
	int		i;
	long	now_ms;
	long	last_ms;

	i = 0;
	while (i < env->philo_amount)
	{
		now_ms = get_absolute_time();
		pthread_mutex_lock(&env->freeze_env);
		last_ms = env->philos[i].last_meal_time;
		pthread_mutex_unlock(&env->freeze_env);
		if (now_ms - last_ms >= env->time_to_die)
		{
			pthread_mutex_lock(&env->freeze_to_print);
			printf("%ld %d died\n", get_time(env), env->philos[i].id);
			pthread_mutex_unlock(&env->freeze_to_print);
			pthread_mutex_lock(&env->monitor_mtx);
			env->end_cycle = true;
			pthread_mutex_unlock(&env->monitor_mtx);
			return (true);
		}
		i++;
	}
	return (false);
}

bool	is_philos_full(t_env *env)
{
	int	i;
	int	meals;

	i = 0;
	if (env->times_must_eat < 0)
		return (false);
	while (i < env->philo_amount)
	{
		pthread_mutex_lock(&env->freeze_env);
		meals = env->philos[i].meals_count;
		pthread_mutex_unlock(&env->freeze_env);
		if (meals < env->times_must_eat)
			return (false);
		i++;
	}
	return (true);
}

long	get_absolute_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

long	get_time(t_env *env)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000 + tv.tv_usec / 1000) - env->start_time);
}
