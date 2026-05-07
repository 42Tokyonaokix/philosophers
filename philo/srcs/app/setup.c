/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:14:43 by natakaha          #+#    #+#             */
/*   Updated: 2026/05/07 09:55:18 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int	setup_system_mutex(t_system *system);
static int	free_system_mutex(t_system *system);

t_system	*setup_t_system(int *num)
{
	t_system	*system;

	system = ft_calloc(1, sizeof(t_system));
	if (!system)
		return (NULL);
	system->num_philos = num[0];
	system->time_to_die = num[1];
	system->time_to_eat = num[2];
	system->time_to_sleep = num[3];
	system->must_eat_count = num[4];
	system->ms_zero = get_ms();
	system->philos_state = SUCCESS;
	if (setup_system_mutex(system) == FAILURE)
		return (free(system), NULL);
	return (system);
}

t_philo	*setup_t_philo(t_system *system)
{
	t_philo	*philo;
	int		i;

	philo = ft_calloc(system->num_philos + 1, sizeof(t_philo));
	if (!philo)
		return (NULL);
	i = 0;
	while (i < system->num_philos)
	{
		(philo[i]).id = i + 1;
		(philo[i]).left_fork = &(system->forks[i]);
		(philo[i]).system = system;
		(philo[i]).state_mutex = &(system->state_mutex[i]);
		if (i != system->num_philos - 1)
			(philo[i]).right_fork = &(system->forks[i + 1]);
		else
			(philo[i]).right_fork = &(system->forks[0]);	
		i++;
	}
	return (philo);
}

static int	setup_system_mutex(t_system *system)
{
	system->forks = create_mutex(system->num_philos);
	if (!system->forks)
		return (free_system_mutex(system), FAILURE);
	system->print_mutex = create_mutex(1);
	if (!system->print_mutex)
		return (free_system_mutex(system), FAILURE);
	system->dead_mutex = create_mutex(1);
	if (!system->dead_mutex)
		return (free_system_mutex(system), FAILURE);
	system->state_mutex = create_mutex(system->num_philos);
	if (!system->state_mutex)
		return (free_system_mutex(system), FAILURE);
	return (SUCCESS);
}

static int	free_system_mutex(t_system *system)
{
	int	flag;

	flag = SUCCESS;
	if (system->forks)
		flag |= free_mutex(system->forks, system->num_philos);
	if (system->print_mutex)
		flag |= free_mutex(system->print_mutex, 1);
	if (system->dead_mutex)
		flag |= free_mutex(system->dead_mutex, 1);
	if (system->state_mutex)
		flag |= free_mutex(system->state_mutex, system->num_philos);
	return (flag);
}

int	execute_bit_value(int philos_state)
{
	if ((philos_state & FATAL) == FATAL)
		return (FATAL);
	if ((philos_state & FAILURE) == FAILURE)
		return (FAILURE);
	if ((philos_state & DEATH) == DEATH)
		return (FAILURE);
	if ((philos_state & FULL_OF_EAT) == FULL_OF_EAT)
		return (SUCCESS);
	return (FAILURE);
}

int	free_system(t_system *system)
{
	int	flag;

	flag = free_system_mutex(system);
	free(system);
	return (flag);
}
