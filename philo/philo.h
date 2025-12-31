/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 09:44:45 by natakaha          #+#    #+#             */
/*   Updated: 2025/12/28 20:47:44 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
#include <sys/time.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libft/ft_printf.h"

# define FAILUER -1
# define SUCCESS 1 

typedef struct	s_philos
{
	pthread_t		thread;
	int				tag;
	int				num;
	int				die;
	int				eat;
	int				slp;
	int				must;
	pthread_mutex_t	*left;	
	pthread_mutex_t	*right;	
}	t_philos;


/*philo_setup*/
void			collect_info(t_philos *node, char **argv);
t_philos		*setup_philos(int n, char **argv);
pthread_mutex_t	*setup_mutex(int n);
t_philos		*set_philo_fork(int n, char **argv);

/*philo_gettime*/
int	timer(void);

#endif