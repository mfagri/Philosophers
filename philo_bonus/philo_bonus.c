/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:12:46 by mfagri            #+#    #+#             */
/*   Updated: 2022/04/12 00:37:48 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <signal.h>
void	kill_p(t_data *data,int pid[])
{
	int i;
	
	i = 0;
	while (1)
	{
		if(data->die == 1 || data->die == 2)
		{
			while(i < data->nbp)
			{
				kill(pid[i],SIGKILL);
				i++;
			}
		}
	}
}
// void	*check_death(t_philo *philo)
// {
// 	while (1)
// 	{
// 		if (get_time() - philo->data->last_eat[philo->num - 1] \
// 		>= philo->data->tdie)
// 		{
// 			if (philo->data->die != 2)
// 				ft_printstatus(philo, "die", 0);
// 				philo->data->die = 1;
// 			break ;
// 		}
// 	}
// 	return (NULL);
// }
int main(int ac, char **av)
{  
	t_data data;
	int *pid;
	// int i;
	// i = 0;
	check_args(ac, av);
	get_args(ac, av, &data);
	init_data(&data);
	sem_unlink("sem");
	sem_unlink("print");
	pid = ft_start(&data);
	sleep (10000000);
	// kill_p(&data,pid);
}