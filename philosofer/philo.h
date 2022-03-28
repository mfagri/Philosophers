/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:21:03 by mfagri            #+#    #+#             */
/*   Updated: 2022/03/28 19:24:16 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

typedef struct data
{
    int nbp;
    int tdie;
    int teat;
    int tsleep;
    int nfe;
    int *philos;
    
}t_data;

void check_args(int ac,char **av);
int	ft_atoi(const char *str);

#endif