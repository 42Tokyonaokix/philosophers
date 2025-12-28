/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:40:10 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/16 02:40:17 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

//int	main(void)
//{
//	t_list	*list1;
//	t_list	*list2;
//	t_list	*list3;
//	t_list	**frontptr;

//	list1 = ft_listnew("test1");
//	list2 = ft_listnew("test2");
//	list3 = ft_listnew("test3");
//	frontptr = &list3;
//	ft_lstadd_front(frontptr, list2);
//	ft_lstadd_front(frontptr, list1);
//	printf("%s\n", (char *)(*frontptr)->content);
//	printf("%s\n", (char *)(*frontptr)->next->content);
//	printf("%s\n", (char *)(*frontptr)->next->next->content);
//}

//int	main(void)
//{
//	t_list	*list1;
//	t_list	**frontptr;
//	t_list	*frontlst;

//	frontlst = NULL;
//	frontptr = &frontlst;
//	//frontptr = NULL;
//	list1 = ft_listnew("test1");
//	ft_lstadd_front(frontptr, list1);
//	printf("%s\n", (char *)(*frontptr)->content);
//	printf("%p\n", (char *)(*frontptr)->next);
//}
