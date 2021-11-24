/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesta <eesta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 06:21:43 by eesta             #+#    #+#             */
/*   Updated: 2021/11/19 06:21:45 by eesta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include <semaphore.h>
# include <signal.h>

typedef enum e_status
{
	alive,
	dead
}			t_status;

typedef struct s_data
{
	int			philo_num;
	int			t_die;
	int			t_eat;
	int			t_sleep;
	int			num_eat;
	sem_t		*fork;
	sem_t		*dead;
	sem_t		*print;
	sem_t		*sem_eaten;
	long long	t_launch;
	t_status	status;
}					t_data;

typedef struct s_philo
{
	int				id;
	pid_t			pid;
	t_data			*data;
	long long		t_last_meal;
	int				num_eaten;
}					t_philo;

int			main(int argc, char **argv);
void		free_all(t_philo *philo);
void		*all_have_eat(void *void_philo);
int			check_args(int argc, char **argv);
t_status	check_status(t_philo *philo);

void		*routine(void *void_philo);
void		*is_dead(void *void_philo);
void		taking_fork(t_philo *philo);
void		eating(t_philo *philo);

t_data		*init_data(int argc, char **argv);
t_philo		*init_philos(int argc, char **argv);

int			ft_atoi(const char *nptr);
long long	get_time_in_ms(void);
void		smart_sleep(long long time, t_philo *philo);
void		print_status(t_philo *philo, char *str);
void		print_dead(t_philo *philo);

#endif
