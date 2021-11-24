/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesta <eesta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 06:19:49 by eesta             #+#    #+#             */
/*   Updated: 2021/11/19 06:20:13 by eesta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_status	check_status(t_philo *philo)
{
	long long	time_in_ms;

	time_in_ms = get_time_in_ms();
	if (philo->t_last_meal == 0)
		philo->t_last_meal = get_time_in_ms() - 1;
	if (philo->data->status == dead)
		return (dead);
	if (time_in_ms - philo->t_last_meal > philo->data->t_die)
	{
		print_dead(philo);
		return (dead);
	}
	return (alive);
}

int	check_args(int argc, char **argv)
{
	if (argc > 4 && argc <= 6)
	{
		if (ft_atoi(argv[1]) < 1)
			return (printf("There must be at least 1 philosopher.\n"));
		if (ft_atoi(argv[2]) < 1)
			return (printf("Time_to_die must be at least 1.\n"));
		if (ft_atoi(argv[3]) < 1)
			return (printf("Time_to_eat must be at least 1.\n"));
		if (ft_atoi(argv[4]) < 1)
			return (printf("Time_to_sleep must be at least 1.\n"));
		if (argc == 6 && ft_atoi(argv[5]) < 1)
			return (printf("Number_of_times_each_philosopher_must_eat must be \
at least 1.\n"));
	}
	else
		return (printf("ARGS NEEDED :	[number_of_philosophers] [time_to_die] \
[time_to_eat] [time_to_sleep]\nOPTIONAL :	\
[number_of_times_each_philosopher_must_eat]\n"));
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (check_args(argc, argv) != 0)
		return (1);
	philo = init_philos(argc, argv);
	create_threads(philo);
}
