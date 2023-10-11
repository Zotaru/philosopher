/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 03:45:03 by alex              #+#    #+#             */
/*   Updated: 2023/10/05 17:56:38 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_info4(t_philo *philos, t_info *info, t_pars *init)
{
	info->print = malloc(sizeof(pthread_mutex_t) * 1);
	if (info->print == NULL)
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

int	init_info5(t_philo *philos, t_info *info, t_pars *init)
{
	if (pthread_mutex_init(info->print, NULL) != 0)
	{
		destroy_forks(info->forks, init->nb_philo);
		free(init);
		free(philos);
		pthread_mutex_destroy(&((info->tod)->mutex));
		free(info->tod);
		pthread_mutex_destroy(&((info->dead)->mutex));
		free(info->dead);
		free(info->philosophers);
		free(info->print);
		free(info);
		return (1);
	}
	return (0);
}

void	free_all(t_philo *philos, t_info *info, t_pars *init)
{
	info->i = 0;
	while (info->i < init->nb_philo)
	{
		pthread_join((info->philosophers)[info->i], NULL);
		info->i++;
	}
	destroy_forks(info->forks, init->nb_philo);
	destroy_forks(info->mut_eat, init->nb_philo);
	free(init);
	free(philos);
	pthread_mutex_destroy(&((info->tod)->mutex));
	free(info->tod);
	pthread_mutex_destroy(&((info->dead)->mutex));
	free(info->dead);
	free(info->philosophers);
	pthread_mutex_destroy(info->print);
	free(info->print);
	free(info);
}

void	create_threads(t_philo *philos, t_info *info, t_pars *init)
{
	info->i = 0;
	pthread_mutex_lock(&((info->tod)->mutex));
	while (info->i < init->nb_philo)
	{
		philos[info->i].id = info->i;
		philos[info->i].left_fork = &((info->forks)[info->i]);
		philos[info->i].right_fork = &((info->forks)[(info->i + 1)
				% init->nb_philo]);
		philos[info->i].nb_philo = init->nb_philo;
		philos[info->i].ttd = init->ttd;
		philos[info->i].tte = init->tte;
		philos[info->i].tts = init->tts;
		philos[info->i].opt_nb_of_eat = init->opt_nb_of_eat;
		philos[info->i].tod = info->tod;
		philos[info->i].str_dead = info->dead;
		philos[info->i].i_am_dead = 0;
		philos[info->i].mut_eat = &((info->mut_eat)[info->i]);
		philos[info->i].i_have_eat = 0;
		philos[info->i].print = info->print;
		pthread_create(&((info->philosophers)[info->i]), NULL,
			philosopher_thread, &(philos[info->i]));
		info->i++;
	}
	pthread_mutex_unlock(&((info->tod)->mutex));
}

int	philosophize(t_pars *init)
{
	t_philo	*philos;
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (info == NULL)
		return (free(init), 1);
	philos = malloc(sizeof(t_philo) * (init->nb_philo));
	if (philos == NULL)
		return (free(init), free(info), 1);
	if (init_info(philos, info, init) == 1)
		return (1);
	if (init_info2(philos, info, init) == 1)
		return (1);
	if (init_info3(philos, info, init) == 1)
		return (1);
	if (init_info4(philos, info, init) == 1)
		return (1);
	if (init_info5(philos, info, init) == 1)
		return (1);
	create_threads(philos, info, init);
	if (init->nb_philo > 1)
		monitoring(philos, init);
	free_all(philos, info, init);
	return (0);
}
