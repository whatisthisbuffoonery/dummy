#include "rb.h"
#include <stdlib.h>

node	*btree_create_node(void *data)
{
	node *a = malloc(sizeof(node));
	a->L = NULL;
	a->R = NULL;
	a->color = red;
	a->data = data;
	return (a);
}
