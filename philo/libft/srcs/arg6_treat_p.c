/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_flag_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:16:57 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/17 22:20:25 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*treat_flag_p_m(char *itoa, t_flag flag, char *dest, size_t size)
{
	size_t	icount;
	size_t	dcount;

	icount = 0;
	dcount = 0;
	dest[dcount++] = '0';
	dest[dcount++] = 'x';
	while (dcount - 2 + ft_strlen(itoa) < flag.precision)
		dest[dcount++] = '0';
	while (dcount + ft_strlen(itoa) < flag.precision)
		dest[dcount++] = '0';
	while (itoa[icount])
		dest[dcount++] = itoa[icount++];
	while (dcount < size)
		dest[dcount++] = ' ';
	dest[dcount] = '\0';
	return (dest);
}

static char	*treat_flag_p_z(char *itoa, t_flag flag, char *dest, size_t size)
{
	size_t	icount;
	size_t	dcount;

	icount = 0;
	dcount = 0;
	dest[dcount++] = '0';
	dest[dcount++] = 'x';
	while (dcount + ft_strlen(itoa) < size)
		dest[dcount++] = '0';
	while (itoa[icount])
		dest[dcount++] = itoa[icount++];
	dest[dcount] = '\0';
	(void)flag;
	return (dest);
}

static char	*treat_flag_p_n(char *itoa, t_flag flag, char *dest, size_t size)
{
	size_t	icount;
	size_t	dcount;

	icount = 0;
	dcount = 0;
	while (dcount + flag.precision + 2 < size
		&& dcount + ft_strlen(itoa) + 2 < size)
		dest[dcount++] = ' ';
	dest[dcount++] = '0';
	dest[dcount++] = 'x';
	while (dcount + ft_strlen(itoa) < size)
		dest[dcount++] = '0';
	while (itoa[icount])
		dest[dcount++] = itoa[icount++];
	dest[dcount] = '\0';
	return (dest);
}

static char	*treat_flag_p1(char *itoa, t_flag flag, char *dest, size_t size)
{
	if (flag.minus)
		dest = treat_flag_p_m(itoa, flag, dest, size);
	else if (flag.zero)
		dest = treat_flag_p_z(itoa, flag, dest, size);
	else
		dest = treat_flag_p_n(itoa, flag, dest, size);
	free(itoa);
	return (dest);
}

char	*treat_flag_p(char	*itoa, t_flag flag)
{
	size_t	size;
	char	*dest;

	size = return_maximum(flag.precision + 2, ft_strlen(itoa) + 2, flag.width);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	dest = treat_flag_p1(itoa, flag, dest, size);
	return (dest);
}
