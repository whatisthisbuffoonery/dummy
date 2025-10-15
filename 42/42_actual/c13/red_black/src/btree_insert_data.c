#include "rb.h"

node	*btree_create_node(void *data, node *nil);
void	rotate_mux(tree *dis, node *x, char a);
void	btree_infix(node *root, node *nil, int k);
void	ft_putstr(char *a);
char	ft_child_not(node *a);

void	ft_recolour(tree *dis, node *curr, int flag)
{
	node *unc = dis->nil;
	
	if (*dis->root == curr)
		return;
	curr->colour ^= 1;
	curr->P->colour ^= 1;
	if (curr == curr->P->L)
		unc = curr->P->R;
	else
		unc = curr->P->L;
	if (unc != dis->nil && flag)
		unc->colour ^= 1;
	write(1, "ree\n", 4);
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
	return (unc->colour);
}


int		ft_check(node **root, node **a)
{
	node *tmp = *a;
	while (tmp != *root)
	{
		if (tmp->colour == red && tmp->P->colour == red)
		{
			*a = tmp;
			write(1, "!", 1);
			ft_putstr((char *)tmp->data);
			return (1);
		}
		tmp = tmp->P;
	}
	return (0);
}

void	btree_insert_data(tree *dis, void *data, int (*cmpf)(void *, void *), int back[])
{
	int compare = 0;
	node *a = btree_create_node(data, dis->nil);
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
	if (*dis->root == dis->nil)
	{
		a->colour = black;
		*dis->root = a;
		write(1, "\n", 1);
		btree_infix(*dis->root, dis->nil, 1);
		write(1, "\n---\n", 5);
		return;
	}
	if (compare > 0)
		curr->R = a;
	if (compare < 0)
		curr->L = a;
	a->P = curr;
	while (ft_check(dis->root, &a))
	{
		if ((*dis->root)->colour == red)
		{
			write(1, "root red", 8);
			(*dis->root)->colour = black;
		}
		else if (!ft_unc(a->P, dis->nil))
		{
			ft_recolour(dis, a->P, 1);
			back[1] += 1;
		}
		else if (ft_child_not(a) != ft_child_not(a->P))
		{
			next = a->P;
			rotate_mux(dis, a->P, ft_child_not(a));
			a = next;
			back[0] += 1;
		}
		else
		{
			ft_recolour(dis, a->P, 0);
			back[1] += 1;
			rotate_mux(dis, a->P->P, ft_child_not(a->P));
			back[0] += 1;
		}
		dis->nil->colour = black;
	}
	write(1, "\n", 1);
	btree_infix(*dis->root, dis->nil, 1);
	write(1, "\n---\n", 5);
}
