#include "rb.h"

node	*btree_create_node(void *data, node *nil)
{
	node *a = malloc(sizeof(node));
	a->L = nil;
	a->R = nil;
	a->P = nil;
	a->C = red;
	if (!nil)
	{
		a->C = black;
		a->L = a;
		a->R = a;
		a->P = a;
	}
	a->data = data;
	return (a);
}
