/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 03:55:52 by alex              #+#    #+#             */
/*   Updated: 2023/10/05 19:10:02 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

typedef struct s_parsing
{
	int	nb_philo;
	int	ttd;
	int	tte;
	int	tts;
	int	opt_nb_of_eat;
}		t_pars;

typedef struct s_timeofday
{
	int				value;
	struct timeval	start_time;
	pthread_mutex_t	mutex;
}					t_tod;

typedef struct s_dead
{
	int				dead;
	pthread_mutex_t	mutex;
}					t_dead;

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				nb_philo;
	int				ttd;
	int				tte;
	int				tts;
	int				opt_nb_of_eat;
	t_tod			*tod;
	t_dead			*str_dead;
	struct timeval	last_eat;
	int				i_have_eat;
	pthread_mutex_t	*mut_eat;
	int				i_am_dead;
	pthread_mutex_t	*print;
}					t_philo;

typedef struct s_info
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	*mut_eat;
	pthread_t		*philosophers;
	int				i;
	t_tod			*tod;
	t_dead			*dead;
	pthread_mutex_t	*print;
}					t_info;

// ----> FORKS

pthread_mutex_t	*create_forks(t_pars *init);

// PARSING

t_pars			*pars(char **argv, int argc);
int				check_number(char *str);
int				present_project(int argc);

// THREAD

// ----> GENERAL FONCTION

int				philosophize(t_pars *init);

// for deatroy

void			destroy_forks(pthread_mutex_t *forks, int number);

// ----> PHILO THREAD

void			*philosopher_thread(void *arg);
long			time_in_ms(struct timeval time);
void			monitoring(t_philo *philos, t_pars *init);

// print

void			print_fork(long time, int id, pthread_mutex_t *print);
void			print_eating(long time, int id, pthread_mutex_t *print);
void			print_sleeping(long time, int id, pthread_mutex_t *print);
void			print_thinking(long time, int id, pthread_mutex_t *print);
void			print_died(long time, int id, pthread_mutex_t *print);

// norminette

t_tod			*init_tod(void);
t_dead			*init_dead(void);
int				init_info(t_philo *philos, t_info *info, t_pars *init);
int				init_info2(t_philo *philos, t_info *info, t_pars *init);
int				init_info3(t_philo *philos, t_info *info, t_pars *init);

// perso usleep et normi

void			u_sleep_perso(long time, long start, t_philo *philos);
int				famine_to_death(t_philo *philos);
long			time_in_ms(struct timeval time);
struct timeval	set_time_for_all(t_tod *tod);

#endif