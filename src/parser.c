/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:52:26 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/24 22:02:12 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	init_environment(char **argv, t_env *env)
{
	env->philo_amount = ft_atoi(argv[1]);
	env->time_to_die = ft_atoi(argv[2]);
	env->time_to_eat = ft_atoi(argv[3]);
	env->time_to_sleep = ft_atoi(argv[4]);
	env->time_to_think = time_to_think(env);
	env->times_must_eat = -1;
	if (argv[5])
		env->times_must_eat = ft_atoi(argv[5]);
	env->start_time = get_absolute_time();
	env->end_cycle = false;
	pthread_mutex_init(&env->freeze_env, NULL);
	pthread_mutex_init(&env->freeze_to_print, NULL);
	pthread_mutex_init(&env->monitor_mtx, NULL);
}

static void	init_forks(t_env *env)
{
	int	i;

	i = 0;
	env->forks = malloc(sizeof(t_fork) * env->philo_amount);
	if (!env->forks)
		printf("Malloc fail\n");
	while (i < (env->philo_amount))
	{
		pthread_mutex_init(&env->forks[i].fork, NULL);
		env->forks[i].fork_id = i + 1;
		i++;
	}
}

static void	init_philos(t_env *env)
{
	int	i;
	int	philo_count;

	i = 0;
	philo_count = env->philo_amount;
	env->philos = malloc(sizeof(t_philo) * philo_count);
	if (!env->philos)
		printf("Malloc fail\n");
	while (i < philo_count)
	{
		env->philos[i].id = i + 1;
		env->philos[i].meals_count = 0;
		env->philos[i].is_full = false;
		env->philos[i].last_meal_time = env->start_time;
		env->philos[i].r_fork = &env->forks[i];
		env->philos[i].l_fork = &env->forks[(i + 1) % philo_count];
		env->philos[i].environment = env;
		i++;
	}
}

void	init_all(char **argv, t_env *env)
{
	if (!env)
		printf("ERROR: null pointer\n");
	init_environment(argv, env);
	init_forks(env);
	init_philos(env);
}

bool	check_args(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		printf(" error :(( expected 5 or 6 arguments.\n");
		return (false);
	}
	i = 1;
	while (argv[i] != NULL)
	{
		if (!is_valid_number(argv[i]) || ft_atoi(argv[i]) <= 0)
		{
			printf(" error :(( Invalid input '%s'.\n", argv[i]);
			return (0);
		}
		i++;
	}
	return (true);
}
