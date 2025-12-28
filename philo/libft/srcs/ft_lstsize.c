#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	size_t	count;

	count = 0;
	temp = lst;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
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
//	printf("%d\n", ft_lstsize(*frontptr));
//}