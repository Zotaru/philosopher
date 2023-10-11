/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_sleep_perso.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:06:58 by amonier           #+#    #+#             */
/*   Updated: 2023/10/05 19:25:47 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	timestamp(void)
{
	struct timeval	t;
	long			timeofday;

	gettimeofday(&t, NULL);
	timeofday = time_in_ms(t);
	return (timeofday);
}

void	u_sleep_perso(long time, long start, t_philo *philos)
{
	while (timestamp() - start < time)
	{
		if (famine_to_death(philos) == 1)
			break ;
		usleep(10);
	}
}
