#include "ft_list.h"

t_list  *ft_list_at(t_list *begin_list, unsigned int nbr);

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list *a = NULL;
	t_list *b;
	void *swap;
	int i = 0;
	int size = 0;

	a = begin_list;
	while (a)
	{
		size ++;
		a = a->next;
	}
	a = begin_list;
	int beta = size - 1;
	while (i < size / 2)
	{
		 swap = a->data;
		 b = ft_list_at(a, beta - (i * 2));
		 a->data = b->data;
		 b->data = swap;
		 a = a->next;
		 i ++;
	}
}
