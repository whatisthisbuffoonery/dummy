#include "rb.h"

void	ft_recolour(tree *dis, node *curr, int flag, int verbose)
{
	node *unc = dis->nil;
	
	if (*dis->root == curr)
		return;
	curr->C ^= 1;
	curr->P->C ^= 1;
	if (curr == curr->P->L)
		unc = curr->P->R;
	else
		unc = curr->P->L;
	if (unc != dis->nil && flag)
		unc->C ^= 1;
	if (verbose)
		write(1, "recolour\n", 9);
}

int		ft_unc(node *curr, node *nil)
{
	node *unc = nil;
	if (curr == curr->P->L)
		unc = curr->P->R;
	else
		unc = curr->P->L;
	if (unc == nil)
		return (1);
	return (unc->C);
}


int		ft_check(node **root, node **a, int verbose)
{
	node *tmp = *a;
	while (tmp != *root)
	{
		if (tmp->C == red && tmp->P->C == red)
		{
			*a = tmp;
			if (verbose)
			{
				write(1, "!", 1);
				ft_putstr((char *)tmp->data);
			}
			return (1);
		}
		tmp = tmp->P;
	}
	return (0);
}

void	btree_insert_data(tree *dis, void *data, int (*cmpf)(void *, void *), int back[], int verbose)
{
	int compare = 0;
	node *a;
	node *curr = *dis->root;
	node *next = dis->nil;
	while (curr != dis->nil)
	{
		compare = cmpf(data, curr->data);
		if (compare > 0)
			next = curr->R;
		else if (compare < 0)
			next = curr->L;
		else
			return;
			//ft_dupe(curr);
		if (next != dis->nil)
		{
			curr = next;
			next = dis->nil;
		}
		else
			break;
	}
	a = btree_create_node(data, dis->nil);
	if (*dis->root == dis->nil)
	{
		a->C = black;
		*dis->root = a;
		if (verbose)
		{
			write(1, "\n", 1);
			btree_prefix(*dis->root, dis->nil, 1);
			write(1, "\n---\n", 5);
		}
		return;
	}
	if (compare > 0)
		curr->R = a;
	if (compare < 0)
		curr->L = a;
	a->P = curr;
	while (ft_check(dis->root, &a, verbose))
	{
		if ((*dis->root)->C == red)
		{
			if (verbose)
				write(1, "root red", 8);
			(*dis->root)->C = black;
		}
		else if (!ft_unc(a->P, dis->nil))
		{
			ft_recolour(dis, a->P, 1, verbose);
			back[1] += 1;
		}
		else if (ft_child_not(a) != ft_child_not(a->P))
		{
			next = a->P;
			rotate_mux(dis, a->P, ft_child_not(a), verbose);
			a = next;
			back[0] += 1;
		}
		else
		{
			ft_recolour(dis, a->P, 0, verbose);
			back[1] += 1;
			rotate_mux(dis, a->P->P, ft_child_not(a->P), verbose);
			back[0] += 1;
		}
		dis->nil->C = black;
	}
	if (verbose)
	{
		write(1, "\n", 1);
		btree_prefix(*dis->root, dis->nil, 1);
		write(1, "\n---\n", 5);
	}
}
