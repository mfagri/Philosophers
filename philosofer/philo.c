/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:22:53 by mfagri            #+#    #+#             */
/*   Updated: 2022/03/28 19:49:39 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_error(void)
{
  write(2,"error\n",7);
  exit (1);
}
void check_args(int ac,char **av)
{
  int i;
  
  if(ac-1 == 5 || ac-1 == 4)
  {
    i = 1;
    while(av[i] != NULL)
    {
      if(ft_atoi(av[i]) <= 0)
        ft_error();
      i++;
    }
  }
  else
    ft_error();
}

void get_args(int ac, char **av,t_data *data)
{
  data->nbp = ft_atoi(av[1]);
  data->tdie = ft_atoi(av[2]);
  data->teat = ft_atoi(av[3]);
  data->tsleep = ft_atoi(av[4]);
  if(ac - 1 == 5)
    data->nfe = ft_atoi(av[5]);
  else
    data->nfe = -1;
  if(data->tdie < 60 || data->teat < 60 || data->tsleep < 60 || data->nbp > 200)
    ft_error();
  return;
}
int main(int ac ,char **av)
{
  t_data data;
  check_args(ac,av);
  get_args(ac,av,&data);
  printf("%d\n",data.nbp);
  printf("%d\n",data.nfe);
  printf("%d\n",data.tdie);
  printf("%d\n",data.tsleep);
  printf("%d\n",data.teat);
}