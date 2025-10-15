#include "rb.h"

node	*btree_create_node(void *data, node *nil)
{
	node *a = malloc(sizeof(node));
	a->L = nil;
	a->R = nil;
	a->P = nil;
	a->colour = red;
	if (!nil)
		a->colour = black;
	a->data = data;
	return (a);
}
