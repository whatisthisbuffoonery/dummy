#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int i = 0;
	t_list *a = begin_list;
	while (a)
	{
		a = a->next;
		i ++;
	}
	return (i);
}
