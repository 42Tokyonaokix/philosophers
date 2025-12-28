/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_flag_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:10:04 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/22 14:07:58 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*treat_flag_u_m(char *itoa, t_flag flag, char *dest, size_t size)
{
	size_t	icount;
	size_t	dcount;

	dcount = 0;
	icount = 0;
	while (dcount + ft_strlen(itoa) < flag.precision)
		dest[dcount++] = '0';
	while (itoa[icount])
		dest[dcount++] = itoa[icount++];
	while (dcount < size)
		dest[dcount++] = ' ';
	dest[dcount] = '\0';
	return (dest);
}

static char	*treat_flag_u_z(char *itoa, t_flag flag, char *dest, size_t size)
{
	size_t	icount;
	size_t	dcount;

	icount = 0;
	dcount = 0;
	while (dcount + ft_strlen(itoa) < size)
		dest[dcount++] = '0';
	while (itoa[icount])
		dest[dcount++] = itoa[icount++];
	dest[dcount] = '\0';
	(void)flag;
	return (dest);
}

static char	*treat_flag_u_n(char *itoa, t_flag flag, char *dest, size_t size)
{
	size_t	icount;
	size_t	dcount;

	dcount = 0;
	icount = 0;
	while (dcount + flag.precision < size && dcount + ft_strlen(itoa) < size)
		dest[dcount++] = ' ';
	while (dcount + ft_strlen(itoa) < size)
		dest[dcount++] = '0';
	while (itoa[icount])
		dest[dcount++] = itoa[icount++];
	dest[dcount] = '\0';
	return (dest);
}

static char	*treat_flag_u1(char *itoa, t_flag flag, char *dest, size_t size)
{
	if (flag.minus)
		dest = treat_flag_u_m(itoa, flag, dest, size);
	else if (flag.zero && !flag.prezero && !flag.precision)
		dest = treat_flag_u_z(itoa, flag, dest, size);
	else
		dest = treat_flag_u_n(itoa, flag, dest, size);
	free(itoa);
	return (dest);
}

char	*treat_flag_u(char	*itoa, t_flag flag)
{
	size_t	size;
	char	*dest;

	size = return_maximum(flag.precision, ft_strlen(itoa), flag.width);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	dest = treat_flag_u1(itoa, flag, dest, size);
	return (dest);
}
