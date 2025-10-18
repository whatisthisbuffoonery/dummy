#include "rb.h"

char	ft_child(node *a);
void	rotate_mux(tree *dis, node *x, char a);

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

void	delete_fix_left(node *a, tree *dis)
{
	node *sibling;
	while (a != *dis->root)
	{
		sibling = a->P->R;
		if (sibling->colour == red)
		{
			sibling->colour = black;
			a->P->colour = red;
			a = a->P;
			rotate_mux(dis, a, 'L');
		}
		if (sibling->colour == black)
		{
			if (sibling->L->colour == black && sibling->R->colour == black)
			{
				a = a->P;
				sibling->colour = red;
				continue;
			}
			if (sibling->L->colour == red && sibling->R->colour == black)
			{
				sibling->L->colour = black;
				sibling->colour = red;
				rotate_mux(dis, sibling, 'R');
				sibling = a->P->R;
			}
			sibling->colour = a->P->colour;
			a->P->colour = black;
			sibling->R->colour = black;
			rotate_mux(dis, a->P, 'L');
			return;
		}
		(*dis->root)->colour = black;
	}
}

void	delete_fix_right(node *a, tree *dis)
{
	node *sibling;
	while (a != *dis->root)
	{
		sibling = a->P->L;
		if (sibling->colour == red)
		{
			sibling->colour = black;
			a->P->colour = red;
			a = a->P;
			rotate_mux(dis, a, 'R');
		}
		if (sibling->colour == black)
		{
			if (sibling->L->colour == black && sibling->R->colour == black)
			{
				a = a->P;
				sibling->colour = red;
				continue;
			}
			if (sibling->L->colour == black && sibling->R->colour == red)
			{
				sibling->R->colour = black;
				sibling->colour = red;
				rotate_mux(dis, sibling, 'L');
				sibling = a->P->L;
			}
			sibling->colour = a->P->colour;
			a->P->colour = black;
			sibling->L->colour = black;
			rotate_mux(dis, a->P, 'R');
			return;
		}
		(*dis->root)->colour = black;
	}
}

void	delete_mux(node *a, lmao colour, tree *dis)
{
	if (a == dis->nil)
	{
		if (a->P == dis->nil)
			return;
	}
	if (colour == red)
		a->colour = black;
	else if (ft_child(a) == 'R')
		delete_fix_right(a, dis);
	else
		delete_fix_left(a, dis);
}

void	btree_delete(tree *dis, node *curr, void (*free_fct)(node *))
{
	node *nil = dis->nil;
	node *tmp = curr->P;
	node *tmp2 = nil;
	lmao cache;
	char c;
	if (dis->nil->colour == red)
		write(1, "poopoo\n", 7);
	if (curr->R != nil && curr->L == nil)
	{
		tmp = curr->R;
		cache = tmp->colour;
		top_shear(dis, curr, curr->R);
	}
	else if (curr->L != nil && curr->R == nil)
	{
		tmp = curr->L;
		cache = tmp->colour;
		top_shear(dis, curr, curr->L);
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
		cache = tmp->colour;
		top_shear(dis, tmp, tmp->R);
		if (tmp != curr->R)
		{
			curr->R->P = tmp;
			tmp->R = curr->R;
		}
		top_shear(dis, curr, tmp);
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
		top_shear(dis, curr, nil);
		if (c == 'L')
			tmp = tmp->L;
		else
			tmp = tmp->R;
		cache = black;
	}
	if (curr->colour == black)
		delete_mux(tmp, cache, dis);
	if (free_fct)
		free_fct(curr);
} 
