/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:43:53 by mfagri            #+#    #+#             */
/*   Updated: 2022/04/12 00:31:10 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_printstatus(t_data *data, char *s, int b)
{
	if (s)
	{
		sem_wait(data->philo.print);
		printf("%lld %d %s\n", get_time() - data->currnt, data->philo.num, s);
	}
	if (b)
		sem_post(data->philo.print);
}

void	ft_usleep(int time)
{
	long long	t;

	t = get_time();
	while (get_time() - t < time)
		usleep(1);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_atoi(const char *str)
{
	int				i;
	int				n;
	long int		res;

	i = 0;
	res = 0;
	n = 1;
	while (str[i] == '\n' || str[i] == '\r' || str[i] == '\t'
		||str[i] == '\f' || str[i] == '\v' || str[i] == ' ' )
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -n;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * n);
}
