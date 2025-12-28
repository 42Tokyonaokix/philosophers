/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:40:23 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/16 02:40:29 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!*lst)
		return ;
	temp = ((*lst)->next);
	while (true)
	{
		ft_lstdelone(*lst, del);
		*lst = temp;
		if (*lst == NULL)
			return ;
		temp = (*lst)->next;
	}
}

//int	main(void)
//{
//	t_list	*list1;
//	t_list	*list2;
//	t_list	*list3;
//	t_list	*list4;
//	t_list	**frontptr;

//	list1 = ft_listnew(strdup("test1"));
//	list2 = ft_listnew(strdup("test2"));
//	list3 = ft_listnew(strdup("test3"));
//	list4 = ft_listnew(strdup("test4"));
//	frontptr = &list3;
//	ft_lstadd_front(frontptr, list2);
//	ft_lstadd_front(frontptr, list1);
//	ft_lstadd_back(frontptr, list4);
//	printf("%s\n", (char *)ft_lstlast(*frontptr)->content);
//	ft_lstclear(frontptr, free);
//}
