/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_multiple_lists.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:19:20 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/17 22:19:00 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	free_formlist(char **formlist, size_t count)
{
	while (count-- > 0)
		free(formlist[count]);
	free(formlist);
}

void	free_arglist(char **arglist, size_t count)
{
	while (count--)
		free(arglist[count]);
	free(arglist);
}
