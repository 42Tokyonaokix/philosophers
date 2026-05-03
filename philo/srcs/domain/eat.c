/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo1_eat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:14:43 by natakaha          #+#    #+#             */
/*   Updated: 2026/05/03 07:06:59 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int	philo_eating(t_philo *philo);
static int	philo_state_change(t_philo *philo, void *arg);

int	philo_eat(t_system *system, t_philo *philo)
{
	if (system->must_eat_count == 0)
		return (FULL_OF_EAT);
	if (philo->id % 2 == 0)
		return (philo_forks_do(philo, philo->left_fork, philo->right_fork,
			philo_eating));
	else
		return (philo_forks_do(philo, philo->right_fork, philo->left_fork,
			philo_eating));	
}

static int	philo_eating(t_philo *philo)
{
	int 		flag;
	int			ms_start;
	t_system	*system;

	system = philo->system;
	flag = SUCCESS;
	flag |= philo_mutex_do(philo, system->print_mutex,
		print_str, (void *)"is eating");
	if (flag == FATAL)
		return (FATAL);
	ms_start = get_time(system->ms_zero);
	flag |= philo_mutex_do(philo, philo->state_mutex,
		philo_state_change, (void *)(&ms_start));
	wait_until_time(system->ms_zero, ms_start + system->time_to_eat, USLEEP);
	return (flag);
}

static int	philo_state_change(t_philo *philo, void *arg)
{
	int	ms_start;

	ms_start = *(int *)arg;
	philo->last_meal_time = ms_start;
	philo->meals_eaten++;
	return (SUCCESS);
}
