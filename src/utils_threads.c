/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:46:28 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/23 20:14:04 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	is_philo_dead(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->philo_amount)
	{
		pthread_mutex_lock(&env->freeze_env);
		if (get_time(env) - env->philos[i].last_meal_time > env->time_to_die)
		{
			pthread_mutex_lock(&env->freeze_env);
			// printf("%ld philo %i died\n", get_time(env), i + 1);
			// env->end_cycle = true;
			pthread_mutex_unlock(&env->freeze_to_print);
			pthread_mutex_unlock(&env->freeze_env);
			return (true);
		}
		pthread_mutex_unlock(&env->freeze_env);
		i++;
	}
	return (false);
}

// bool	is_philo_dead(t_env *env)
// {
// 	int		i;
// 	long	current_time;
// 	long	time_since_last_meal;

// 	i = 0;
// 	while (i < env->philo_amount)
// 	{
// 		current_time = get_absolute_time();
// 		time_since_last_meal = current_time - env->philos[i].last_meal_time;
// 		if (time_since_last_meal > env->time_to_die)
// 		{
// 			pthread_mutex_lock(&env->freeze_to_print);
// 			printf("%ld philo %d died\n", get_time(env), env->philos[i].id);
// 			pthread_mutex_unlock(&env->freeze_to_print);
// 			pthread_mutex_lock(&env->monitor_mtx);
// 			env->end_cycle = true;
// 			pthread_mutex_unlock(&env->monitor_mtx);
// 			return (true);
// 		}
// 		i++;
// 	}
// 	return (false);
// }

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
	struct timeval	time;
	long	current;

	gettimeofday(&time, NULL);
	current = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (current);
}

long	get_time(t_env *env)
{
	struct timeval	time;
	long current;

	gettimeofday(&time, NULL);
	current = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (current - env->start_time);
}
