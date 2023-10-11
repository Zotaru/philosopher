/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 03:44:30 by alex              #+#    #+#             */
/*   Updated: 2023/10/05 17:33:49 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*create_forks(t_pars *init)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = malloc(sizeof(pthread_mutex_t) * (init->nb_philo));
	if (forks == NULL)
		return (NULL);
	i = 0;
	while (i < init->nb_philo)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			perror("Mutex init fail");
			destroy_forks(forks, i);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

void	destroy_forks(pthread_mutex_t *forks, int number)
{
	int	i;

	i = 0;
	while (i < number)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(forks);
}
