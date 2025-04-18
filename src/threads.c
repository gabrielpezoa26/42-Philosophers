/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:49:56 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/18 18:42:52 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// void monitor_routine(t_env)

void start_cycle(t_env *env)
{
	int	i;

	i = 1;
	// monitor
	while (i <= env->philo_amount)
	{
		// monitor
		printf("DEBUG: criou uma threadddd %i\n", i);
		i++;
	}
	printf("DEBUG: saiu start_cycle\n");

}