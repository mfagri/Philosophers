/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:02:32 by mfagri            #+#    #+#             */
/*   Updated: 2022/04/18 01:35:18 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(t_philo *philo)
{
	ft_printstatus(philo, "is sleeping", 1);
	ft_usleep(philo->data->tsleep);
}

void	ft_thinking(t_philo *philo)
{
	ft_printstatus(philo, "is thinking", 1);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->num - 1]);
	ft_printstatus(philo, "has taken a fork", 1);
	pthread_mutex_lock(&philo->data->forks[philo->num % philo->data->nbp]);
	ft_printstatus(philo, "has taken a fork", 1);
	ft_printstatus(philo, "is eating", 1);
	ft_usleep(philo->data->teat);
	philo->data->last_eat[philo->num - 1] = get_time();
	pthread_mutex_unlock(&philo->data->forks[philo->num - 1]);
	pthread_mutex_unlock(&philo->data->forks[philo->num % philo->data->nbp]);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		is_eat;

	is_eat = 0;
	philo = (t_philo *)arg;
	if (philo->num % 2)
		usleep(1000);
	while (1)
	{
		ft_eat(philo);
		is_eat += 1;
		if (philo->data->nfe != -1)
		{
			if (is_eat > philo->data->nfe)
			{
				philo->data->die = 2;
				break ;
			}
		}
		ft_sleep(philo);
		ft_thinking(philo);
	}
	return (NULL);
}

void	*ft_init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->currnt = get_time();
	pthread_mutex_init(&data->mutex, NULL);
	while (i < data->nbp)
	{
		data->last_eat[data->philos->num - 1] = get_time();
		pthread_create(&data->philos[i].ph, NULL, &routine, &data->philos[i]);
		i++;
	}
	check_death(data->philos);
	i = 0;
	while (i < data->nbp && !data->die)
	{
		pthread_join(data->philos[i].ph, NULL);
		i++;
	}
	return (NULL);
}
