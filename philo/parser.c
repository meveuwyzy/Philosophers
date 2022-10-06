/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 06:08:20 by dalonso           #+#    #+#             */
/*   Updated: 2021/08/04 21:54:38 by dalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	parser(char **argv, t_info *info, t_existance *existance)
{
	info->N = ft_atoi(argv[1]);
	if (info->N == 0)
		return (0);
	existance->full_feds = 0;
	info->td = ft_atoi(argv[2]);
	info->ts = ft_atoi(argv[4]);
	info->te = ft_atoi(argv[3]);
	info->nm = 0;
	if (argv[5])
		info->nm = ft_atoi(argv[5]);
	existance->philosopher = linkage_structs(existance, info);
	return (1);
}

t_philosopher	*linkage_structs(t_existance *existance, t_info *info)
{
	t_philosopher	*philosopher;
	int				i;

	i = 0;
	philosopher = malloc(sizeof(t_philosopher) * info->N);
	while (i < info->N)
	{
		philosopher[i].n = i + 1;
		philosopher[i].meals_count = 0;
		pthread_mutex_init(&philosopher[i].eat, NULL);
		philosopher[i].eat_flag = 0;
		philosopher[i].rfork = i + 1;
		philosopher[i].lfork = i;
		if (i == 0)
			philosopher[i].lfork = info->N;
		philosopher[i].existance = existance;
		philosopher[i].info = info;
		i++;
	}
	existance->is_die = 0;
	return (philosopher);
}

int	ft_atoi(const char *str)
{
	unsigned long long int	x;

	x = 0;
	while (*str)
	{
		x = x * 10 + *str - '0';
		str++;
	}
	return (x);
}
