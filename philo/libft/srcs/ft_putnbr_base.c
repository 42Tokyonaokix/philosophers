/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:19:39 by natakaha          #+#    #+#             */
/*   Updated: 2025/09/18 15:44:53 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	str_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i])
	{
		if (base[i] < 32 || 127 <= base[i] || 127 <= base[i]
			|| base[i] == 43 || base[i] == 45)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				base_len;
	int				remain;
	long long int	lnbr;

	lnbr = nbr;
	if (str_check (base) == 0)
	{
	}
	else
	{
		base_len = ft_strlen (base);
		remain = 0;
		if (lnbr < 0)
		{
			write (1, "-", 1);
			lnbr = -lnbr;
		}
		remain = lnbr % base_len;
		lnbr = lnbr / base_len;
		if (lnbr)
			ft_putnbr_base(lnbr, base);
		write (1, &base[remain], 1);
	}
}

//int	main(void)
//{
//	ft_putnbr_base(INT_MIN, "012345678");
//}
