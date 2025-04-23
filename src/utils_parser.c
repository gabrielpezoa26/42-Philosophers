/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:46:28 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/23 00:17:29 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// void	assign_forks(t_philo *philo)
// {
// 	if (philo->id % 2 == 0)
// 	{
// 		pthread_mutex_lock(&philo->r_fork->fork);
// 		pthread_mutex_lock(&philo->l_fork->fork);
// 	}
// 	else
// 	{
// 		pthread_mutex_lock(&philo->l_fork->fork);
// 		pthread_mutex_lock(&philo->r_fork->fork);
// 	}
// }

t_fork	*assign_forks(t_env *env, char side)
{
	int	id;

	id = 0;
	if (side == 'r')
		id = env->philos->id;
	if (side == 'l')
		id = env->philos->id % env->philo_amount;
	return (&env->forks[id]);
}

long	get_current_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

static int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	number;
	int	sign;

	i = 0;
	number = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number * sign);
}

int	is_valid_number(char *arg)
{
	int	i;

	i = 0;
	if (!arg || !arg[0])
		return (0);
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}
