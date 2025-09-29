#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list *a = NULL;
	t_list *b = NULL;
	t_list *tmp;
	if (begin_list)
		a = *begin_list;
	if (a)
	{
		b = a->next;
		a->next = NULL;
	}
	while (b)
	{
		tmp = b->next;
		b->next = a;
		a = b;
		b = tmp;
	}
	if (a)
		*begin_list = a;
}
