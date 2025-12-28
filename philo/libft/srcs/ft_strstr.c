/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:22:38 by natakaha          #+#    #+#             */
/*   Updated: 2025/09/09 12:28:34 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (to_find[0] == '\0')
		return (&str[0]);
	else
	{
		while (str[i] != '\0')
		{
			while (str[i + k] == to_find[k] && str[i] != '\0')
			{
				k++;
				if (to_find[k] == '\0' )
				{
					return (&str[i]);
				}
			}
			k = 0;
			i++;
		}
		return (NULL);
	}
}

//int main(void)
//{
//	char str[] = "ABCDCDCDFF";
//	char to_find[] = "X";

//	printf("Answer  =%p\n",strstr(str,to_find));
//	printf("Finder  =%p", ft_strstr(str, to_find));
//}
