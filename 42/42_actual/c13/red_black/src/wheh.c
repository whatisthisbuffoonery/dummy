#include "rb.h"
	
void	btree_insert_data(tree *dis, void *data, int (*cmpf)(void *, void*), int b[]);
int		btree_level_count(tree *dis);
void	btree_infix(node *root, node *nil, int k);
node	*btree_create_node(void *data, node *nil);
node	*btree_search(tree *dis, void *data, int (cmp)(void *, void *));
void	btree_delete(tree *dis, node *curr, void (*free_fct)(node *));

int		ft_strcmp(void *a, void *b)
{
	char *s1 = (char *)a;
	char *s2 = (char *)b;

	int i = 0;

	while (s1[i] && s1[i] == s2[i])
		i ++;
	return (s1[i] - s2[i]);
}

void	ft_putnbr(int n)
{
	int t = 1;
	char a;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	while (n / t > 9)
		t *= 10;
	while (t)
	{
		a = ((n / t) % 10) + 48;
		write(1, &a, 1);
		t /= 10;
	}
}

void	ft_putstr(char *a)
{
	int i = 0;
	while (a[i])
		i ++;
	write(1, a, i);
}

int		ft_atoi(char *c)
{
	int i = 0;
	int flag = 1;
	int a = 0;
	if (c[i] == '-')
	{
		i ++;
		flag = -1;
	}
	while (c[i])
	{
		a *= 10;
		a += c[i] - 48;
		i ++;
	}
	return (a * flag);
}

int		int_cmp(void *a, void *b)
{
	return (ft_atoi((char *)a) - ft_atoi((char *)b));
}

int		main(int c, char **v)
{
	if (c < 2)
		return (1);
	int i = 1;
	int b[2] = {0, 0};
	node *dumdum = btree_create_node(0, (void *)"pootis");
	node *a = dumdum;
	tree *dis = malloc(sizeof(tree*));
	dis->root = &a;
	dis->nil = dumdum;
	node *del;
	while (i < c && v[i][0] != '|')
	{
		btree_insert_data(dis, (void *)v[i], int_cmp, b);
		i ++;
	}
	i ++;
	while (i < c)
	{
		write(1, "\n---\ndel", 8);
		ft_putstr(v[i]);
		write(1, "\n", 1);
		del = btree_search(dis, (void *)v[i], int_cmp);
		if (!del)
		{
			write(1, "bomb out\n", 9);
			return (1);
		}
		btree_delete(dis, del, 0);
		btree_infix(*dis->root, dis->nil, 1);
		i ++;
	}
	write(1, "\n---\n", 5);
	ft_putnbr(btree_level_count(dis));
	write(1, "\n", 1);
	//btree_suffix(dis, 1);
	write(1, "turns: ", 7);
	ft_putnbr(b[0]);
	write(1, "\nrecolours: ", 12);
	ft_putnbr(b[1]);
	write(1, "\n", 1);
}
