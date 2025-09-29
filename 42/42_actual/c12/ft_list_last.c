#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list *a = begin_list;
	if (!a)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}
