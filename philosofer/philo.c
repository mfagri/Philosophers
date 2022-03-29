/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:22:53 by mfagri            #+#    #+#             */
/*   Updated: 2022/03/29 19:09:19 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac ,char **av)
{
  t_data data;
  
  check_args(ac,av);
  get_args(ac,av,&data);
  init_data(&data);
  int i = 0;
  while(i < data.nbp)
  {
    printf("%d\n",data.philos[i].num);
    i++;
  }
  ft_init_philo(&data);
}