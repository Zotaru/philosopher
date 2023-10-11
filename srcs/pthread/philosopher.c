/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 03:43:19 by alex              #+#    #+#             */
/*   Updated: 2023/10/05 19:23:05 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	end_eating(t_philo *philos, int id, struct timeval *time)
{
	gettimeofday(time, NULL);
	if (famine_to_death(philos) == 1)
	{
		pthread_mutex_unlock(philos->left_fork);
		pthread_mutex_unlock(philos->right_fork);
		return (1);
	}
	print_fork(time_in_ms(*time), id, philos->print);
	pthread_mutex_lock(philos->mut_eat);
	gettimeofday(&(philos->last_eat), NULL);
	print_eating(time_in_ms(*time), id, philos->print);
	philos->i_have_eat++;
	pthread_mutex_unlock(philos->mut_eat);
	u_sleep_perso((philos->tte), time_in_ms(*time), philos);
	pthread_mutex_unlock(philos->left_fork);
	pthread_mutex_unlock(philos->right_fork);
	return (0);
}

int	choose_fork_and_eating(t_philo *philos, int id)
{
	struct timeval	time;

	if (id == philos->nb_philo - 1)
		pthread_mutex_lock(philos->right_fork);
	else
		pthread_mutex_lock(philos->left_fork);
	gettimeofday(&time, NULL);
	if (famine_to_death(philos) == 1)
	{
		if (id == philos->nb_philo - 1)
			pthread_mutex_unlock(philos->right_fork);
		else
			pthread_mutex_unlock(philos->left_fork);
		return (1);
	}
	print_fork(time_in_ms(time), id, philos->print);
	if (id == philos->nb_philo - 1)
		pthread_mutex_lock(philos->left_fork);
	else
		pthread_mutex_lock(philos->right_fork);
	return (end_eating(philos, id, &time));
}

void	one_philo(t_philo *philos, struct timeval *time, int *id)
{
	gettimeofday(time, NULL);
	print_fork(time_in_ms(*time), *id, philos->print);
	usleep(philos->ttd * 1000);
	gettimeofday(time, NULL);
	print_died(time_in_ms(*time), *id, philos->print);
	pthread_exit(NULL);
}

void	philo_set_up(t_philo *philos, struct timeval *time, int *id)
{
	pthread_mutex_lock(philos->mut_eat);
	philos->last_eat = set_time_for_all(philos->tod);
	pthread_mutex_unlock(philos->mut_eat);
	if (*id % 2 != 0)
		usleep(2000);
	if (philos->nb_philo == 1)
		one_philo(philos, time, id);
}

void	*philosopher_thread(void *arg)
{
	t_philo			*philos;
	struct timeval	time;
	int				id;

	philos = (t_philo *)arg;
	id = philos->id;
	philo_set_up(philos, &time, &id);
	while (1)
	{
		if (choose_fork_and_eating(philos, id) == 1)
			break ;
		gettimeofday(&time, NULL);
		usleep(1000);
		if (famine_to_death(philos) == 1)
			break ;
		print_sleeping(time_in_ms(time), id, philos->print);
		u_sleep_perso((philos->tts), time_in_ms(time), philos);
		gettimeofday(&time, NULL);
		if (famine_to_death(philos) == 1)
			break ;
		print_thinking(time_in_ms(time), id, philos->print);
		usleep(1000);
	}
	pthread_exit(NULL);
}
