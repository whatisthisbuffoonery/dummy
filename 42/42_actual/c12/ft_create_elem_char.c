#include "ft_list.h"

t_list	*ft_create_elem_char(void *data)
{
	t_list *a = malloc(sizeof(t_list));
	char *src = (char *) data;
	int i = 0;
	while (src[i])
		i ++;
	char *dst = malloc((i + 1) * sizeof(char));
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i ++;
	}
	dst[i] = '\0';
	a->data = dst;
	a->next = NULL;
	return (a);
}
