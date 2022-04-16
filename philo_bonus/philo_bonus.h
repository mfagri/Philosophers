/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:13:30 by mfagri            #+#    #+#             */
/*   Updated: 2022/04/16 01:55:52 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <signal.h>
# include <semaphore.h>

typedef struct philo
{
	sem_t			*sem;
	sem_t			*print;
	int				is_eat;
	int				is_die;
	struct s_data	*data;
	long long		last_eat;
	int				num;
	pthread_t		ph;
}t_philo;

typedef struct s_data
{
	t_philo			*philo;
	int				nbp;
	int				tdie;
	int				teat;
	int				tsleep;
	int				nfe;
	int				full;
	long long		currnt;
	int				die;
}t_data;

long long	get_time(void);
void		check_args(int ac, char **av);
void		*routine(void *arg);
void		ft_printstatus(t_philo *philo, char *s, int b);
void		get_args(int ac, char **av, t_data *data);
void		init_data(t_data *data);
int			*ft_init_philo(t_data *data);
void		ft_usleep(int time);
int			ft_atoi(const char *str);
void		*check_death(t_data *data);
int			*ft_start(t_data *data);
void		*ft_ll(t_philo *philo);

#endif
