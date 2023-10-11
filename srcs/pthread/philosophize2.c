/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophize2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:51:18 by amonier           #+#    #+#             */
/*   Updated: 2023/10/05 18:06:37 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_tod	*init_tod(void)
{
	t_tod	*tod;

	tod = malloc(sizeof(t_tod) * 1);
	if (tod == NULL)
		return (NULL);
	tod->value = 0;
	gettimeofday(&(tod->start_time), NULL);
	pthread_mutex_init(&(tod->mutex), NULL);
	return (tod);
}

t_dead	*init_dead(void)
{
	t_dead	*dead;

	dead = malloc(sizeof(t_dead) * 1);
	if (dead == NULL)
		return (NULL);
	dead->dead = 0;
	pthread_mutex_init(&(dead->mutex), NULL);
	return (dead);
}

int	init_info(t_philo *philos, t_info *info, t_pars *init)
{
	info->forks = create_forks(init);
	if (info->forks == NULL)
	{
		free(init);
		free(info);
		free(philos);
		return (1);
	}
	info->tod = init_tod();
	if (info->tod == NULL)
	{
		destroy_forks(info->forks, init->nb_philo);
		free(init);
		free(philos);
		free(info);
		return (1);
	}
	return (0);
}

int	init_info2(t_philo *philos, t_info *info, t_pars *init)
{
	info->dead = init_dead();
	if (info->dead == NULL)
	{
		destroy_forks(info->forks, init->nb_philo);
		free(init);
		free(philos);
		pthread_mutex_destroy(&((info->tod)->mutex));
		free(info->tod);
		free(info);
		return (1);
	}
	info->philosophers = malloc(sizeof(pthread_t) * (init->nb_philo));
	if (info->philosophers == NULL)
	{
		destroy_forks(info->forks, init->nb_philo);
		free(init);
		free(philos);
		pthread_mutex_destroy(&((info->tod)->mutex));
		free(info->tod);
		pthread_mutex_destroy(&((info->dead)->mutex));
		free(info->dead);
		free(info);
		return (1);
	}
	return (0);
}

int	init_info3(t_philo *philos, t_info *info, t_pars *init)
{
	info->mut_eat = create_forks(init);
	if (info->mut_eat == NULL)
	{
		destroy_forks(info->forks, init->nb_philo);
		free(init);
		free(philos);
		pthread_mutex_destroy(&((info->tod)->mutex));
		free(info->tod);
		pthread_mutex_destroy(&((info->dead)->mutex));
		free(info->dead);
		free(info->philosophers);
		free(info);
		return (1);
	}
	return (0);
}
