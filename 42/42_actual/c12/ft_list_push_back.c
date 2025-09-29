#include "ft_list.h"

t_list	*ft_create_elem(void *data);

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *a = *begin_list;
	while (a && a->next)
		a = a->next;
	if (a)
		a->next = ft_create_elem(data);
	else
		*begin_list = ft_create_elem(data);
}
