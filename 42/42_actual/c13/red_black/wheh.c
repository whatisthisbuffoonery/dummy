#include <unistd.h>
#include <stdlib.h>
#include "rb.h"

int		ft_strcmp(void *a, void *b)
{
	char *s1 = (char *)a;
	char *s2 = (char *)b;

	int i = 0;

	while (s1[i] && s1[i] == s2[i])
		i ++;
	return (s1[i] - s2[i]);
}

int		main(int c, char **v)
{
	if (c < 2)
		return (1);
	int i = 1;
	node *a = NULL;
	while (i < c)
	{
		btree_insert_data(&a, (void *)v[i], ft_strcmp);
		i ++;
	}
}
