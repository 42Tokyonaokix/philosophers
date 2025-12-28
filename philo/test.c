/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 09:33:04 by natakaha          #+#    #+#             */
/*   Updated: 2025/12/28 20:47:34 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//void	*hello_world(void *arg)
//{
//	int	i;

//	i = *(int *)arg;
//	ft_putstr_fd("I am", 1);
//	ft_putnbr_fd(i, 1);
//	ft_putendl_fd("th philosopher", 1);
//	return (NULL);
//}

void	collect_info(t_philos *node, char **argv)
{

}

int	main(int argc, char **argv)
{
	int			i;
	t_philos	*lst;

	if (argc != 4 && argc != 5)
		return (ft_putendl_fd("invalid arg number", 2), 1);
	i = 0;
	lst = (t_philos *)ft_calloc(7, sizeof(t_philos));
	if (!lst)
		return (1);
	while (i < 7)
	{
		if (pthread_create(&lst[i].tag, NULL, hello_world, &i))
			return (1);
		collect_info(lst[i], argv);
		pthread_join(lst[i].tag, NULL);
		i++;
	}
}

//#include <stdio.h>
//#include <sys/time.h>

//int	main(void)
//{
//	struct timeval	tv;

//	gettimeofday(&tv, NULL);
//	printf("%ld:%ld",tv.tv_sec, tv.tv_usec);
//}