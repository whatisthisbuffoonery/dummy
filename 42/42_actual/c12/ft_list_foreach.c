#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list *a = begin_list;

	while (a)
	{
		f(a->data);
		a = a->next;
	}
}
