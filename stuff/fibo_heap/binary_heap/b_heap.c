#include <unistd.h>
#include <stdlib.h>

int		ft_atoi(char *v)
{
	int a = 0;
	int i = 0;
	int flag = 1;

	if (v[i] == '-')
	{
		i ++;
		flag = -1;
	}

	while (v[i])
	{
		if (v[i] > 47 && v[i] < 58)
		{
			a *= 10;
			a += v[i] - 48;
		}
		i ++;
	}
	return (a * flag);
}

void	ft_swap(int *a, int *b)
{
	int i = *a;
	*a = *b;
	*b = i;
}

void	fixup(int output[], int index, int k)
{
	while (k < index)
	{
		if (output[index] >= output[k])
			return;
		ft_swap(&output[index], &output[k]);
		index = k;
		k = (index - 1) / 2;
	}
}

void	insert(int output[], int src, int index)
{
	output[index] = src;
	fixup(output, index, (index - 1) / 2);
}

void	ft_putnbr(int n)
{
	int t = 1;
	char a;

	while (n / t > 9)
		t *= 10;
	while (t)
	{
		a = ((n / t) % 10) + 48;
		write(1, &a, 1);
		t /= 10;
	}
}

void	heap_prefix(int output[], int index, int level, int size)
{
	int i = 1;
	int k = index * 2;
	while (i < level)
	{
		write(1, "    ", 4);
		i ++;
	}
	ft_putnbr(output[index]);
	write(1, "\n", 1);
	if (k + 1 < size)
		heap_prefix(output, k + 1, level + 1, size);
	if (k + 2 < size)
		heap_prefix(output, k + 2, level + 1, size);
}

int		main(int c, char **v)
{
	if (c < 2)
		return (1);
	int size = c - 1;
	int *input = malloc(size * sizeof(int));
	int *output = malloc(size * sizeof(int));
	int i = 0;
	while (i < size)
	{
		input[i] = 0;
		output[i] = 0;
		i ++;
	}
	i = 0;
	while (++i < c)
		input[i - 1] = ft_atoi(v[i]);
	i = -1;
	while (++i < size)
		insert(output, input[i], i);
	heap_prefix(output, 0, 1, c);
}
