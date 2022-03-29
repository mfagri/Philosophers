/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:21:03 by mfagri            #+#    #+#             */
/*   Updated: 2022/03/29 19:09:51 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

typedef struct philo
{
    int is_eat;
    int is_die;
    int is_th;
    int num;
    pthread_t ph;
    
}t_philo;

typedef struct data
{
    int nbp;
    int tdie;
    int teat;
    int tsleep;
    int nfe;
    pthread_mutex_t		mutex;
    pthread_mutex_t *forks;
    t_philo *philos;
    
}t_data;



void check_args(int ac,char **av);
int	ft_atoi(const char *str);
void get_args(int ac, char **av,t_data *data);
void init_data(t_data *data);
void ft_init_philo(t_data *data);
#endif