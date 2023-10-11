/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:49:39 by amonier           #+#    #+#             */
/*   Updated: 2023/10/05 17:20:41 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_fork(long time, int id, pthread_mutex_t *print)
{
	pthread_mutex_lock(print);
	printf("%ld %d has taken a fork\n", time, id);
	pthread_mutex_unlock(print);
}

void	print_eating(long time, int id, pthread_mutex_t *print)
{
	pthread_mutex_lock(print);
	printf("%ld %d is eating\n", time, id);
	pthread_mutex_unlock(print);
}

void	print_sleeping(long time, int id, pthread_mutex_t *print)
{
	pthread_mutex_lock(print);
	printf("%ld %d is sleeping\n", time, id);
	pthread_mutex_unlock(print);
}

void	print_thinking(long time, int id, pthread_mutex_t *print)
{
	pthread_mutex_lock(print);
	printf("%ld %d is thinking\n", time, id);
	pthread_mutex_unlock(print);
}

void	print_died(long time, int id, pthread_mutex_t *print)
{
	pthread_mutex_lock(print);
	printf("%ld %d died (i:%d)\n", time, id, id);
	pthread_mutex_unlock(print);
}
