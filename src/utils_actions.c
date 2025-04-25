/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 00:57:46 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/24 21:35:01 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_message(t_env *env, int id, char *msg)
{
	pthread_mutex_lock(&env->freeze_to_print);
	if (!sim_stopped(env))
		printf("%ld %d %s\n", get_time(env), id, msg);
	pthread_mutex_unlock(&env->freeze_to_print);
}

static int	lock_fork(t_env *env, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	if (sim_stopped(env))
	{
		pthread_mutex_unlock(fork);
		return (0);
	}
	return (1);
}

int	take_forks(t_philo *philo)
{
	t_env			*env;
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	env = philo->environment;
	if (philo->id % 2 == 0)
	{
		first = &philo->r_fork->fork;
		second = &philo->l_fork->fork;
	}
	else
	{
		first = &philo->l_fork->fork;
		second = &philo->r_fork->fork;
	}
	if (!lock_fork(env, first))
		return (0);
	print_message(env, philo->id, "has taken a fork");
	if (!lock_fork(env, second))
	{
		pthread_mutex_unlock(first);
		return (0);
	}
	print_message(env, philo->id, "has taken a fork");
	return (1);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->l_fork->fork);
	pthread_mutex_unlock(&philo->r_fork->fork);
}

bool	sim_running(t_env *env)
{
	bool	running;

	pthread_mutex_lock(&env->monitor_mtx);
	running = !env->end_cycle;
	pthread_mutex_unlock(&env->monitor_mtx);
	return (running);
}