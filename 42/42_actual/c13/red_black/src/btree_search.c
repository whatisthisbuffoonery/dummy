#include "rb.h"

node	*btree_search(tree *dis, void *data, int (cmp)(void *, void *))
{
	int compare;
	node *a = *dis->root;
	while (a != dis->nil)
	{
		compare = cmp(data, a->data);
		if (compare < 0)
			a = a->L;
		if (compare > 0)
			a = a->R;
		else
			return (a);
	}
	return (0);
}
