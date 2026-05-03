/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo3_think.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:14:43 by natakaha          #+#    #+#             */
/*   Updated: 2026/05/03 06:12:25 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int	ms_thinking_time(t_system *system, t_philo *philo);
static int	ms_fix(int ms_time);

int	philo_think(t_system *system, t_philo *philo)
{
	int flag;
	int	ms_start;
	int	ms_think;

	flag = SUCCESS;
	ms_start = get_time(system->ms_zero);
	flag |= philo_mutex_do(philo, system->print_mutex,
		print_str, (void *)"is thinking");
	if (flag == FATAL)
		return (FATAL);
	ms_think = ms_thinking_time(system, philo);
	wait_until_time(system->ms_zero, ms_start + ms_think, USLEEP);
	return (flag)
}

static int	ms_thinking_time(t_system *system, t_philo *philo)
{
	int	num_groups;
	int	group_id;
	int eat_time;
	int	slp_time;

	eat_time = system->time_to_eat;
	slp_time = system->time_to_sleep;
	num_groups = (system->num_philos + 1) / 2;
	group_id = ((philo->id - 1) / 2 + 1) % num_groups;
	if (system->num_philos % 2 == 0)
		return (ms_fix(eat_time - slp_time));
	if (group_id == eat_time % num_groups)
		return (ms_fix(eat_time * 2 - slp_time));
	return (ms_fix(eat_time - slp_time));
}

static int	ms_fix(int ms_time)
{
	if (ms_time < 0)
		return (0);
	return (ms_time);
}