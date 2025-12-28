/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-23 09:44:45 by natakaha          #+#    #+#             */
/*   Updated: 2025-12-23 09:44:45 by natakaha         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include "libft/libft.h"

typedef struct	s_philos
{
	pthread_t			tag;
	struct s_phoilos	*next;
}	t_philos;


/*utils_philo*/
t_philos	*p_lstnew(pthread_t tag);
void		p_lstadd_back(t_philos **lst, t_philos *new);
void		p_lstclear(t_philos **lst);
t_philos	*p_create_(int	n);

#endif