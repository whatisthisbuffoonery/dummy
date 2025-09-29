#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *a = NULL;
	if (begin_list1)
		a = *begin_list1;
	while (a && a->next)
		a = a->next;
	if (a)
		a->next = begin_list2;
}
