/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:49:56 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/04/24 21:47:35 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	sim_stopped(t_env *env)
{
	bool	end;

	pthread_mutex_lock(&env->monitor_mtx);
	end = env->end_cycle;
	pthread_mutex_unlock(&env->monitor_mtx);
	return (end);
}

int	main(int argc, char **argv)
{
	t_env	env;

	if (!check_args(argc, argv))
		return (1);
	init_all(argv, &env);
	launch_cycle(&env);
	free_structs(&env);
	return (0);
}
