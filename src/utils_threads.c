/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:46:28 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/23 00:01:13 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// bool is_philo_dead(t_env *env)
// {
// 	if (tempo desde ultima comida > tempo de morrer)
// 		env->end_cycle = 1
// }

// void	ft_sleep(long time, t_table *env)
// {
// 	long	start_time;
// 	long	elapsed_time;
// 	long	remaining_time;

// 	start_time = get_current_time();
// 	while (current_time() - start_time < time)
// 	{
// 		if (env->end_cycle)
// 			break ;
// 		elapsed_time = get_current_time() - start_time;
// 		if (elapsed_time >= time)
// 			break ;
// 		remaining_time = time - elapsed_time;
// 		if (remaining_time > 5)
// 			usleep(remaining_time * 500);
// 		else
// 			usleep(100);
// 	}
// }

// static uint64_t	get_time_us(void)
// {
// 	struct timeval tv;

// 	gettimeofday(&tv, NULL);
// 	return ((uint64_t)tv.tv_sec * 1000000ULL + (uint64_t)tv.tv_usec);
// }

// void	ft_usleep(uint64_t duration_us, t_env *env)
// {
// 	uint64_t	start_time_us;
// 	uint64_t	elapsed_time_us;
// 	uint64_t	remaining_time_us;

// 	start_time_us = get_time_us();
// 	while (!env->end_cycle)
// 	{
// 		elapsed_time_us = get_time_us() - start_time_us;
// 		if (elapsed_time_us >= duration_us)
// 			break;
// 		remaining_time_us = duration_us - elapsed_time_us;
// 		if (remaining_time_us > 2000)
// 			usleep(remaining_time_us / 2);
// 		else
// 			usleep(200);
// 	}
// }

long	current_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		printf("gettimeofday fail\n");
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
