/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:22:33 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/18 15:46:29 by gcesar-n         ###   ########.fr       */
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
	int			meals_count;
	bool		is_full;
	long		last_meal_time;
	t_fork		*l_fork;
	t_fork		*r_fork;
	pthread_t	thread_id;
	t_env		*environment;
}	t_philo;

struct s_env
{
	int				philo_amount;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				times_must_eat;
	long			start_time;
	bool			end_cycle;
	pthread_mutex_t	freeze_to_print; //obs
	pthread_mutex_t	freeze_env; //obs
	t_fork			*forks;
	t_philo			*philos;
};

/*-----PARSER-----*/
bool	validate_input(int argc, char **argv);
void	init_all(char **argv, t_env *env);

/*-----THREADS-----*/
void start_cycle(t_env *env);

/*-----UTILS-----*/
t_fork	*assign_forks(t_env *env, char side);
long	get_current_time(void);
int		ft_atoi(char *str);
int		is_valid_number(char *arg);

/*-----CLEAN-----*/
void	all_clean(t_env *env);


#endif