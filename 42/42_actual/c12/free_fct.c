#include "ft_list.h"

void	ft_elem_free(void *a)
{
	if (a)
		free(a);
}
