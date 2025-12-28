/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_flag_di1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:57:39 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/22 12:52:40 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*treat_flag_di1(char *itoa, t_flag flag, char *dest, size_t size)
{
	if (itoa[0] == '-' || flag.space || flag.plus)
		dest = treat_flag_di_h(itoa, flag, dest, size);
	else
		dest = treat_flag_di_n(itoa, flag, dest, size);
	free(itoa);
	return (dest);
}

static char	*treat_flag_di(char	*itoa, t_flag flag)
{
	size_t	size;
	char	*dest;

	if (itoa[0] == '-')
		size = return_maximum(flag.precision + 1, ft_strlen(itoa), flag.width);
	else if (flag.plus || flag.space)
		size = return_maximum(flag.precision + 1,
				ft_strlen(itoa) + 1, flag.width);
	else
		size = return_maximum(flag.precision, ft_strlen(itoa), flag.width);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	dest = treat_flag_di1(itoa, flag, dest, size);
	return (dest);
}

char	*return_di(va_list args, t_flag flag)
{
	int		nbr;
	char	*itoa;
	char	*dest;

	nbr = va_arg(args, int);
	if (nbr == 0 && flag.prezero)
		itoa = ft_strdup("");
	else
		itoa = ft_itoa(nbr);
	dest = treat_flag_di(itoa, flag);
	return (dest);
}
