/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheba <nsheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 06:35:58 by dalonso           #+#    #+#             */
/*   Updated: 2021/08/04 21:47:25 by nsheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	check_args(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	if (str[0] == '0' && (str[1]))
		return (0);
	return (1);
}

int	valid(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (check_args(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

unsigned long long	get_time(void)
{
	unsigned long long	mili_sec;
	struct timeval		current_time;

	gettimeofday(&current_time, NULL);
	mili_sec = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (mili_sec);
}

void	free_all(t_existance *existance, t_info *info)
{
	int	i;

	i = 0;
	if (existance)
	{
		while (i < info->N)
			pthread_mutex_destroy(&existance->forks[i++]);
		free(existance->forks);
		pthread_mutex_destroy(&existance->write);
	}
}
