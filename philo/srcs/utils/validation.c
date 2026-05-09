/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:14:43 by natakaha          #+#    #+#             */
/*   Updated: 2026/05/09 18:44:56 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	*validate_argument(int argc, char **argv)
{
	int	*num;
	int	i;

	if (argc < 5 || argc > 6)
		return (invalid_arg_error(), NULL);
	num = ft_calloc(6, sizeof(int));
	if (!num)
		return (fatal_error("malloc"), NULL);
	i = 0;
	while (i < argc - 1)
	{
		num[i] = ft_atoi(argv[i + 1]);
		if ((i == NUM_PHILOS && num[i] <= 0) || num[i] < 0)
			return (invalid_input_error(argv[i + 1]),
				free(num), NULL);
		i++;
	}
	if (argc == 5)
		num[MUST_EAT] = UNDEF;
	return (num);
}

void	fatal_error(char *arg)
{
	ft_putstr_fd("FATAL: ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd(" failed\n", STDERR_FILENO);
}

void	invalid_input_error(char *arg)
{
	ft_putstr_fd("INPUT: ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd(": invalid argumnet\n", STDERR_FILENO);
}

void	invalid_arg_error(void)
{
	ft_putstr_fd("INPUT: invalid arg number\n", STDERR_FILENO);
}
