/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:09:54 by mfagri            #+#    #+#             */
/*   Updated: 2022/04/12 00:21:27 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_error(void)
{
	write(2, "error\n", 7);
	exit (1);
}

void	check_args(int ac, char **av)
{
	int	i;

	if (ac - 1 == 5 || ac - 1 == 4)
	{
		i = 1;
		while (av[i] != NULL)
		{
			if (ft_atoi(av[i]) <= 0)
				ft_error();
			i++;
		}
	}
	else
		ft_error();
}

void	get_args(int ac, char **av, t_data *data)
{
	data->nbp = ft_atoi(av[1]);
	data->tdie = ft_atoi(av[2]);
	data->teat = ft_atoi(av[3]);
	data->tsleep = ft_atoi(av[4]);
	if (ac - 1 == 5)
		data->nfe = ft_atoi(av[5]);
	else
		data->nfe = -1;
	if (data->tdie < 60 || data->teat < 60 || \
	data->tsleep < 60 || data->nbp > 200)
		ft_error();
	return ;
}

void	init_data(t_data *data)
{
	int	i;

	i = 0;
	data->die = 0;
	data->full = 0;
}
