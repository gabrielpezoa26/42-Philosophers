/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:52:26 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/14 00:30:25 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//                                            ./philo 3 100 100 100 [5]

int	validate_input(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		printf(" error :(( expected 5 or 6 arguments.\n");
		return (0);
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
	return (1);
}
