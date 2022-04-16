/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:22:53 by mfagri            #+#    #+#             */
/*   Updated: 2022/04/16 23:13:54 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_death(t_philo *philo)
{
	while (1)
	{
		if (get_time() - philo->data->last_eat[philo->num - 1] \
		>= philo->data->tdie)
		{
			if (philo->data->die != 2)
				ft_printstatus(philo, "died", 0);
				philo->data->die = 1;
			break ;
		}
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_data	data;

	check_args(ac, av);
	get_args(ac, av, &data);
	init_data(&data);
	ft_init_philo(&data);
}
