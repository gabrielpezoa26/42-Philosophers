/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:49:56 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/24 15:30:37 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eating(t_philo *philo)
{
	t_env	*env;
	long	start_time;

	env = philo->environment;
	pthread_mutex_lock(&env->freeze_env);
	philo->last_meal_time = get_absolute_time();
	philo->meals_count++;
	if (env->times_must_eat > 0 && philo->meals_count >= env->times_must_eat)
		philo->is_full = true;
	pthread_mutex_unlock(&env->freeze_env);
	if (env->end_cycle)
		return ;
	print_message(env, philo->id, "is eating");
	start_time = get_time(env);
	while (!env->end_cycle && get_time(env) - start_time < env->time_to_eat)
		usleep(200);
}

void	sleeping(t_philo *philo)
{
	t_env	*env;
	long	start_time;

	env = philo->environment;
	if (env->end_cycle)
		return ;
	print_message(env, philo->id, "is sleeping");
	start_time = get_time(env);
	while (!env->end_cycle && get_time(env) - start_time < env->time_to_sleep)
		usleep(200);
}

void	thinking(t_philo *philo)
{
	t_env	*env;
	long	start_time;

	env = philo->environment;
	if (env->end_cycle)
		return ;
	print_message(env, philo->id, "is thinking");
	start_time = get_time(env);
	while (!env->end_cycle && get_time(env) - start_time < env->time_to_think)
		usleep(200);
}
