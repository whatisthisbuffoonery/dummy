#include "rb.h"

void	ft_putnbr(int n);
int		ft_atoi(char *);

node	*btree_search(tree *dis, void *data, int (cmp)(void *, void *))
{
	int compare;
	node *a = *dis->root;
	while (a != dis->nil)
	{
		write(1, "compare ", 8);
		ft_putnbr(ft_atoi(data));
		write(1, " minus ", 7);
		ft_putnbr(ft_atoi(a->data));
		write(1, "\n", 1);
		compare = cmp(data, a->data);
		if (compare < 0)
			a = a->L;
		if (compare > 0)
			a = a->R;
		if (compare == 0)
			return (a);
	}
	return (0);
}
