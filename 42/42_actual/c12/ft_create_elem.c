#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list *a = malloc(sizeof(t_list));
	a->data = data;
	a->next = NULL;
	return (a);
}
