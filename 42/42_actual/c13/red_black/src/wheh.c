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

void	free_func_no_data(node *a)
{
	free(a);
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
	while (c[i] >= '0' && c[i] <= '9' && c[i])
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

int		flag(int *num, char **v)
{
	int c = *num;
	int i = 1;

	while (i < c)
	{
		if (v[i][0] == '-' && v[i][1] == 'v' && v[i][2] == 0)
		{
			while (i < c)
			{
				v[i] = v[i + 1];
				i ++;
			}
			*num -= 1;
			return (1);
		}
		i ++;
	}
	return (0);
}

int		main(int c, char **v)
{
	int i = 1;
	int b[2] = {0, 0};
	int verbose = flag(&c, v);
	if (c < 2)
		return (1);
	node *dumdum = btree_create_node((void *)"pootis\0", 0);
	tree *dis = malloc(sizeof(tree));
	dis->root = &dumdum;
	dis->nil = dumdum;
	node *del;
	while (i < c && v[i][0] != '|')
	{
		btree_insert_data(dis, (void *)v[i], int_cmp, b, verbose);
		i ++;
	}
	i ++;
	if (!verbose)
		btree_prefix(*dis->root, dis->nil, 1);
	write(1, "\n---\n", 5);
	ft_putnbr(btree_level_count(dis));
	write(1, "\n", 1);
	write(1, "turns: ", 7);
	ft_putnbr(b[0]);
	write(1, "\nrecolours: ", 12);
	ft_putnbr(b[1]);
	write(1, "\n", 1);
	b[0] = 0;
	b[1] = 0;
	while (i < c)
	{
		verbose = -1;
		write(1, "\n-------\ndel", 12);
		ft_putstr(v[i]);
		write(1, "\n", 1);
		del = btree_search(dis, (void *)v[i], int_cmp);
		if (!del)
		{
			write(1, "bomb out\n", 9);
			i ++;
			continue;
		}
		btree_delete(dis, del, free_func_no_data, b);
		btree_prefix(*dis->root, dis->nil, 1);
		i ++;
	}
	if (verbose == -1)
	{
		write(1, "\n-------\n", 9);
		ft_putnbr(btree_level_count(dis));
		write(1, "\n", 1);
		write(1, "turns: ", 7);
		ft_putnbr(b[0]);
		write(1, "\nrecolours: ", 12);
		ft_putnbr(b[1]);
		write(1, "\n", 1);
	}

//	while (*dis->root != dis->nil)
//		btree_delete(dis, *dis->root, free_func_no_data, b);
//	free(dis->nil);
//	free(dis);
	btree_clear(dis);
}
