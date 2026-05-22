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
static int	get_meals_eaten(t_philo *philo, void *meals_eaten);
static int	first_think(t_system system, t_philo philo);
static int	think_after_second(t_system system, t_philo philo, int meals_eaten);

int	philo_think(t_system *system, t_philo *philo)
{
	int	flag;
	int	ms_start;
	int	ms_think;

	flag = SUCCESS;
	ms_start = get_time(system->ms_zero);
	flag |= philo_mutex_do(philo, system->print_mutex, print_str,
			(void *)"is thinking");
	if (flag != SUCCESS)
		return (SUCCESS);
	ms_think = ms_thinking_time(system, philo);
	if (ms_think < 0)
		return (FAILURE);
	wait_until_time(system->ms_zero, ms_start + ms_think, USLEEP);
	return (flag);
}

/* 

This algo defines the two different sleep time.

The one is "eat_time - sleep_time".  It is the basic think_time
which can make eat_time = sleep_time + think_time. So it enables philos
to gain eat-and-rest cycles. this cycles sync odds and evens
because of the sharing forks with next ones.

The other is "eat_time * 2 - sleep_time". When number of philos are odd, 
the first way has a problem. The last philo cant have a fork 
because the next one is also has odd id. this irregular think_time happens
number-of-philos a time. its because every time needs one rest person.

its the time schedule example when ./philo 7 300 90 90

| Cycle |  1  |  2  |  3  |  4  |  5  |  6  |  7  |
|-------|-----|-----|-----|-----|-----|-----|-----|
|   1   | eat | t&s | eat | t&s | eat | t&s | t&s |
|   2   | t&s | eat | t&s | eat | t&s | eat | t&s |
|   3   | t&s | t&s | eat | t&s | eat | t&s | eat |
|   4   | eat | t&s | t&s | eat | t&s | eat | t&s |
|   5   | t&s | eat | t&s | t&s | eat | t&s | eat |

*/

static int	ms_thinking_time(t_system *system, t_philo *philo)
{
	int	meals_eaten;

	if (philo_mutex_do(philo, philo->state_mutex,
			get_meals_eaten, &meals_eaten) != SUCCESS)
		return (ERROR);
	if (meals_eaten == 0)
		return (first_think(*system, *philo));
	else
		return (think_after_second(*system, *philo, meals_eaten));
}

static int	first_think(t_system system, t_philo philo)
{
	int	think_time; 

	if (philo.id == system.num_philos)
		think_time = system.time_to_eat * 2;
	else if (philo.id % 2 == 1)
		think_time = 0;
	else
		think_time = system.time_to_eat;
	return (think_time);
}

static int	think_after_second(t_system system, t_philo philo, int meals_eaten)
{
	int	think_time;
	int	num_groups;
	int	group_id;

	num_groups = system.num_philos / 2;
	group_id = (philo.id + 1) / 2;
	if (philo.id == system.num_philos)
		group_id--;
	if (system.num_philos % 2 == 0)
		think_time = system.time_to_eat - system.time_to_sleep;
	else if (group_id % num_groups == meals_eaten % num_groups)
		think_time = system.time_to_eat * 2 - system.time_to_sleep;
	else
		think_time = system.time_to_eat - system.time_to_sleep;
	if (think_time < 0)
		think_time = 0;
	return (think_time);
}

static int	get_meals_eaten(t_philo *philo, void *meals_eaten)
{
	*(int *)meals_eaten = philo->meals_eaten;
	return (SUCCESS);
}
