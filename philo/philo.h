/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 09:44:45 by natakaha          #+#    #+#             */
/*   Updated: 2026/01/31 15:35:54 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>
# include <string.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

# define FAILUER -1
# define SUCCESS 1
# define CLOSE 0
# define CLEAR -3
# define DEATH -4

typedef struct s_philos
{
	int				tag;
	int				num;
	int				die;
	int				eat;
	int				slp;
	int				must;
	int				group;
	int				eat_n;
	int				death_time;
	pthread_t		thread;
	pthread_t		manager;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}					t_philos;

/* philo_setup */
t_philos			*setup_philos(int n, char **argv);
pthread_mutex_t		*setup_mutex(int n);
t_philos			*set_philo_fork(int n, char **argv, pthread_mutex_t *forks);
int					init_philo(t_philos *node, char **argv, int i);

/* philo_gettime */
pthread_mutex_t		*microphone(void);
int					timer(void);
int					waiting(int now, int time);
int					death_inform(int i);
pthread_mutex_t		*scythe(void);

/* philo_life */
void				*life_manage(void *arg);
int					philos_think(t_philos philo);

/* philo_pthread */
int					print_state(int tag, char *str);
int					philos_sleep_think(t_philos philo, int start);
int					count_eating(t_philos philo, int flag);

/* pihlo_utils.c */
int					ft_strncmp(const char *s1, const char *s2, size_t len);
void				ft_putendl_fd(char *s, int fd);
size_t				ft_strlen(const char *s);
int					ft_atoi(const char *nptr);
void				*ft_calloc(size_t nmemb, size_t size);

/* life_utils.c */
int					have_forks(t_philos philo, pthread_mutex_t *first,
						pthread_mutex_t *next);
void				*is_living(void *arg);
int					think_alg(t_philos philo);
int					first_think(t_philos philo);

/* main.c */
int					create_and_join(int n, t_philos *philo,
						pthread_mutex_t *forks);

#endif