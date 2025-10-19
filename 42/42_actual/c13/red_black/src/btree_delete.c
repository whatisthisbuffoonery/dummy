#include "rb.h"

char	ft_child(node *a);
void	rotate_mux(tree *dis, node *x, char a);
void	ft_putstr(char *a);
void	redden(node *a, tree *dis, int flag);

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

void	delete_fix_left(node *a, tree *dis, int b[])
{
	node *sibling;
	while (a != *dis->root)
	{
		sibling = a->P->R;
		if (sibling->colour == red)
		{
			b[1] += 1;
			b[0] += 1;
			sibling->colour = black;
			//a->P->colour = red;
			redden(a->P, dis, 1);
			a = a->P;
			rotate_mux(dis, a, 'L');
		}
		if (sibling->colour == black)
		{
			if (sibling->L->colour == black && sibling->R->colour == black)
			{
				b[1] += 1;
				a = a->P;
				//sibling->colour = red;
				redden(sibling, dis, 1);
				continue;
			}
			if (sibling->L->colour == red && sibling->R->colour == black)
			{
				b[1] += 1;
				b[0] += 1;
				sibling->L->colour = black;
				redden(sibling, dis, 1);
				//sibling->colour = red;
				rotate_mux(dis, sibling, 'R');
				sibling = a->P->R;
			}
			b[1] += 1;
			b[0] += 1;
			sibling->colour = a->P->colour;
			redden(sibling, dis, 0);
			a->P->colour = black;
			sibling->R->colour = black;
			rotate_mux(dis, a->P, 'L');
			return;
		}
		(*dis->root)->colour = black;
	}
}

void	delete_fix_right(node *a, tree *dis, int b[])
{
	node *sibling;
	while (a != *dis->root)
	{
		sibling = a->P->L;
		if (sibling->colour == red)
		{
			b[1] += 1;
			b[0] += 1;
			sibling->colour = black;
			redden(a->P, dis, 1);
			//a->P->colour = red;
			a = a->P;
			rotate_mux(dis, a, 'R');
		}
		if (sibling->colour == black)
		{
			if (sibling->L->colour == black && sibling->R->colour == black)
			{
				b[1] += 1;
				a = a->P;
				redden(sibling, dis, 1);
				//sibling->colour = red;
				continue;
			}
			if (sibling->L->colour == black && sibling->R->colour == red)
			{
				b[1] += 1;
				b[0] += 1;
				sibling->R->colour = black;
				redden(sibling, dis, 1);
				//sibling->colour = red;
				rotate_mux(dis, sibling, 'L');
				sibling = a->P->L;
			}
			b[1] += 1;
			b[0] += 1;
			sibling->colour = a->P->colour;
			a->P->colour = black;
			redden(sibling, dis, 0);
			sibling->L->colour = black;
			rotate_mux(dis, a->P, 'R');
			return;
		}
		(*dis->root)->colour = black;
	}
}

void	prompt(node *a)
{
	ft_putstr((char *)a->data);
	if (a->colour == red)
		write(1, "R\n", 2);
	else
		write(1, "B\n", 2);
}

void	delete_mux(node *a, lmao colour, tree *dis, int b[])
{
	write(1, "replacement: ", 13);
	prompt(a);
	write(1, "\n", 1);
	if (a == dis->nil)
	{
		if (a->P == dis->nil)
			return;
	}
	if (colour == red)
	{
		b[1] += 1;
		a->colour = black;
	}
	else if (ft_child(a) == 'R')
		delete_fix_right(a, dis, b);
	else
		delete_fix_left(a, dis, b);
}

void	btree_delete(tree *dis, node *curr, void (*free_fct)(node *), int b[])
{
	node *nil = dis->nil;
	node *tmp = curr->P;
	node *tmp2 = nil;
	lmao cache;
	char c;
	if (dis->nil->colour == red)
		write(1, "poopoo\n", 7);
	prompt(curr);
	if (curr->R != nil && curr->L == nil)
	{
		write(1, "\nright\n", 7);
		tmp = curr->R;
		cache = tmp->colour;
		top_shear(dis, curr, curr->R);
	}
	else if (curr->L != nil && curr->R == nil)
	{
		write(1, "\nleft\n", 6);
		tmp = curr->L;
		cache = tmp->colour;
		top_shear(dis, curr, curr->L);
	}
	else if (curr->L != nil && curr->R != nil)
	{
		write(1, "\nboth\n", 6);
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
		b[1] += 1;
		if (c == 'L')
			tmp = tmp2->L;
		else
			tmp = tmp2->R;
		tmp->P = tmp2;
	}
	else
	{
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
	if (curr->colour == black)
		delete_mux(tmp, cache, dis, b);
	if (free_fct)
		free_fct(curr);
	nil->P = nil;
	nil->L = nil;
	nil->R = nil;
} 
