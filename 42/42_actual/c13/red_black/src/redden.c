#include "rb.h"

void	redden(node *a, tree *dis, int flag)
{
	if (flag)
		a->C = red;
	if (a == *dis->root || a == dis->nil)
		a->C = black;
}
