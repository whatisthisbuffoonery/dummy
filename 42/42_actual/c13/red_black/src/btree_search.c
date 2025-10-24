#include "rb.h"

node	*btree_search(tree *dis, void *data, int (*cmpf)(void *, void *))
{
	int compare;
	node *a = *dis->root;
	while (a != dis->nil)
	{
		compare = cmpf(data, a->data);
		if (compare < 0)
			a = a->L;
		if (compare > 0)
			a = a->R;
		if (compare == 0)
			return (a);
	}
	return (0);
}
