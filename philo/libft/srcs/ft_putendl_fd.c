/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:46:48 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/16 02:46:54 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

//int main(int argc, char **argv)
//{
//	int	fd;

//	fd = open(argv[1], O_WRONLY);
//	ft_putendl_fd(argv[2], fd);
//	(void)argc;
//	(void)argv;
//}
