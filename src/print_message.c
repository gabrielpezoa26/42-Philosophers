/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:46:28 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/23 18:56:56 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	ft_print_char(int c)
{
	write(1, &c, 1);
}

static void	ft_print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_print_char(str[i]);
		i++;
	}
}

static void	ft_print_nbr(long n)
{
	if (n >= 10)
		ft_print_nbr(n / 10);
	ft_print_char((n % 10) + '0');
}

void	print_message(char *msg)
{
	long	timestamp;

	timestamp = get_time();
	ft_print_nbr(timestamp);
	ft_print_char(' ');
	ft_print_str(msg);
	ft_print_char('\n');
}
