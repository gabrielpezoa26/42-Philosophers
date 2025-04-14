/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:22:33 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/14 00:31:55 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_env	t_env;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}	t_fork;

typedef struct s_philo
{
	int			id;
	long		meals_count;
	bool		is_full;
	long		last_meal;
	t_fork		*l_fork;
	t_fork		*r_fork;
	pthread_t	thread_t;
	t_env		*environment;
}	t_philo;

struct s_env
{
	long	philo_amount;
	long	die_time;
	long	eat_time;
	long	sleep_time;
	long	max_meals;
	long	start_cycle;
	bool	end_cycle;
	t_fork	*forks;
	t_philo	*philos;
};

/*-----PARSER-----*/
int	validate_input(int argc, char **argv);

/*-----UTILS-----*/
int	ft_atoi(char *str);
int	is_valid_number(char *arg);

#endif