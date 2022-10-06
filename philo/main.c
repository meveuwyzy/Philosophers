/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 06:08:31 by dalonso           #+#    #+#             */
/*   Updated: 2021/07/31 06:08:33 by dalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	main(int argc, char **argv)
{
	t_existance	existance;
	t_info		info;
	int			i;

	if (valid(argc, argv) == 0)
	{
		printf("wrong arguments\n");
		return (0);
	}
	if (parser(argv, &info, &existance) == 0)
	{
		printf("wrong arguments\n");
		return (0);
	}
	existance.forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* info.N);
	i = 0;
	while (i < info.N)
		pthread_mutex_init(&existance.forks[i++], NULL);
	pthread_mutex_init(&existance.write, NULL);
	start_sim(&existance, &info);
	return (0);
}
