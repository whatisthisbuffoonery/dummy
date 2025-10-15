#include "rb.h"

void	left_rotate(node **root, node *nil, node *x)
{
	node *y = nil;
	if (x != nil)
		y = x->R;
	if (y != nil)
	{
		if (x->P != nil)
		{
			if (x->P->L == x)
				x->P->L = y;
			else
				x->P->R = y;
		}
		if (x->P == nil)
			*root = y;
		y->P = x->P;
		x->P = y;
		x->R = y->L;
		if (y->L != nil)
			y->L->P = x;
		y->L = x;
	}
}

void	right_rotate(node **root, node *nil, node *x)
{
	node *y = nil;
	if (x != nil)
		y = x->L;
	if (y != nil)
	{
		if (x->P != nil)
		{
			if (x->P->L == x)
				x->P->L = y;
			else
				x->P->R = y;
		}
		if (x->P == nil)
			*root = y;
		y->P = x->P;
		x->P = y;
		x->L = y->R;
		if (y->R != nil)
			y->R->P = x;
		y->R = x;
	}
}

void	ft_putstr(char *a);

void	rotate_mux(tree *dis, node *x, char a)
{
	if (a == 'L')
		left_rotate(dis->root, dis->nil, x);
	if (a == 'R')
		right_rotate(dis->root, dis->nil, x);
	write(1, "\n", 1);
	write(1, &a, 1);
	write(1, ", ", 2);
	ft_putstr(x->data);
	write(1, "\n", 1);
}
