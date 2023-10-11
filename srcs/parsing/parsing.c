/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 04:06:57 by alex              #+#    #+#             */
/*   Updated: 2023/10/05 17:33:49 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_atoi_long_long(char *str)
{
	long long	res;
	long long	i;

	i = 0;
	res = 0;
	while (str[i])
	{
		res = 10 * res + str[i] - '0';
		i++;
	}
	return (res);
}

int	check_number(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			printf("%s is not a number\n", str);
			return (0);
		}
	}
	if (i >= 11)
	{
		printf("%s : argument to big\n", str);
		return (0);
	}
	if (ft_atoi_long_long(str) > INT_MAX)
	{
		printf("%s : argument to big\n", str);
		return (0);
	}
	return (1);
}

t_pars	*wrong_number_arg(int argc)
{
	if (argc < 5)
		printf("Not enough arguments\n");
	if (argc > 6)
		printf("Too many arguments\n");
	return (NULL);
}

void	fill_init(char **argv, int argc, t_pars *init)
{
	init->nb_philo = ft_atoi_long_long(argv[1]);
	init->ttd = ft_atoi_long_long(argv[2]);
	init->tte = ft_atoi_long_long(argv[3]);
	init->tts = ft_atoi_long_long(argv[4]);
	init->opt_nb_of_eat = -1;
	if (argc == 6)
		init->opt_nb_of_eat = ft_atoi_long_long(argv[5]);
	return ;
}

t_pars	*pars(char **argv, int argc)
{
	int		i;
	t_pars	*init;

	if (present_project(argc) == 0)
		return (NULL);
	if (argc < 5 || argc > 6)
		return (wrong_number_arg(argc));
	i = 1;
	while (i < argc)
	{
		if (check_number(argv[i]) == 0)
			return (NULL);
		i++;
	}
	init = malloc(sizeof(t_pars) * 1);
	if (init == NULL)
		return (NULL);
	fill_init(argv, argc, init);
	return (init);
}
