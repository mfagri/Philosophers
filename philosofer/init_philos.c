/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:02:32 by mfagri            #+#    #+#             */
/*   Updated: 2022/03/29 20:47:38 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	printf_philo_status(t_data *data, char *s, int lamp)
// {
// 	pthread_mutex_lock(&data->mutex);
// 	if (s)
// 		printf("%lld philo %d %s\n", (get_time() - philo->data->time) \
// 			, philo->index, s);
// 	if (lamp)
// 		pthread_mutex_unlock(&philo->data->mutex);
    
void *routine(void * arg)
{
  t_data *data;
  data = (t_data *)arg;
  //pthread_mutex_lock(&data->forks[data->philos->num]);
  printf("hello philo\n");
  //pthread_mutex_unlock(&data->forks[data->philos->num]);
  return(0);
}

void ft_init_philo(t_data *data)
{
    int i;
    i = 0;
    while(i < data->nbp)
    {
        pthread_create(&data->philos[i].ph,NULL,&routine,(void *)data);
        i++;
    }
    i = 0;
    while(i < data->nbp)
    {
        pthread_join(data->philos[i].ph,NULL);
        i++;
    }
}