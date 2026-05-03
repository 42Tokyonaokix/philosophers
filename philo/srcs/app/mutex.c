/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:14:43 by natakaha          #+#    #+#             */
/*   Updated: 2026/05/03 10:41:29 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	pthread_forks_unlock(pthread_mutex_t *first, pthread_mutex_t *next);

int	philo_mutex_do(t_philo *philo, pthread_mutex_t *mutex,
		int function(t_philo *, void *), void *arg)
{
	int	flag;
	
	if (pthread_mutex_lock(mutex) != SUCCESS)
		return (FATAL);
	flag = function(philo, arg);
	if (pthread_mutex_unlock(mutex) != SUCCESS)
		return (FATAL);
	return (flag);
}

int	philo_forks_do(t_philo *philo, pthread_mutex_t *first, pthread_mutex_t *next,
		int function(t_philo *))
{
	int			flag;	
	t_system	*system;

	flag = SUCCESS;
	system = philo->system;
	if (pthread_mutex_lock(first) != SUCCESS)
		return (FATAL);
	flag |= philo_mutex_do(philo, system->print_mutex,
		print_str, (void *)"has taken a fork");
	if (flag == FATAL)
		return (pthread_mutex_unlock(first), FATAL);
	if (pthread_mutex_lock(next) != SUCCESS)
		return (pthread_mutex_unlock(first), FATAL);
	flag |= philo_mutex_do(philo, system->print_mutex,
		print_str, (void *)"has taken a fork");
	if (flag == FATAL)
		return (pthread_forks_unlock(first, next), FATAL);
	flag |= function(philo);
	pthread_forks_unlock(first, next);
	return (flag);
}

static void	pthread_forks_unlock(pthread_mutex_t *first, pthread_mutex_t *next)
{
	pthread_mutex_unlock(first);
	pthread_mutex_unlock(next);
}
