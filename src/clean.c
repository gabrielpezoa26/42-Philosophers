/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:39:57 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/24 00:28:55 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_structs(t_env *env)
{
	if (env->philos)
		free(env->philos);
	if (env->forks)
		free(env->forks);
	printf("DEBUG: freeeeeee\n");
}
