#include "ft_list.h"

void	ft_not_split(t_list **begin_list, t_list **a, t_list **b)
{
	*a = *begin_list;
	t_list *i = *a;
	t_list *k = NULL;

	if (i)
		k = i->next;
	while (k && k->next)
	{
		i = i->next;
		k = k->next->next;
	}
	if (i)
		*b = i->next;
	if (*b)
		i->next = NULL;
}

void	window_shopping(t_list **begin_list, t_list *a, t_list *b, int (*cmp)(void *, void *))
{
	t_list *head = NULL;
	t_list *tmp = NULL;
	if (!b || cmp(a->data, b->data) < 0)
	{
		head = a;
		if (a)
			a = a->next;
	}
	else
	{
		head = b;
		if (b)
			b = b->next;
	}
	tmp = head;
	while (a && b)
	{
		if (cmp(a->data, b->data) < 0)
		{
			tmp->next = a;
			a = a->next;
		}
		else
		{
			tmp->next = b;
			b = b->next;
		}
		tmp = tmp->next;
	}
	while (a || b)
	{
		if (a)
		{
			tmp->next = a;
			a = a->next;
		}
		else
		{
			tmp->next = b;
			b = b->next;
		}
		tmp = tmp->next;
	}
	*begin_list = head;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)(void *, void *))
{
	t_list *a = NULL;
	t_list *b = NULL;

	ft_not_split(begin_list, &a, &b);
	if (a && a->next)
		ft_list_sort(&a, cmp);
	if (b && b->next)
		ft_list_sort(&b, cmp);

	window_shopping(begin_list, a, b, cmp);
}
