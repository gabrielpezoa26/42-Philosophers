/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:49:56 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/23 23:52:09 by gcesar-n         ###   ########.fr       */
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

void	take_forks(t_philo *p)
{
	t_env	*e;

	e = p->environment;
	if (p->id % 2 == 0)
	{
		pthread_mutex_lock(&p->r_fork->fork);
		if (e->end_cycle) { pthread_mutex_unlock(&p->r_fork->fork); return ; }
		log_fork(e, p->id);
		pthread_mutex_lock(&p->l_fork->fork);
		if (e->end_cycle) { drop_forks(p); return ; }
		log_fork(e, p->id);
	}
	else
	{
		pthread_mutex_lock(&p->l_fork->fork);
		if (e->end_cycle) { pthread_mutex_unlock(&p->l_fork->fork); return ; }
		log_fork(e, p->id);
		pthread_mutex_lock(&p->r_fork->fork);
		if (e->end_cycle) { drop_forks(p); return ; }
		log_fork(e, p->id);
	}
}

void	drop_forks(t_philo *p)
{
	pthread_mutex_unlock(&p->l_fork->fork);
	pthread_mutex_unlock(&p->r_fork->fork);
}

/* ------------------------------ actions -------------------------------- */
void	eating(t_philo *p)
{
	t_env	*e;
	long	start;

	e = p->environment;
	pthread_mutex_lock(&e->freeze_env);
	p->last_meal_time = get_absolute_time();
	pthread_mutex_unlock(&e->freeze_env);
	if (e->end_cycle) return ;
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
	if (e->end_cycle) return ;
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
	if (e->end_cycle) return ;
	log_state(e, p->id, "is thinking");
	start = get_time(e);
	while (!e->end_cycle && get_time(e) - start < e->time_to_think)
		usleep(200);
}
