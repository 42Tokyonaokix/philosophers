#include "../libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}

//int	main(void)
//{
//	t_list	*list1;
//	t_list	*list2;
//	t_list	*list3;
//	t_list	*list4;
//	t_list	**frontptr;

//	list1 = ft_listnew("test1");
//	list2 = ft_listnew("test2");
//	list3 = ft_listnew("test3");
//	list4 = ft_listnew("test4");
//	frontptr = &list3;
//	ft_lstadd_front(frontptr, list2);
//	ft_lstadd_front(frontptr, list1);
//	ft_lstadd_back(frontptr, list4);
//	printf("%s\n", (char *)ft_lstlast(*frontptr)->content);
//}

//int	main(void)
//{
//	t_list	*list1;
//	t_list	**frontptr;
//	t_list	*frontlst;
	
//	frontlst = NULL;
//	frontptr = &frontlst;
//	list1 = ft_listnew("test1");
//	ft_lstadd_back(frontptr, list1);
//	printf("%s\n", (char *)(*frontptr)->content);
//}

//int	main(void)
//{
//	t_list	*list1;
//	t_list	**frontptr;
	
//	frontptr = NULL;
//	list1 = ft_listnew("test1");
//	ft_lstadd_back(frontptr, list1);
//}