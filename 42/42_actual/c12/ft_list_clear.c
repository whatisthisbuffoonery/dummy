#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list *a = begin_list;
	t_list *b = NULL;
	if (a)
	{
		b = a->next;
		if (free_fct)
			free_fct(a->data);
		free(a);
	}
	while (b)
	{
		a = b->next;
		if (free_fct)
			free_fct(b->data);
		free(b);
		b = a;
	}
}
