/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:14:43 by natakaha          #+#    #+#             */
/*   Updated: 2026/05/03 07:08:16 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	main(int argc, char **argv)
{
	int			**num;
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
	flag = SUCCESS;
	flag |= create_threads(system->num_philos, philo_life_manage, philo_monitor, philo);
	flag |= free_system(system);
	free(philo);
	if (flag == FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);	
}
