/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:02:32 by mfagri            #+#    #+#             */
/*   Updated: 2022/03/31 22:06:14 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_printstatus(t_philo *philo,char *s,int b)
{
	pthread_mutex_lock(&philo->data->mutex);
	if(s)
		printf("%lld philo number %d %s\n", get_time()-philo->data->currnt,philo->num,s);
	if(b)
		pthread_mutex_unlock(&philo->data->mutex);
}
void  ft_usleep(int time)
{
	// long long curr;
	
	// curr = get_time();
	// usleep((time - (time * 0.03)) * 1000);
	// while ((get_time() - curr) < time)
	// 	usleep(1);
	long long	t;

	t = get_time();
	while (get_time() - t < time)
		usleep(1);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000 ) + (time.tv_usec / 1000));
}
void ft_sleep(t_philo * philo)
{
	// pthread_mutex_lock(&philo->data->mutex);
	// pthread_mutex_unlock(&philo->data->mutex);
	//printf("%lld philo number %d sleep \n",get_time() - philo->data->currnt,philo->num);
	ft_printstatus(philo,"sleeping",1);
	//printf("%lld philo number %d is thinking\n",philo->data->last_eat[philo->num - 1],philo->num);
	ft_usleep(philo->data->tsleep);
}
void ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->num - 1]);
	ft_printstatus(philo,"take frok",1);
	pthread_mutex_lock(&philo->data->forks[philo->num % philo->data->nbp]);
	ft_printstatus(philo,"take frok",1);
	philo->data->last_eat[philo->num-1] = get_time() - philo->data->currnt;
	ft_printstatus(philo,"eating",1);
	ft_usleep(philo->data->teat);
	pthread_mutex_unlock(&philo->data->forks[philo->num - 1]);
	pthread_mutex_unlock(&philo->data->forks[philo->num % philo->data->nbp]);
}
void ft_thinking(t_philo *philo)
{
	ft_printstatus(philo,"thinking",1);
}
void	*routine(void * arg)
{
  t_philo *philo;
  philo = (t_philo *)arg;
  if (philo->num % 2)
	usleep(1000);
  while(1)
  {
	  ft_eat(philo);
	  ft_sleep(philo);
	  ft_thinking(philo);
  }
  return(0);
}

void ft_init_philo(t_data *data)
{
	int i;
	
	//printf("%lld--\n",(time.tv_sec /1000) + (time.tv_usec * 1000) - data->currnt);
	i = 0;
	data->currnt = get_time();
	pthread_mutex_init(&data->mutex,NULL);
	while(i < data->nbp)
	{
		pthread_create(&data->philos[i].ph,NULL,&routine,&data->philos[i]);
		i++;
	}
	i = 0;
	while(i < data->nbp)
	{
		pthread_join(data->philos[i].ph,NULL);
		i++;
	}
}