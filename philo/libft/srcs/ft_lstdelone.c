/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:40:35 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/16 02:40:37 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}

//int	main(void)
//{
//	t_list	*list1;
//	t_list	*list2;
//	t_list	*list3;
//	t_list	*list4;
//	t_list	**frontptr;

//	list1 = ft_listnew(strdup("test1"));
//	list2 = ft_listnew("test2");
//	list3 = ft_listnew("test3");
//	list4 = ft_listnew("test4");
//	frontptr = &list3;
//	ft_lstadd_front(frontptr, list2);
//	ft_lstadd_front(frontptr, list1);
//	ft_lstadd_back(frontptr, list4);
//	printf("%p\n", (char *)(*frontptr));
//	ft_lstdelone(*frontptr, free);
//	printf("%p\n", (char *)(*frontptr));
//}

//int main(void)
//{
//	t_list	*list1;

//	list1 = ft_listnew(strdup("test1"));
//	ft_lstdelone(list1, free);
//}
