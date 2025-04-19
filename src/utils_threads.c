/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:46:28 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/19 20:23:46 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// bool is_philo_dead(t_env *env);

// void	ft_sleep(long time_ms, t_env *env)
// {
// 	long	start_time_ms;
// 	long	elapsed_time_ms;
// 	long	remaining_time_ms;

// 	start_time_ms = get_current_time();
// 	while (get_current_time() - start_time_ms < time_ms)
// 	{
// 		if (env->end_simulation)
// 			break ;
// 		elapsed_time_ms = get_current_time() - start_time_ms;
// 		if (elapsed_time_ms >= time_ms)
// 			break ;
// 		remaining_time_ms = time_ms - elapsed_time_ms;
// 		if (remaining_time_ms > 5)
// 			usleep(remaining_time_ms * 500);
// 		else
// 			usleep(100);
// 	}
// }
