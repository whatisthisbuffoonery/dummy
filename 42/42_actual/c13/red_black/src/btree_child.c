#include "rb.h"

char	ft_child_not(node *a)
{
	if (!a || !(a->P))
		return (0);
	if (a == a->P->L)
		return ('R');
	if (a == a->P->R)
		return ('L');
	return ('N');
}

char	ft_child(node *a)
{
	if (!a || !(a->P))
		return (0);
	if (a == a->P->L)
		return ('L');
	if (a == a->P->R)
		return ('R');
	return ('N');
}
