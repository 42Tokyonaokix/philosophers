/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:41:37 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/16 02:42:39 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static t_list	*ft_lstmap2(t_list *lst, void *(*f)(void *),
					void (*del)(void *), t_list *newlist);

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	void	*fstcontent;

	if (!lst)
		return (NULL);
	fstcontent = f(lst->content);
	newlist = ft_lstnew(fstcontent);
	if (!newlist)
	{
		del(fstcontent);
		return (NULL);
	}
	lst = lst->next;
	newlist = ft_lstmap2(lst, f, del, newlist);
	return (newlist);
}

static t_list	*ft_lstmap2(t_list *lst, void *(*f)(void *),
					void (*del)(void *), t_list *newlist)
{
	t_list	*addlist;
	void	*addcontent;

	while (lst)
	{
		addcontent = f(lst->content);
		addlist = ft_lstnew(addcontent);
		if (!addlist)
		{
			ft_lstclear(&newlist, del);
			del(addcontent);
			return (NULL);
		}
		ft_lstadd_back(&newlist, addlist);
		lst = lst->next;
	}
	return (newlist);
}

//void *lst_upper(void *c)
//{
//    size_t	index;
//	char	*p;

//	index = 0;
//	p = (char *)c;
//	while (p[index])
//	{
//		if ('a' <= p[index] && p[index] <= 'z')
//			p[index] -= 32;
//		index++;
//	}
//	return ((void *)p);
//}

//int	main(void)
//{
//	t_list	*list1;
//	t_list	*list2;
//	t_list	*list3;
//	t_list	*list4;
//	t_list	**frontptr;

//	list1 = ft_lstnew(strdup("test1"));
//	list2 = ft_lstnew(strdup("test2"));
//	list3 = ft_lstnew(strdup("test3"));
//	list4 = ft_lstnew(strdup("test4"));
//	frontptr = &list3;
//	ft_lstadd_front(frontptr, list2);
//	ft_lstadd_front(frontptr, list1);
//	ft_lstadd_back(frontptr, list4);
//	printf("%s\n", (char *)list1->content);
//	printf("%s\n", (char *)list2->content);
//	printf("%s\n", (char *)list3->content);
//	printf("%s\n", (char *)list4->content);
//	ft_lstmap(list1, lst_upper, free);
//	printf("%s\n", (char *)list1->content);
//	printf("%s\n", (char *)list2->content);
//	printf("%s\n", (char *)list3->content);
//	printf("%s\n", (char *)list4->content);
//}
