/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesta <eesta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 06:20:53 by eesta             #+#    #+#             */
/*   Updated: 2021/11/19 06:20:55 by eesta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	long	num;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	num = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		nptr++;
	if (nptr[i] == '-')
		sign = sign * -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		nptr++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = (num * 10) + nptr[i] - '0';
		nptr++;
		if (num * sign > 2147483647)
			return (-1);
		if (num * sign < -2147483648)
			return (0);
	}
	return (num * sign);
}

long long	get_time_in_ms(void)
{
	struct timeval	tv;
	long long		time_in_ms;

	gettimeofday(&tv, NULL);
	time_in_ms = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	return (time_in_ms);
}

void	smart_sleep(long long time, t_philo *philo)
{
	long long	time_in_ms;

	time_in_ms = get_time_in_ms();
	check_status(philo);
	while (philo->data->status == alive)
	{
		if (get_time_in_ms() - time_in_ms > philo->data->t_die - 1)
			print_dead(philo);
		if (get_time_in_ms() - time_in_ms >= time)
			break ;
		usleep(50);
	}
}

void	update_list(t_data *data, int philo_id)
{
	int	i;

	i = 0;
	while (i < data->philo_num - 1)
	{
		data->list[i] = data->list[i + 1];
		i++;
	}
	data->list[i] = philo_id;
}
