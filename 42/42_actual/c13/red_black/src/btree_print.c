#include "rb.h"

void	muh_prefix(int *i, int k, node *a, node *nil)
{
	if (a != nil)
		k ++;
	if (k > *i)
		*i = k;
	if (a != nil)
	{
		muh_prefix(i, k, a->L, nil);
		muh_prefix(i, k, a->R, nil);
	}
}

int		btree_level_count(tree *dis)
{
	int i = 0;
	node *root = *dis->root;
	muh_prefix(&i, 0, root, dis->nil);
	return (i);
}

void	btree_prefix(node *root, node *nil, int k)
{
	char c;
	int i = 1;
	if (root != nil)
	{
		c = ft_child(root);
		if (c != 'N')
			write(1, &c, 1);
		while (i < k)
		{
			write(1, "    ", 4);
			i ++;
		}
		ft_putstr((char *)root->data);
		if (root->C == red)
			write(1, "R", 1);
		else
			write(1, "B", 1);
		write(1, " (", 2);
		ft_putnbr(k);
		write(1, ")", 1);
		/*
		if (root->P)
		{
			write(1, " P->", 4);
			ft_putstr((char *)root->P->data);
		}
		*/
		write(1, "\n", 1);
	}
	if (root->L != nil)
		btree_prefix(root->L, nil, k + 1);
	if (root->R != nil)
		btree_prefix(root->R, nil, k + 1);
}
