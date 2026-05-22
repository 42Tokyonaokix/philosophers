/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:14:43 by natakaha          #+#    #+#             */
/*   Updated: 2026/05/22 20:08:59 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	main(int argc, char **argv)
{
	int			*num;
	t_system	*system;
	t_philo		*philo;
	int			flag;

	num = validate_argument(argc, argv);
	if (!num)
		return (EXIT_FAILURE);
	system = setup_t_system(num);
	free(num);
	if (!system)
		return (EXIT_FAILURE);
	philo = setup_t_philo(system);
	if (!philo)
		return (free_system(system), EXIT_FAILURE);
	flag = create_threads(system->num_philos, philo_life_manage, philo_monitor,
			philo);
	free(philo);
	flag |= execute_bit_value(system->philos_state);
	free_system(system);
	if (flag == SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

/* 
void	print_system(t_system *system)
{
	printf("num_philos: %d\n", system->num_philos);
	printf("time_to_die: %d\n", system->time_to_die);
	printf("time_to_eat: %d\n", system->time_to_eat);
	printf("time_to_sleep: %d\n", system->time_to_sleep);
	printf("must_eat_count: %d\n", system->must_eat_count);
	printf("ms_zero: %d\n", system->ms_zero);
	printf("forks: %p\n", system->forks);
	printf("print_mutex: %p\n", system->print_mutex);
	printf("dead_mutex: %p\n", system->dead_mutex);
	printf("state_mutex: %p\n", system->state_mutex);
}

void	print_philo(t_philo *philo)
{
	printf("id: %d\n", philo->id);
	printf("last_meal_time: %ld\n", philo->last_meal_time);
	printf("meals_eaten: %d\n", philo->meals_eaten);
	printf("left_fork: %p\n", philo->left_fork);
	printf("right_fork: %p\n", philo->right_fork);
	printf("state_mutex: %p\n", philo->state_mutex);
	printf("system: %p\n", philo->system);
} 
*/