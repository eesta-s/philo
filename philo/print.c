/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesta <eesta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 06:20:43 by eesta             #+#    #+#             */
/*   Updated: 2021/11/19 06:20:46 by eesta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, char *str)
{
	long long	time_in_ms;

	pthread_mutex_lock(&philo->data->print);
	time_in_ms = get_time_in_ms() - philo->data->t_launch;
	if (philo->data->status == alive)
		printf("%lld %d %s\n", time_in_ms, philo->id, str);
	pthread_mutex_unlock(&philo->data->print);
}

void	print_dead(t_philo *philo)
{
	long long	time_in_ms;

	pthread_mutex_lock(&philo->data->print);
	time_in_ms = get_time_in_ms() - philo->data->t_launch;
	if (philo->data->status == alive)
	{
		philo->data->status = dead;
		usleep(1000);
		printf("%lld %d died\n", time_in_ms, philo->id);
	}
	pthread_mutex_unlock(&philo->data->print);
}

int	create_threads(t_philo *philo)
{
	int			i;
	pthread_t	*th;

	i = -1;
	th = malloc(sizeof(pthread_t) * (philo->data->philo_num));
	while (++i < philo->data->philo_num)
		pthread_create(&th[i], NULL, routine, &philo[i]);
	i = 0;
	while (i < philo->data->philo_num)
		pthread_join(th[i++], NULL);
	free(th);
	free(philo->data->fork);
	free(philo->data->list);
	free(philo->data);
	free(philo);
	return (0);
}
