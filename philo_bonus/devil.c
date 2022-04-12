/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   devil.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:48:54 by mfagri            #+#    #+#             */
/*   Updated: 2022/04/12 00:57:47 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_sem(t_data *data)
{
	data->philo.sem = sem_open("sem", O_CREAT, 0777, data->nbp);
	data->philo.print = sem_open("print", O_CREAT, 0777, 1);
	if (data->philo.sem == SEM_FAILED || data->philo.print == SEM_FAILED)
	{
		printf ("sen failed\n");
		return (free(data->philo.ph), exit(0));
	}
}

void	ft_sleep(t_data *data)
{
	ft_printstatus(data, "sleeping", 1);
	ft_usleep(data->tsleep);
}

void	ft_thinking(t_data *data)
{
	ft_printstatus(data, "thinking", 1);
}

void	ft_eat(t_data *data)
{
	sem_wait(data->philo.sem);
	ft_printstatus(data, "take fork", 1);
	sem_wait(data->philo.sem);
	ft_printstatus(data, "take fork", 1);
	ft_printstatus(data, "eating", 1);
	ft_usleep(data->teat);
	data->last_eat = get_time();
	sem_post(data->philo.sem);
	sem_post(data->philo.sem);
}
void *routine(void *arg)
{
	t_data	*data;
	data = (t_data *)arg;

	// sleep(1);
	// printf ("%d\n", data->philo.num);
	// sleep(10);
	while (1)
	{
		ft_eat(data);
		data->philo.is_eat += 1;
		ft_sleep(data);
		ft_thinking(data);
	}
	return (NULL);
}

void ft_philo(t_data *data)
{
	pthread_t   ph;
	
	data->currnt = get_time();
	// printf ("%d\n", getpid());
	// printf ("%d\n", data->philo.num);
	// sleep (10);
	pthread_create(&ph, NULL, &routine, data);  
	pthread_join(ph, NULL);
	// while(1)
	// {
	// 	if (get_time() - philo->data->last_eat[philo->num - 1] \
	// 	>= philo->data->tdie)
	// 	{
	// 		ft_printstatus(philo,"die",0);
	// 		philo->data->die = 1;
	// 		exit(1);
	// 	}
	// 	if (philo->data->nfe != -1)
	// 	{
	// 		if (philo->is_eat > philo->data->nfe)
	// 		philo->data->die = 1;
	// 		exit(0);
	// 	}
	// } 
}

int *ft_start(t_data *data)
{
	int pid;
	int *pids;
	int i;

	i = -1;
	pids= (int*)malloc(sizeof(int)*data->nbp);
	ft_sem(data);
	while(++i < data->nbp)
	{
		pid = fork();
		if(pid == 0)
		{
			data->philo.num = i + 1;
			ft_philo(data);
			// usleep (100);
			break ;
		}
		else
			pids[i] = pid;
	}
	return (pids);
}