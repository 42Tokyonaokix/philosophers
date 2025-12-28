/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_flag_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:53:48 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/22 15:01:39 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*treat_flag_s1(char *src, t_flag flag, char *dest, size_t size)
{
	size_t	dcount;
	size_t	scount;

	dcount = 0;
	scount = 0;
	if (flag.minus)
	{
		while (src[scount] && (scount < flag.precision || flag.precision == 0))
			dest[dcount++] = src[scount++];
		while (dcount < size)
			dest[dcount++] = ' ';
	}
	else
	{
		while ((flag.precision != 0 && dcount < size - minimum(ft_strlen(src),
					flag.precision)) || (flag.precision == 0
				&& dcount < size - ft_strlen(src)))
			dest[dcount++] = ' ';
		while (dcount < size)
			dest[dcount++] = src[scount++];
	}
	dest[dcount] = '\0';
	return (dest);
}

static char	*treat_flag_prezero(char *src, t_flag flag, char *dest, size_t size)
{
	size_t	dcount;

	dcount = 0;
	while (dcount < size)
		dest[dcount++] = ' ';
	dest[dcount] = '\0';
	(void)src;
	(void)flag;
	return (dest);
}

static char	*treat_flag_s(char *src, t_flag flag)
{
	size_t	size;
	char	*dest;

	size = ft_strlen(src);
	if (flag.precision && size > flag.precision)
		size = flag.precision;
	if (flag.prezero)
		size = 0;
	if (size < flag.width)
		size = flag.width;
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	if (flag.prezero)
		dest = treat_flag_prezero(src, flag, dest, size);
	else
		dest = treat_flag_s1(src, flag, dest, size);
	return (dest);
}

char	*return_s(va_list args, t_flag flag)
{
	char	*src;
	char	*dest;

	src = va_arg(args, char *);
	if (!src)
	{
		if ((1 <= flag.precision && flag.precision < 6) || flag.prezero)
			src = "";
		else
			src = "(null)";
	}
	dest = treat_flag_s(src, flag);
	return (dest);
}
