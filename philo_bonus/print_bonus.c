/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesta <eesta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 06:21:53 by eesta             #+#    #+#             */
/*   Updated: 2021/11/19 06:21:57 by eesta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_status(t_philo *philo, char *str)
{
	long long	time_in_ms;

	sem_wait(philo->data->print);
	time_in_ms = get_time_in_ms() - philo->data->t_launch;
	if (philo->data->status == alive)
		printf("%lld %d %s\n", time_in_ms, philo->id, str);
	sem_post(philo->data->print);
}

void	print_dead(t_philo *philo)
{
	long long	time_in_ms;

	sem_wait(philo->data->print);
	time_in_ms = get_time_in_ms() - philo->data->t_launch;
	printf("%lld %d died\n", time_in_ms, philo->id);
	sem_post(philo->data->dead);
}
