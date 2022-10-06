/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 21:10:31 by dalonso           #+#    #+#             */
/*   Updated: 2021/08/04 21:10:35 by dalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_info
{
	int					N;
	int					td;
	int					te;
	int					ts;
	int					nm;
}				t_info;

typedef struct s_existance
{
	int					full_feds;
	pthread_mutex_t		write;
	struct s_philosoper	*philosopher;
	pthread_mutex_t		*forks;
	unsigned long long	time;
	int					is_die;
}				t_existance;

typedef struct s_philosoper
{
	int					n;
	int					lfork;
	int					rfork;
	unsigned long long	last_time_eat;
	int					meals_count;
	int					eat_flag;
	pthread_mutex_t		eat;
	struct s_existance	*existance;
	struct s_info		*info;
}				t_philosopher;

int					parser(char **argv, t_info *info, t_existance *threads);
unsigned long long	get_time(void);
void				start_sim(t_existance *existance, t_info *info);
void				phsleep(t_philosopher *bro, t_info *inf);
void				eat(t_philosopher *bro, t_info *inf);
void				free_all(t_existance *existance, t_info *info);
void				status(char *str, t_philosopher *philosopher);
void				looking_for_dead(t_existance *existance, t_info *info);
t_philosopher		*linkage_structs(t_existance *existance, t_info *info);
int					check_args(char *str);
int					ft_atoi(const char *str);
void				*cycle(void *philosopher);
int					valid(int argc, char **argv);
void				cat(t_existance *existance, t_info *info, int i);

#endif
