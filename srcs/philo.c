/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 03:55:29 by alex              #+#    #+#             */
/*   Updated: 2023/10/05 17:33:49 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_pars	*init;
	int		err;

	init = pars(argv, argc);
	if (init == NULL)
		return (0);
	err = philosophize(init);
	return (err);
}
