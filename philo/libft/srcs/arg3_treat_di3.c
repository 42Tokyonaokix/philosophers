/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_flag_di3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:04:00 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/22 11:44:07 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*treat_flag_di_nm(char *itoa, t_flag flag, char *dest, size_t size)
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

static char	*treat_flag_di_nz(char *itoa, t_flag flag, char *dest, size_t size)
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

static char	*treat_flag_di_nn(char *itoa, t_flag flag, char *dest, size_t size)
{
	size_t	icount;
	size_t	dcount;

	dcount = 0;
	icount = 0;
	while (dcount + flag.precision < size && dcount + ft_strlen(itoa) < size)
		dest[dcount++] = ' ';
	while (dcount < size - ft_strlen(itoa))
		dest[dcount++] = '0';
	while (itoa[icount])
		dest[dcount++] = itoa[icount++];
	dest[dcount] = '\0';
	return (dest);
}

char	*treat_flag_di_n(char *itoa, t_flag flag, char *dest, size_t size)
{
	if (flag.minus)
		dest = treat_flag_di_nm(itoa, flag, dest, size);
	else if (flag.zero && !flag.prezero && !flag.precision)
		dest = treat_flag_di_nz(itoa, flag, dest, size);
	else
		dest = treat_flag_di_nn(itoa, flag, dest, size);
	return (dest);
}
