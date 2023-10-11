/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_and_die.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:31:13 by amonier           #+#    #+#             */
/*   Updated: 2023/10/05 18:32:44 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	time_in_ms(struct timeval time)
{
	long	result;

	result = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (result);
}

struct timeval	set_time_for_all(t_tod *tod)
{
	struct timeval	start;

	pthread_mutex_lock(&(tod->mutex));
	if (tod->value == 0)
	{
		gettimeofday(&(tod->start_time), NULL);
		start = tod->start_time;
		tod->value = 1;
	}
	else
	{
		start = tod->start_time;
	}
	pthread_mutex_unlock(&(tod->mutex));
	return (start);
}

int	famine_to_death(t_philo *philos)
{
	int	dead;

	pthread_mutex_lock(&((philos->str_dead)->mutex));
	dead = ((philos->str_dead)->dead);
	pthread_mutex_unlock(&((philos->str_dead)->mutex));
	if (dead == 1)
		return (1);
	else
		return (0);
}
