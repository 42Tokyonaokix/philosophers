/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_multiple_bases.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:06:16 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/22 15:01:49 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*return_u(va_list args, t_flag flag)
{
	unsigned int	nbr;
	char			*itoa;
	char			*dest;

	nbr = va_arg(args, unsigned int);
	if (nbr == 0 && flag.prezero)
		itoa = ft_strdup("");
	else
		itoa = ft_itoa_unsigned(nbr);
	dest = treat_flag_u(itoa, flag);
	return (dest);
}

char	*return_x(va_list args, t_flag flag)
{
	unsigned int	nbr;
	char			*itoa;
	char			*dest;

	nbr = va_arg(args, unsigned int);
	if (nbr == 0 && flag.prezero)
		itoa = ft_strdup("");
	else
		itoa = ft_itoa_hexs(nbr);
	dest = treat_flag_x(itoa, flag);
	return (dest);
}

char	*return_large_x(va_list args, t_flag flag)
{
	unsigned int	nbr;
	char			*itoa;
	char			*dest;

	nbr = va_arg(args, unsigned int);
	if (nbr == 0 && flag.prezero)
		itoa = ft_strdup("");
	else
		itoa = ft_itoa_hexb(nbr);
	dest = treat_flag_lx(itoa, flag);
	return (dest);
}

char	*return_p_null(t_flag flag)
{
	size_t	dcount;
	size_t	scount;
	char	*dest;
	size_t	size;

	size = return_maximum(flag.width, 5, 0);
	dest = (char *)malloc(sizeof(char) * size + 1);
	dcount = 0;
	scount = 0;
	if (flag.minus)
	{
		while ("(nil)"[scount])
			dest[dcount++] = "(nil)"[scount++];
		while (dcount < size)
			dest[dcount++] = ' ';
	}
	else
	{
		while (dcount + 5 < size)
			dest[dcount++] = ' ';
		while ("(nil)"[scount])
			dest[dcount++] = "(nil)"[scount++];
	}
	dest[dcount] = '\0';
	return (dest);
}

char	*return_p(va_list args, t_flag flag)
{
	void			*ptr;
	uintptr_t		addr;
	char			*itoa;
	char			*dest;

	ptr = va_arg(args, void *);
	if (!ptr)
	{
		dest = return_p_null(flag);
		return (dest);
	}
	addr = (uintptr_t)ptr;
	itoa = ft_itoa_hexs(addr);
	dest = treat_flag_p(itoa, flag);
	return (dest);
}
