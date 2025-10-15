#include "rb.h"

char	ft_child(node *a);

void	top_shear(tree *dis, node *curr, node *a)
{
	if (curr->P == dis->nil)
		*dis->root = a;
	else if (ft_child(curr) == 'L')
		curr->P->L = a;
	else
		curr->P->R = a;
	a->P = curr->P;
}

void	delete_fix(node *a, node *nil)
{
	if (a == nil && a->P == nil)
		return;
	if (a->colour == red)
	{
		a->colour = black;
		return;
	}

void	btree_delete(tree *dis, node *curr, void (*free_fct)(node *))
{
	node *nil = dis->nil;
	node **root = dis->root;
	node *tmp = curr->P;
	node *tmp2 = nil;
	char c = 'N';
	if (curr->R != nil && curr->L == nil)
	{
		tmp = curr->R;
		top_shear(root, curr, curr->R);
	}
	else if (curr->L != nil && curr->R == nil)
	{
		tmp = curr->L;
		top_shear(root, curr, curr->L);
	}
	else if (curr->L != nil && curr->R != nil)
	{
		tmp = curr->R;
		while (tmp->L != nil)
			tmp = tmp->L;
		tmp2 = tmp->P;
		if (tmp == curr->R)
			tmp2 = tmp;
		c = ft_child(tmp);
		top_shear(root, tmp, tmp->R);
		if (tmp != curr->R)
		{
			curr->R->P = tmp;
			tmp->R = curr->R;
		}
		top_shear(root, curr, tmp);
		tmp->L = curr->L;
		curr->L->P = tmp;
		tmp->colour = curr->colour;
		if (c == 'L')
			tmp = tmp2->L;
		else
			tmp = tmp2->R;
		tmp->P = tmp2;
	}
	else
	{
		tmp = curr->P;
		c = ft_child(curr);
		top_shear(root, curr, nil);
		if (c == 'L')
			tmp = tmp->L;
		else
			tmp = tmp->R;
	}
	if (curr->colour == black)
		delete_fix(tmp, dis->nil);
	if (free_fct)
		free_fct(curr);
} 
