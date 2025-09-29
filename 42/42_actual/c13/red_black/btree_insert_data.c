#include "rb.h"

node	*btree_create_node(void *data);

void	btree_insert_data(node **root, void *data, int (*cmpf)(void *, void*))
{
	node *a = btree_create_node(data);
	node *curr = *root;
	while (curr)
	{
		if (cmpf(
