/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:46:28 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/23 17:04:44 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	is_philo_dead(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->philo_amount)
	{
		pthread_mutex_lock(&env->freeze_to_print);
		if (get_time(env) - env->philos[i].last_meal_time > env->time_to_die)
		{
			pthread_mutex_lock(&env->freeze_env);
			printf("%ld philo %i died\n", get_time(env), i + 1);
			pthread_mutex_unlock(&env->freeze_to_print);
			pthread_mutex_unlock(&env->freeze_env);
			return (true);
		}
		pthread_mutex_unlock(&env->freeze_env);
		i++;
	}
	return (false);
}

// bool	is_all_philos_full(t_env *t_env)
// {
// 	int	i;

// 	while()
// 	{
// 		if (qtde comeram == env->times_must_eat)
// 	}
// }

void	ft_usleep(uint64_t duration_us, t_env *env)
{
	uint64_t	start_time_us;
	uint64_t	elapsed_time_us;
	uint64_t	remaining_time_us;

	start_time_us = get_time(env);
	while (!env->end_cycle)
	{
		elapsed_time_us = get_time(env) - start_time_us;
		if (elapsed_time_us >= duration_us)
			break;
		remaining_time_us = duration_us - elapsed_time_us;
		if (remaining_time_us > 2000)
			usleep(remaining_time_us / 2);
		else
			usleep(200);
	}
}

long	get_time(t_env *env)
{
	struct timeval	time;
	long current;

	gettimeofday(&time, NULL);
	current = time.tv_sec * 1000 + time.tv_sec / 1000;
	return (current - env->start_time);
}
