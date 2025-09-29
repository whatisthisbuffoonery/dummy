#include "ft_list.h"

t_list	*ft_create_elem(void *data);

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list *a = NULL;
	t_list *b = NULL;
	int i = 1;
	if (strs && *strs)
		a = ft_create_elem((void *)strs[0]);
	while (i < size)
	{
		b = ft_create_elem((void *)strs[i]);
		b->next = a;
		a = b;
		i ++;
	}
	return (a);
}
