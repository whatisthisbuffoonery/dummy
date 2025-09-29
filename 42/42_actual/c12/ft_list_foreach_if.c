#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)(void *, void *))
{
	t_list *a = begin_list;

	while (a)
	{
		if (!cmp(a->data, data_ref))
			f(a->data);
		a = a->next;
	}
}
