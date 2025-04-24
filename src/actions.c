/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:49:56 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/23 22:10:01 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eating(void)
{
	printf("is eating\n");
	usleep(100);  //debug
}

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

// void	eating(t_philo *philo)
// {
// 	printf("is eating\n");
// 	usleep(100);  //debug
// }

// void	sleeping(t_philo *philo)
// {
// 	printf("is sleeping\n");
// 	usleep(philo->environment->time_to_sleep);
// }

// void	thinking(t_philo *philo)
// {
// 	printf("is thinking\n");
// 	usleep(philo->environment->time_to_think);
// }
