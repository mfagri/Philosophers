/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:02:32 by mfagri            #+#    #+#             */
/*   Updated: 2022/04/11 23:01:53 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
void	ft_sem(t_philo *philo)
{
	sem_unlink("sem");
	sem_unlink("print");
	philo->sem = sem_open("sem", O_CREAT, 0777, philo->data->nbp);
	philo->print = sem_open("print", O_CREAT, 0777, 1);
	if (philo->sem == SEM_FAILED || philo->print == SEM_FAILED)
		return (free(philo->ph), exit(0));
}
void	ft_sleep(t_philo *philo)
{
	ft_printstatus(philo, "sleeping", 1);
	ft_usleep(philo->data->tsleep);
}

void	ft_thinking(t_philo *philo)
{
	ft_printstatus(philo, "thinking", 1);
}

void	ft_eat(t_philo *philo)
{
	sem_wait(philo->sem);
	ft_printstatus(philo, "take fork", 1);
	sem_wait(philo->sem);
	ft_printstatus(philo, "take fork", 1);
	ft_printstatus(philo, "eating", 1);
	ft_usleep(philo->data->teat);
	philo->data->last_eat[philo->num - 1] = get_time();
	sem_post(philo->sem);
	sem_post(philo->sem);
}
void	*routine(void *arg)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	
	if (philo->num % 2)
		usleep(1000);
//	while (1)
//	{
		ft_eat(philo);
		philo->is_eat += 1;
		ft_sleep(philo);
		ft_thinking(philo);
	//}
	return (NULL);
}
void *ft_ll(t_philo *philo)
{
	philo->data->currnt = get_time();
	pthread_create(&philo->ph, NULL, &routine, &philo);
	//pthread_join(philo->ph, NULL);
	pthread_detach(philo->ph);
	while(1)
	{
		if (get_time() - philo->data->last_eat[philo->num - 1] \
		>= philo->data->tdie)
		{
			ft_printstatus(philo,"die",0);
			philo->data->die = 1;
			exit(1);
		}
		if (philo->data->nfe != -1)
		{
			if (philo->is_eat > philo->data->nfe)
			philo->data->die = 1;
			exit(0);
		}
	}
	exit(0);
}

int	*ft_init_philo(t_data *data)
{
	int	i;
	int *pids;
	int pid;

	ft_sem(data->philo);
	printf("---------------> %d\n",data->philo[0].num);
	pids= (int*)malloc(sizeof(int)*data->nbp);
	i = -1;
	while (++i < data->nbp)
	{
		//printf("{    %d    }\n",data->philo[i].num);
		pid = fork();
		if(pid == 0)
		{
			ft_ll(&data->philo[i]);
		}
		else
			pids[i] = pid;
		
	}
	return(pids);
}
