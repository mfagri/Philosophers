/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:09:54 by mfagri            #+#    #+#             */
/*   Updated: 2022/04/18 04:49:39 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	data->philos = malloc(sizeof(t_philo) * data->nbp);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nbp);
	data->last_eat = malloc (sizeof(long long) * data->nbp);
	if (!data->philos || !data->forks)
		ft_error();
	while (i < data->nbp)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			ft_error();
		data->philos[i].num = i + 1;
		data->philos[i].data = data;
		data->die = 0;
		i++;
	}
	if (pthread_mutex_init(&data->ful, NULL))
		ft_error();
}
