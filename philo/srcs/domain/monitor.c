/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo0_life.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:14:43 by natakaha          #+#    #+#             */
/*   Updated: 2026/05/03 05:16:13 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int			philos_state_change(t_philo *philo, void *arg);
static int	monitoring_philos(t_philo *philo, t_system *system);
int			change_philo_status(t_philo *philo, void *arg);

void	*philo_monitor(void *arg)
{
	t_philo		*philo;
	t_system	*system;
	int			flag;

	philo = (t_philo *)arg;
	system = philo->system;
	while (true)
	{
		flag = monitoring_philos(philo, system);
		if (flag != SUCCESS)
		{
			flag = philo_mutex_do(philo, system->dead_mutex,
					philos_state_change, &flag);
			return (NULL);
		}
	}
}

static int	monitoring_philos(t_philo *philo, t_system *system)
{
	int	num_philos;
	int	i;
	int	flag;
	int	foe_flag;

	num_philos = system->num_philos;
	flag = SUCCESS;
	foe_flag = FULL_OF_EAT;
	i = 0;
	while (i < num_philos)
	{
		flag = philo_mutex_do(&philo[i], philo[i].state_mutex,
				change_philo_status, (void *)system);
		if (flag != SUCCESS && flag != FULL_OF_EAT)
			return (flag);
		foe_flag &= flag;
		i++;
	}
	return (foe_flag);
}

int	change_philo_status(t_philo *philo, void *arg)
{
	t_system	*system;
	int			ms_now;
	int			flag;

	system = (t_system *)arg;
	ms_now = get_time(system->ms_zero);
	if (ms_now > philo->last_meal_time + system->time_to_die)
	{
		flag = DEATH;
		philo_mutex_do(philo, system->dead_mutex, philos_state_change, &flag);
		philo_mutex_do(philo, system->print_mutex, print_str, (void *)"died");
		return (DEATH);
	}
	if (philo->meals_eaten >= system->must_eat_count
		&& system->must_eat_count >= 0)
		return (FULL_OF_EAT);
	return (SUCCESS);
}

int	philos_state_change(t_philo *philo, void *arg)
{
	int	flag;

	flag = *(int *)arg;
	philo->system->philos_state = flag;
	return (SUCCESS);
}
