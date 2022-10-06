/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheba <nsheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 06:23:09 by dalonso           #+#    #+#             */
/*   Updated: 2021/08/04 21:52:52 by nsheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	start_sim(t_existance *existance, t_info *info)
{
	int			i;
	pthread_t	t_id;

	i = 0;
	existance->time = get_time();
	while (i < info->N)
	{
		existance->philosopher[i].last_time_eat = get_time();
		pthread_create(&t_id, NULL, &cycle, &existance->philosopher[i++]);
		usleep(100);
	}
	looking_for_dead(existance, info);
	return ;
}

void	looking_for_dead(t_existance *existance, t_info *info)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < info->N)
		{
			if ((get_time() >= ((unsigned long long)info->td
						+ existance->philosopher[i].last_time_eat))
				&& existance->philosopher[i].eat_flag == 0)
			{
				cat(existance, info, i);
				return ;
			}
			else if (existance->full_feds == info->N)
			{
				free_all(existance, info);
				return ;
			}
		}
		usleep(100);
	}
}

void	cat(t_existance *existance, t_info *info, int i)
{
	pthread_mutex_lock(&existance->philosopher[i].eat);
	existance->is_die = 1;
	status("died", &existance->philosopher[i]);
	pthread_mutex_unlock(&existance->philosopher[i++].eat);
	free_all(existance, info);
}

void	status(char *str, t_philosopher *philosopher)
{
	unsigned long long	time;

	pthread_mutex_lock(&philosopher->existance->write);
	time = get_time() - philosopher->existance->time;
	printf("%llu philosopher %d %s\n", time, philosopher->n, str);
	if (str[0] != 'd')
		pthread_mutex_unlock(&philosopher->existance->write);
}
