/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:52:26 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/19 20:18:26 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	init_environment(char **argv, t_env *env)
{
	env->philo_amount = ft_atoi(argv[1]);
	env->time_to_die = ft_atoi(argv[2]);
	env->time_to_eat = ft_atoi(argv[3]);
	env->time_to_sleep = ft_atoi(argv[4]);
	env->times_must_eat = 0;
	if (argv[5])
		env->times_must_eat = ft_atoi(argv[5]);
	env->start_time = get_current_time();
	env->end_cycle = false;
	// pthread_mutex_init(&env->freeze_env, NULL);
	// pthread_mutex_init(&env->freeze_env, NULL);
	printf("DEBUG: parsed Values: philo_amount: %d, time_to_die: %ld, "
		"time_to_eat: %ld, time_to_sleep: %ld\n", env->philo_amount, env->time_to_die, env->time_to_eat, env->time_to_sleep);
	if (argv[5]) //debug
		printf("DEBUG:  times_must_eat: %d\n", env->times_must_eat);
	printf("DEBUG: saiu init_env\n");
}

static void	init_forks(t_env *env)
{
	int	i;

	i = 0;
	env->forks = malloc(sizeof(t_fork) * env->philo_amount);
	if (!env->forks)
		write(1, "Malloc fail", 11);
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

	i = 0;
	env->philos = malloc(sizeof(t_philo) * env->philo_amount);
	if (!env->philos)
		write(1, "Malloc fail", 11);
	while (i < (env->philo_amount))
	{
		env->philos[i].id = i + 1;
		env->philos[i].meals_count = 0;
		env->philos[i].is_full = false;
		env->philos[i].last_meal_time = env->start_time;
		env->philos[i].r_fork = assign_forks(env, 'r');
		env->philos[i].l_fork = assign_forks(env, 'l');
		env->philos[i].environment = env;
		i++;
	}
}

void	init_all(char **argv, t_env *env)
{
	if (!env)
		printf("DEBUG: visshhhh\n");
	init_environment(argv, env);
	printf("DEBUG: saiu init_env, vai chamar init forks\n");
	init_forks(env);
	printf("DEBUG: saiu init_forks, vai chamar init_philos\n");
	init_philos(env);
	printf("DEBUG: saiu init_forks, vai chamar init_philos\n");
	printf("DEBUG: boaaaaaa terminou init_all\n");
}

bool	validate_input(int argc, char **argv)
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
			printf(" error: Invalid input '%s'.\n", argv[i]);
			return (0);
		}
		i++;
	}
	return (true);
}
