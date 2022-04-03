/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:22:53 by mfagri            #+#    #+#             */
/*   Updated: 2022/04/03 17:59:29 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int *check_death(t_philo *philo)
{
   // printf("{%lld}\n", philo->data->last_eat[philo->num-1]);
   // printf("phil nn %d\n",philo->num)
   while(1)
   {
    if(get_time() - philo->data->last_eat[philo->num-1] >= philo->data->tdie)
    {
      ft_printstatus(philo,"die",0);
      philo->data->die = 1;
      break ;
    }
   }
  return (0);
}

int main(int ac ,char **av)
{
  t_data data;
  
  check_args(ac,av);
  get_args(ac,av,&data);
  init_data(&data);
  ft_init_philo(&data);
  // check_death(data.philos);
}