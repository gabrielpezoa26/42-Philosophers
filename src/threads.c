/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:49:56 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/21 02:55:53 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// static void	*monitor_routine(t_env *env)
// {
// 	// if (env->times_must_eat == )
// 	// verifica se algum philo morreu
// }

static void	*routine(void *context)
{
	(void)context;
	printf("is eatingg\n");
	printf("is sleeping\n");
	printf("is thinking\n");
	printf("monitor routine pocando\n");
	return (NULL);
}

void	start_cycle(t_env *env)
{
	int	i;

	i = 0;
	// pthread_create(&env->monitor, NULL, monitor_routine, NULL);
	while (i < env->philo_amount)
	{
		printf("DEBUG: creating philo: %i\n", i);
		// monitor
		pthread_create(&env->philos[i].thread_id, NULL, routine,
			&env->philos[i]);
		i++;
	}
	pthread_join(env->monitor, NULL); // unitialised
	i = 0;
	while (i < (env->philo_amount))
	{
		pthread_join(env->philos[i].thread_id, NULL);
		i++;
	}
}
