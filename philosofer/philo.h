/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:21:03 by mfagri            #+#    #+#             */
/*   Updated: 2022/03/31 17:19:04 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct philo
{
	int is_eat;
	int is_die;
	int num;
	pthread_t ph;
	struct s_data *data;
}t_philo;

typedef struct s_data
{
	int nbp;
	int tdie;
	int teat;
	int tsleep;
	int nfe;
	long long	currnt;
	long long	*last_eat;
	pthread_mutex_t		mutex;
	pthread_mutex_t *forks;
	t_philo *philos;
	
}t_data;



void check_args(int ac,char **av);
int	ft_atoi(const char *str);
void get_args(int ac, char **av,t_data *data);
void init_data(t_data *data);
void ft_init_philo(t_data *data);
long long	get_time(void);
#endif