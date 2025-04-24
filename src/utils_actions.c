/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 00:57:46 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/24 01:00:21 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_message(t_env *env, int id, char *msg)
{
	pthread_mutex_lock(&env->freeze_to_print);
	if (!env->end_cycle)
		printf("%ld %d %s\n", get_time(env), id, msg);
	pthread_mutex_unlock(&env->freeze_to_print);
}

static int	lock_fork(t_env *env, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	if (env->end_cycle)
	{
		pthread_mutex_unlock(fork);
		return (0);
	}
	return (1);
}

void	take_forks(t_philo *philo)
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
		return ;
	print_message(env, philo->id, "has taken a fork");
	if (!lock_fork(env, second))
	{
		pthread_mutex_unlock(first);
		return ;
	}
	print_message(env, philo->id, "has taken a fork");
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->l_fork->fork);
	pthread_mutex_unlock(&philo->r_fork->fork);
}
