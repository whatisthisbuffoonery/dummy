#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int i = 0;
	t_list *a = begin_list;
	while (i < nbr && a)
	{
		a = a->next;
		i ++;
	}
	return (a);
}
