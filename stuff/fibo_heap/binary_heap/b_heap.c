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

void	fixdown(int output[], int size)
{
	int i = 0;
	int k = 0;
	while ((2 * i) + 2 < size)
	{
		k = 2 * i;
		if (output[i] > output[k + 1])
		{
			if (output[k + 1] > output[k + 2])
			{
				ft_swap(&output[i], &output[k + 2]);
				i = k + 2;
				continue;
			}
			ft_swap(&output[i], &output[k + 1]);
			i = k + 1;
		}
		else if (output[i] > output[k + 2])
		{
			ft_swap(&output[i], &output[k + 2]);
			i = k + 2;
		}
		else
			return;
	}
	k = 2 * i + 1;
	if (size - (2 * i) > 0 && output[i] > output[k])
		ft_swap(&output[i], &output[k]);
}

void	heap_pop(int output[], int *size)
{
	*size -= 1;
	output[0] = output[*size];
	output[*size] = 0;
	fixdown(output, *size);
}

void	plain(int output[], int size)
{
	int i = 0;
	while (i < size)
		ft_putnbr(output[i++]);
	write(1, "\n", 1);
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
	heap_prefix(output, 0, 1, size);
	plain(output, size);
	heap_pop(output, &size);
	write(1, "\n---\n", 5);
	heap_prefix(output, 0, 1, size);
	plain(output, size);
	free(input);
	free(output);
}
