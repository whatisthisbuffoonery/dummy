#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *), void (*free_fct)(void *))
{
	t_list *a = NULL;
	t_list *b = NULL;
	t_list *head = NULL;

	if (begin_list)
		head = *begin_list;
	if (head)
		b = head->next;
	while (head && !cmp(head->data, data_ref))
	{
		if (free_fct)
			free_fct(head->data);
		free(head);
		head = b;
		b = head->next;
	}
	a = head;
	while (b)
	{
		if (!cmp(b->data, data_ref))
		{
			a->next = b->next;
			if (free_fct)
				free_fct(b->data);
			free(b);
			b = NULL;
		}
		if (b)
			a = a->next;
		b = a->next;
	}
	*begin_list = head;
}
