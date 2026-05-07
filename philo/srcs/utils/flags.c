/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:14:43 by natakaha          #+#    #+#             */
/*   Updated: 2026/05/07 16:20:53 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

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
