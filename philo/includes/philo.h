/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 09:44:45 by natakaha          #+#    #+#             */
/*   Updated: 2026/05/07 10:25:04 by natakaha         ###   ########.fr       */
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

# define USLEEP 50
# define SUCCESS 0
# define FAILURE 1
# define FATAL 2
# define DEATH 4
# define FULL_OF_EAT 8


typedef struct s_system {
 int num_philos;
 int time_to_die;
 int time_to_eat;
 int time_to_sleep;
 int must_eat_count;
 pthread_mutex_t *forks;
 pthread_mutex_t *print_mutex;
 pthread_mutex_t *dead_mutex;
 pthread_mutex_t *state_mutex;
 int philos_state;
 int ms_zero;
}	t_system;

typedef struct s_philo {
 int id;
 long last_meal_time;
 int meals_eaten;
 pthread_mutex_t *left_fork;
 pthread_mutex_t *right_fork;
 pthread_mutex_t *state_mutex;
 t_system *system;
} t_philo;

/* utils.libft-utils */
int				ft_putstr_fd(char *s, int fd);
size_t			ft_strlen(const char *s);
int				ft_atoi(const char *nptr);
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			ft_putnbr_fd(int n, int fd);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
/* utils.gettime */
long long		get_ms(void);
long long		get_time(long long ms_zero);
int				wait_time(long long ms_time, int us_wait);
int				wait_until_time(long long ms_zero, long long ms_finish, int us_wait);

/* utils.mutex */
int				free_mutex(pthread_mutex_t *mutex, int i);
pthread_mutex_t	*create_mutex(int n);

/* utils.pthread */
int				create_threads(int n, void *life_func(void *), void *monitor_func(void *), void *strct);

/* app.validation */
int				*validate_argument(int argc, char **argv);

/* app.setup */
t_system		*setup_t_system(int *num);
t_philo			*setup_t_philo(t_system *system);
int				free_system(t_system *system);
int				execute_bit_value(int philos_state);

/* app.mutex */
int				philo_mutex_do(t_philo *philo, pthread_mutex_t *mutex,
					int function(t_philo *, void *), void *arg);
int				philo_forks_do(t_philo *philo, pthread_mutex_t *first, pthread_mutex_t *next,
					int function(t_philo *));

/* print_base */
int				print_str(t_philo *philo, void *str);
int				are_philos_living(t_philo *philo, void *arg);

/* print_life */
int				print_fork(t_philo *philo);
int				print_eat(t_philo *philo);

/* domain.life */
void			*philo_life_manage(void *arg);
int				philo_eat(t_system *system, t_philo *philo);
int				philo_sleep(t_system *system, t_philo *philo);
int				philo_think(t_system *system, t_philo *philo);
void			*philo_monitor(void *arg);

/* app.main */
void			print_system(t_system *system);
void			print_philo(t_philo *philo);

#endif