/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 09:44:45 by natakaha          #+#    #+#             */
/*   Updated: 2026/01/07 00:21:16 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libft/ft_printf.h"

# define FAILUER -1
# define SUCCESS 1
# define EATING -2
# define CLEAR -3
# define DEATH -4

typedef struct s_philos
{
	pthread_t		thread;
	int				tag;
	int				num;
	int				die;
	int				eat;
	int				slp;
	int				must;
	int				eat_n;
	pthread_t		manager;
	int				death_time;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}	t_philos;

/*philo_setup*/
t_philos		*setup_philos(int n, char **argv);
pthread_mutex_t	*setup_mutex(int n);
t_philos		*set_philo_fork(int n, char **argv);
int				create_and_join(int n, t_philos *philo, void *(*f)(void *));

/*philo_gettime*/
int				timer(void);
int				waiting(int now, int time);
int				death_inform(int i);
void			*is_living(void *arg);


/*philo_alfg*/
void			*alg_manage(void *arg);
int				philos_eat(t_philos *philo,
					pthread_mutex_t *first,
					pthread_mutex_t *next);
int				philos_sleep(t_philos philo);
int				philos_think(t_philos philo);

/*philo_pthread*/
int				print_state(int time, int tag, char *str);
int				have_forks(t_philos philo,
					pthread_mutex_t *first,
					pthread_mutex_t *next);
int				philos_sleep_think(t_philos philo, int start);

/*philo_init*/
int				init_philo(t_philos *node, char **argv, int i);

#endif