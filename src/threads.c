/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:49:56 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/23 00:26:42 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// static void	*monitor_routine(void *arg)
// {
// 	// verifica se alguem morreu ou meals_eaten == times_must_eat
// 	t_env	*env;
// 	int		counter_full_philos;
	
// 	while(!(env->end_cycle))
// 	{
		
// 	}

// }

static void	*routine(void *arg)
{
	t_env *env;

	env = (void *)arg;
	printf("pick forks\n");
	printf("is eatinggg\n");
	printf("drop forks\n");
	printf("is sleeping\n");
	printf("is thinking\n");
	printf("monitor routineeeee\n");
	return (NULL);
}

void	start_cycle(t_env *env)
{
	int	i;

	i = 0;
	// pthread_create(&env->monitor, NULL, monitor_routine,  env);
	while (i < env->philo_amount)
	{
		printf("DEBUG: creating philo: %i\n", i);
		pthread_create(&env->philos[i].thread_id, NULL, routine,
			&env->philos[i]);
		i++;
	}
	// pthread_join(env->monitor, NULL); // unitialised
	i = 0;
	while (i < (env->philo_amount))
	{
		pthread_join(env->philos[i].thread_id, NULL);
		i++;
	}
}
