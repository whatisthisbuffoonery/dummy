#include "rb.h"

void	redden(node *a, tree *dis, int flag)
{
	if (flag)
		a->colour = red;
	if (a == *dis->root || a == dis->nil)
		a->colour = black;
}
