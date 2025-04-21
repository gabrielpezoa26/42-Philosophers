/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:46:28 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/21 17:34:14 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// bool is_philo_dead(t_env *env)
// {
// 	if (tempo desde ultima comida > tempo de morrer)
// 		env->end_cycle = 1
// }

void	ft_sleep(long time, t_table *env)
{
	long	start_time;
	long	elapsed_time;
	long	remaining_time;

	start_time = get_current_time();
	while (current_time() - start_time < time)
	{
		if (env->end_cycle)
			break ;
		elapsed_time = get_current_time() - start_time;
		if (elapsed_time >= time)
			break ;
		remaining_time = time - elapsed_time;
		if (remaining_time > 5)
			usleep(remaining_time * 500);
		else
			usleep(100);
	}
}

long	current_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		printf("gettimeofday fail\n");
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
