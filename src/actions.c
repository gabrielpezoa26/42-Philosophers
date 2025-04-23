/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:49:56 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/23 17:41:10 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eating(void)
{
	printf("is eating\n");
	usleep(100);  //debug
}

// void eating(void)
// {
// 	t_env *env;
	
// 	pthread_mutex_lock();
// 	printf("%d is eating\n", i);
// 	env->philos->meals_count++;
// 	pthread_mutex_unlock();
// }

void	sleeping(void)
{
	printf("is sleeping\n");
	usleep(1000); //debug
}

void	thinking(void)
{
	printf("is thinking\n");
	usleep(10000); //debug
}
