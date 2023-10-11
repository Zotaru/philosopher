/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 02:40:52 by alex              #+#    #+#             */
/*   Updated: 2023/10/05 17:20:59 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	present_project(int argc)
{
	if (argc == 1)
	{
		printf("Welcome to the philosopher project.\n");
		printf("If you want to make run the project you");
		printf("need to enter 4 or 5 arguments\n");
		printf("1st argument: number of philospher\n");
		printf("2nd argument: time to die in ms\n");
		printf("3rd argument: time to eat in ms\n");
		printf("4th argument: time to sleep in ms\n");
		printf("5th argument: number of times each philo");
		printf("must eat (optionnal)\n");
		return (0);
	}
	return (1);
}
