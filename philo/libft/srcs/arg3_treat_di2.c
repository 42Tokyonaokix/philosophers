/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_flag_di2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:01:37 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/22 11:43:29 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*treat_flag_di_hm(char *itoa, t_flag flag, char *dest, size_t size)
{
	size_t	icount;
	size_t	dcount;
	size_t	isize;

	icount = 0;
	dcount = 0;
	isize = ft_strlen(itoa);
	if (itoa[icount] == '-')
	{
		dest[dcount++] = itoa[icount++];
		isize--;
	}
	else if (flag.plus)
		dest[dcount++] = '+';
	else
		dest[dcount++] = ' ';
	while (dcount - 1 + isize < flag.precision)
		dest[dcount++] = '0';
	while (itoa[icount])
		dest[dcount++] = itoa[icount++];
	while (dcount < size)
		dest[dcount++] = ' ';
	dest[dcount] = '\0';
	return (dest);
}

static char	*treat_flag_di_hz(char *itoa, t_flag flag, char *dest, size_t size)
{
	size_t	icount;
	size_t	dcount;
	size_t	isize;

	icount = 0;
	dcount = 0;
	isize = ft_strlen(itoa);
	if (itoa[icount] == '-')
	{
		dest[dcount++] = itoa[icount++];
		isize--;
	}
	else if (flag.plus)
		dest[dcount++] = '+';
	else
		dest[dcount++] = ' ';
	while (dcount + isize < size)
		dest[dcount++] = '0';
	while (itoa[icount])
		dest[dcount++] = itoa[icount++];
	dest[dcount] = '\0';
	return (dest);
}

static char	*treat_flag_di_hn(char *itoa, t_flag flag, char *dest, size_t size)
{
	size_t	icount;
	size_t	dcount;
	size_t	isize;

	icount = 0;
	dcount = 0;
	isize = ft_strlen(itoa);
	if ((flag.plus || flag.space) && itoa[icount] != '-')
		isize += 1;
	while (dcount + flag.precision + 1 < size && dcount + isize < size)
		dest[dcount++] = ' ';
	if (flag.plus && itoa[icount] != '-')
		dest[dcount++] = '+';
	else if (flag.space && itoa[icount] != '-')
		dest[dcount++] = ' ';
	else
		dest[dcount++] = itoa[icount++];
	while (dcount + isize - 1 < size)
		dest[dcount++] = '0';
	while (itoa[icount])
		dest[dcount++] = itoa[icount++];
	dest[dcount] = '\0';
	return (dest);
}

char	*treat_flag_di_h(char *itoa, t_flag flag, char *dest, size_t size)
{
	if (flag.minus)
		dest = treat_flag_di_hm(itoa, flag, dest, size);
	else if (flag.zero && !flag.prezero && !flag.precision)
		dest = treat_flag_di_hz(itoa, flag, dest, size);
	else
		dest = treat_flag_di_hn(itoa, flag, dest, size);
	return (dest);
}
