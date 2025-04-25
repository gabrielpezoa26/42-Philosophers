/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:22:33 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/24 21:47:28 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
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
	int				number_philos_full;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	int				times_must_eat;
	int				meals_count;
	long			start_time;
	bool			end_cycle;
	pthread_mutex_t	freeze_to_print;
	pthread_mutex_t	freeze_env;
	pthread_mutex_t	monitor_mtx;
	t_fork			*forks;
	t_philo			*philos;
	pthread_t		monitor;
};

/*-----PARSER-----*/
bool	check_args(int argc, char **argv);
void	init_all(char **argv, t_env *env);

/*-----THREADS-----*/
void	launch_cycle(t_env *env);

/*-----ACTIONS-----*/
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);

/*-----UTILS_THREADS-----*/
bool	is_philo_dead(t_env *env);
bool	is_philos_full(t_env *env);
void	handle_single_philo(t_philo *philo);
long	get_absolute_time(void);
long	get_time(t_env *env);

/*-----UTILS_PARSER-----*/
int		ft_atoi(char *str);
int		is_valid_number(char *arg);
int		time_to_think(t_env *env);

/*-----UTILS_ACTIONS-----*/
void	print_message(t_env *env, int id, char *msg);
int		take_forks(t_philo *philo);
void	drop_forks(t_philo *philo);
bool	sim_running(t_env *env);
bool	sim_stopped(t_env *env);

/*-----CLEAN-----*/
void	free_structs(t_env *env);


#endif