/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:02:32 by mfagri            #+#    #+#             */
/*   Updated: 2022/04/18 01:45:06 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	sem_wait(philo->sem);
	ft_printstatus(philo, "has taken a fork", 1);
	philo->last_eat = get_time() - philo->data->currnt;
	sem_wait(philo->sem);
	ft_printstatus(philo, "has taken a fork", 1);
	ft_printstatus(philo, "is eating", 1);
	philo->last_eat = get_time() - philo->data->currnt;
	ft_usleep(philo->data->teat);
	sem_post(philo->sem);
	sem_post(philo->sem);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!(philo->num % 2))
		usleep(1000);
	while (1)
	{
		ft_eat(philo);
		philo->is_eat += 1;
		ft_sleep(philo);
		ft_thinking(philo);
	}
	return (NULL);
}

void	ft_ll(t_philo *philo)
{
	philo->sem = sem_open("sem", O_CREAT, 0660, philo->data->nbp);
	philo->print = sem_open("print", O_CREAT, 0660, 1);
	if (philo->sem == SEM_FAILED || philo->print == SEM_FAILED)
		return (free(philo->ph), exit(0));
	pthread_create(&philo->ph, NULL, routine, philo);
	pthread_detach(philo->ph);
	while (1)
	{
		if (get_time() - philo->last_eat - philo->data->currnt \
		>= philo->data->tdie)
		{
			ft_printstatus(philo, "died", 0);
			exit(1);
		}
		if (philo->data->nfe != -1)
			if (philo->is_eat > philo->data->nfe)
				exit(0);
		usleep(50);
	}
	return ;
}
