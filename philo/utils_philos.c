/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-23 09:48:53 by natakaha          #+#    #+#             */
/*   Updated: 2025-12-23 09:48:53 by natakaha         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//t_philos	*p_lstnew(pthread_t tag)
//{
//	t_philos	*node;

//	node = ft_calloc(sizeof(t_philos), 1);
//	node->tag = tag;
//	return (node);
//}

//void	p_lstadd_back(t_philos **lst, t_philos *new)
//{
//	t_philos	*tmp;

//	tmp = *lst;
//	if (!tmp)
//	{
//		tmp = new;
//		return ;
//	}
//	while (tmp->next)
//		tmp = tmp->next;
//	tmp->next = new;
//	return ;
//}

//void	p_lstclear(t_philos **lst)
//{
//	t_philos *tmp;

//	tmp = *lst;
//	while (tmp)
//	{
//		tmp = tmp->next;
//		free(*lst);
//		*lst = tmp;
//	}
//	lst = NULL;
//}

//t_philos	*p_create_(int	n)
//{
//	int			i;
//	t_philos	*new;
//	t_philos	*lst;

//	i = 0;
//	lst = NULL;
//	while (i < n)
//	{
//		new = p_lstnew(i);
//		if (!new)
//			return (p_lstclear(&lst), NULL);
//		p_lstadd_back(&lst, new);
//		i++;
//	}
//	return (lst);
//}

