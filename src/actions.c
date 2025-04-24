/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:49:56 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/24 00:22:02 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	log_state(t_env *e, int id, char *msg)
{
	pthread_mutex_lock(&e->freeze_to_print);
	if (!e->end_cycle)
		printf("%ld %d %s\n", get_time(e), id, msg);
	pthread_mutex_unlock(&e->freeze_to_print);
}

static void	log_fork(t_env *e, int id)
{
	pthread_mutex_lock(&e->freeze_to_print);
	if (!e->end_cycle)
		printf("%ld %d has taken a fork\n", get_time(e), id);
	pthread_mutex_unlock(&e->freeze_to_print);
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
	log_fork(env, philo->id);
	if (!lock_fork(env, second))
	{
		pthread_mutex_unlock(first);
		return ;
	}
	log_fork(env, philo->id);
}

void	drop_forks(t_philo *p)
{
	pthread_mutex_unlock(&p->l_fork->fork);
	pthread_mutex_unlock(&p->r_fork->fork);
}

void	eating(t_philo *p)
{
	t_env	*e;
	long	start;

	e = p->environment;
	pthread_mutex_lock(&e->freeze_env);
	p->last_meal_time = get_absolute_time();
	p->meals_count++;
	if (e->times_must_eat > 0 && p->meals_count >= e->times_must_eat)
		p->is_full = true;
	pthread_mutex_unlock(&e->freeze_env);
	if (e->end_cycle)
		return ;
	log_state(e, p->id, "is eating");
	start = get_time(e);
	while (!e->end_cycle && get_time(e) - start < e->time_to_eat)
		usleep(200);
}

void	sleeping(t_philo *p)
{
	t_env	*e;
	long	start;

	e = p->environment;
	if (e->end_cycle)
		return ;
	log_state(e, p->id, "is sleeping");
	start = get_time(e);
	while (!e->end_cycle && get_time(e) - start < e->time_to_sleep)
		usleep(200);
}

void	thinking(t_philo *p)
{
	t_env	*e;
	long	start;

	e = p->environment;
	if (e->end_cycle)
		return ;
	log_state(e, p->id, "is thinking");
	start = get_time(e);
	while (!e->end_cycle && get_time(e) - start < e->time_to_think)
		usleep(200);
}
