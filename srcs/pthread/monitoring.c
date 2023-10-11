/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 00:08:50 by wfreulon          #+#    #+#             */
/*   Updated: 2023/10/06 16:01:51 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	enough_eat(t_philo *philos, int i)
{
	pthread_mutex_lock(&((philos[i - 1].str_dead)->mutex));
	((philos[i - 1].str_dead)->dead) = 1;
	pthread_mutex_unlock(&((philos[i - 1].str_dead)->mutex));
	usleep(1000);
}

void	one_dead(t_philo *philos, int i, long time)
{
	pthread_mutex_lock(&((philos[i].str_dead)->mutex));
	((philos[i].str_dead)->dead) = 1;
	pthread_mutex_unlock(&((philos[i].str_dead)->mutex));
	usleep(1000);
	print_died(time, i, philos[i].print);
	pthread_mutex_unlock(philos[i].mut_eat);
}

void	count_eat(int *least_eat, int *i, t_philo *philos, t_pars *init)
{
	if (init->opt_nb_of_eat != -1
		&& philos[*i].i_have_eat >= init->opt_nb_of_eat)
		(*least_eat)++;
	pthread_mutex_unlock(philos[*i].mut_eat);
	usleep(500);
	(*i)++;
}

void	monitoring(t_philo *philos, t_pars *init)
{
	int				i;
	struct timeval	time;
	int				least_eat;

	usleep(1000);
	while (1)
	{
		least_eat = 0;
		i = 0;
		while (i < init->nb_philo)
		{
			pthread_mutex_lock(philos[i].mut_eat);
			gettimeofday(&time, NULL);
			if (time_in_ms(time)
				- time_in_ms(philos[i].last_eat) >= philos[i].ttd)
				return (one_dead(philos, i, time_in_ms(time)));
			count_eat(&least_eat, &i, philos, init);
		}
		if (i == init->nb_philo && init->opt_nb_of_eat != -1
			&& least_eat == init->nb_philo)
			return (enough_eat(philos, i));
	}
}
