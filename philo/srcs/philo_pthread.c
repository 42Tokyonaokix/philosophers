/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_pthread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:24:44 by natakaha          #+#    #+#             */
/*   Updated: 2026/01/09 18:10:28 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

pthread_mutex_t	*microphone(void)
{
	static pthread_mutex_t	*mic;

	if (!mic)
		mic = setup_mutex(1);
	if (!mic)
		return (NULL);
	return (mic);
}

int	have_forks(t_philos philo,
	pthread_mutex_t *first,
	pthread_mutex_t *next)
{
	if (!pthread_mutex_lock(first))
	{
		print_state(philo.tag, "has taken a fork");
		pthread_mutex_lock(next);
		print_state(philo.tag, "has taken a fork");
		return (SUCCESS);
	}
	return (FAILUER);
}

int	print_state(int tag, char *str)
{
	pthread_mutex_t	*mic;
	static int		flag;

	mic = microphone();
	if (!mic)
		return (FAILUER);
	if (pthread_mutex_lock(mic))
		return (FAILUER);
	if (flag == DEATH)
	{
		pthread_mutex_unlock(mic);
		return (FAILUER);
	}
	ft_printf("timestamp_in_%d %d %s\n", timer(), tag, str);
	if (!ft_strncmp(str, "died", 5))
		flag = DEATH;
	pthread_mutex_unlock(mic);
	return (SUCCESS);
}

int	count_eating(t_philos philo, int flag)
{
	static int	count;
	int			turn;

	if (!(philo.num % 2))
		return (-1);
	turn = (philo.num - 1) / 2;
	if (flag)
		count++;
	return (count / turn);
}

int	main(int argc, char **argv)
{
	int			i;
	t_philos	*philo;

	if (argc != 5 && argc != 6)
		return (ft_putendl_fd("invalid arg number", 2), 1);
	i = ft_atoi(argv[1]);
	philo = set_philo_fork(i, argv);
	if (!philo)
		return (1);
	if (create_and_join(i, philo, life_manage) == FAILUER)
		return (1);
	return (0);
}
