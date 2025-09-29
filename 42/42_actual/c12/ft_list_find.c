#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)(void *, void *))
{
	t_list *a = begin_list;

	while (a)
	{
		if (!cmp(a->data, data_ref))
			return (a);
		a = a->next;
	}
	return (NULL);
}
