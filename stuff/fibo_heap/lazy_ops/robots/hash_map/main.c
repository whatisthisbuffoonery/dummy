#include "hash.h"

int		hash(char *v)
{
	int i = 0;
	int a = 0;

	while (v[i])
	{
		a += v[i];
		a *= v[i];
		i ++;
	}
	return (a);
}

void	insert(node_list *a, char *v, int (*h)(char *))
{
	int index = h(v) % a->size;
	if (a->curr == a->size || !a->map[index].nil)
	{};
	curr ++;
}

void	init(node_list *a)
{
	int size = a->size;
	int i = 0;
	node *b;
	while (i < size)
	{
		b = &a->map[i++];
		b->N = 0;
		b->data = 0;
		b->nil = 1;
	}
}

int		main(int c, char **v)
{
	if (c < 2)
		return (1);
	int i = 1;
	node_list a = {10, 0, malloc(10 * sizeof(node))};
	init(&a);

	while (i < c)
		insert(&a, v[i++], hash);
}
