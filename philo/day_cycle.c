/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day_cycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheba <nsheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 06:19:42 by dalonso           #+#    #+#             */
/*   Updated: 2021/08/04 21:37:57 by nsheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*cycle(void *philosopher)
{
	t_philosopher	*bro;
	t_info			*inf;

	bro = (t_philosopher *)philosopher;
	inf = (t_info *)bro->info;
	while (1)
	{
		if (bro->existance->is_die == 0)
			status("is thinking", bro);
		eat(bro, inf);
		phsleep(bro, inf);
		usleep(100);
	}
}

void	eat(t_philosopher *bro, t_info *inf)
{
	pthread_mutex_lock(&bro->existance->forks[bro->lfork]);
	status("taking lfork", bro);
	if (inf->N == 1)
	{
		while (1)
			usleep(100);
	}
	pthread_mutex_lock(&bro->existance->forks[bro->rfork]);
	status("taking rfork", bro);
	pthread_mutex_lock(&bro->eat);
	status("start eating", bro);
	bro->last_time_eat = get_time();
	bro->eat_flag = 1;
	bro->meals_count = bro->meals_count + 1;
	if (bro->meals_count == inf->nm)
		bro->existance->full_feds++;
	while ((get_time() - bro->last_time_eat)
		< (unsigned long long)inf->te)
		usleep(100);
	pthread_mutex_unlock(&bro->eat);
	bro->eat_flag = 0;
}

void	phsleep(t_philosopher *bro, t_info *inf)
{
	unsigned long long	time;

	pthread_mutex_unlock(&bro->existance->forks[bro->lfork]);
	pthread_mutex_unlock(&bro->existance->forks[bro->rfork]);
	if (bro->existance->is_die == 0)
		status("is sleeping", bro);
	time = get_time();
	while ((get_time() - time) < (unsigned long long)inf->ts)
		usleep(100);
}
