#include "rb.h"

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

void	delete_fix_left(node *a, tree *dis, int b[], int verbose)
{
	node *sibling;
	while (a != *dis->root)
	{
		sibling = a->P->R;
		if (sibling->C == red)
		{
			b[1] += 1;
			b[0] += 1;
			sibling->C = black;
			redden(a->P, dis, 1);//a->P->colour = red;
			a = a->P;
			rotate_mux(dis, a, 'L', verbose);
		}
		if (sibling->C == black)
		{
			if (sibling->L->C == black && sibling->R->C == black)
			{
				b[1] += 1;
				a = a->P;
				redden(sibling, dis, 1);//sibling->colour = red;
				continue;
			}
			if (sibling->L->C == red && sibling->R->C == black)
			{
				b[1] += 1;
				b[0] += 1;
				sibling->L->C = black;
				redden(sibling, dis, 1);//sibling->colour = red;
				rotate_mux(dis, sibling, 'R', verbose);
				sibling = a->P->R;
			}
			b[1] += 1;
			b[0] += 1;
			sibling->C = a->P->C;
			redden(sibling, dis, 0);
			a->P->C = black;
			sibling->R->C = black;
			rotate_mux(dis, a->P, 'L', verbose);
			return;
		}
		(*dis->root)->C = black;
	}
}

void	delete_fix_right(node *a, tree *dis, int b[], int verbose)
{
	node *sibling;
	while (a != *dis->root)
	{
		sibling = a->P->L;
		if (sibling->C == red)
		{
			b[1] += 1;
			b[0] += 1;
			sibling->C = black;
			redden(a->P, dis, 1);//a->P->colour = red;
			a = a->P;
			rotate_mux(dis, a, 'R', verbose);
		}
		if (sibling->C == black)
		{
			if (sibling->L->C == black && sibling->R->C == black)
			{
				b[1] += 1;
				a = a->P;
				redden(sibling, dis, 1);//sibling->colour = red;
				continue;
			}
			if (sibling->L->C == black && sibling->R->C == red)
			{
				b[1] += 1;
				b[0] += 1;
				sibling->R->C = black;
				redden(sibling, dis, 1);//sibling->colour = red;
				rotate_mux(dis, sibling, 'L', verbose);
				sibling = a->P->L;
			}
			b[1] += 1;
			b[0] += 1;
			sibling->C = a->P->C;
			a->P->C = black;
			redden(sibling, dis, 0);
			sibling->L->C = black;
			rotate_mux(dis, a->P, 'R', verbose);
			return;
		}
		(*dis->root)->C = black;
	}
}

void	prompt(node *a)
{
	ft_putstr((char *)a->data);
	if (a->C == red)
		write(1, "R\n", 2);
	else
		write(1, "B\n", 2);
}

void	delete_mux(node *a, colour cache, tree *dis, int b[], int verbose)
{
	if (verbose)
	{
		write(1, "replacement: ", 13);
		prompt(a);
		write(1, "\n", 1);
	}
	if (a == dis->nil)
	{
		if (a->P == dis->nil)
			return;
	}
	if (cache == red)
	{
		b[1] += 1;
		a->C = black;
	}
	else if (ft_child(a) == 'R')
		delete_fix_right(a, dis, b, verbose);
	else
		delete_fix_left(a, dis, b, verbose);
}

void	btree_delete(tree *dis, node *curr, void (*free_fct)(node *), int b[], int verbose)
{
	node *nil = dis->nil;
	node *tmp = curr->P;
	node *tmp2 = nil;
	colour cache;
	char c;
	if (dis->nil->C == red)
		write(1, "poopoo\n", 7);
	if (verbose)
		prompt(curr);
	if (curr->R != nil && curr->L == nil)
	{
		if (verbose)
			write(1, "\nright\n", 7);
		tmp = curr->R;
		cache = tmp->C;
		top_shear(dis, curr, curr->R);
	}
	else if (curr->L != nil && curr->R == nil)
	{
		if (verbose)
			write(1, "\nleft\n", 6);
		tmp = curr->L;
		cache = tmp->C;
		top_shear(dis, curr, curr->L);
	}
	else if (curr->L != nil && curr->R != nil)
	{
		if (verbose)
			write(1, "\nboth\n", 6);
		tmp = curr->R;
		while (tmp->L != nil)
			tmp = tmp->L;
		tmp2 = tmp->P;
		if (tmp == curr->R)
			tmp2 = tmp;
		c = ft_child(tmp);
		cache = tmp->C;
		top_shear(dis, tmp, tmp->R);
		if (tmp != curr->R)
		{
			curr->R->P = tmp;
			tmp->R = curr->R;
		}
		top_shear(dis, curr, tmp);
		tmp->L = curr->L;
		curr->L->P = tmp;
		tmp->C = curr->C;
		b[1] += 1;
		if (c == 'L')
			tmp = tmp2->L;
		else
			tmp = tmp2->R;
		tmp->P = tmp2;
	}
	else
	{
		if (verbose)
			write(1, "\nneither\n", 9);
		tmp = curr->P;
		c = ft_child(curr);
		top_shear(dis, curr, nil);
		if (c == 'L')
			tmp = tmp->L;
		else
			tmp = tmp->R;
		cache = black;
	}
	if (curr->C == black)
		delete_mux(tmp, cache, dis, b, verbose);
	if (free_fct)
		free_fct(curr);
	nil->P = nil;
	nil->L = nil;
	nil->R = nil;
	if (verbose)
		write(1, "\n", 1);
} 
