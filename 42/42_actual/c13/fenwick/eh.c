#include <unistd.h>
#include <stdlib.h>

void	ft_add(int src, int *output, int index, int size)	//toss new number to end of list
{
	while (index < size)	//first number immediately affects index 1, 2, 4, 8, 16, ....
	{
		output[index] += src;
		index += index & -index;
	}
}

void	ft_putnbr(int n)
{
	int t = 1;
	char a;

	if (n < 0)
	{
		write(1, "-", 1);
		n = 0 - n;
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

int		ft_atoi(char *v, int *input, int index)
{
	int i = 0;
	int a = 0;
	int flag = 1;

	if (v[i] == '-')
	{
		flag = -1;
		i ++;
	}
	while (v[i])
	{
		if (v[i] < 48 || v[i] > 57)
			return (1);
		a *= 10;
		a += v[i] - 48;
		i ++;
	}
	input[index] = a * flag;
	return (0);
}

int		ft_sum(int *output, int index)	//grab sum
{
	int i = 0;
	while (index > 0)
	{
		i += output[index];
		index -= index & -index;
	}
	return (i);
}

int		main(int c, char **v)	//do prefix sums
{
	if (c < 2)
		return (1);
	int *input = malloc(c * sizeof(int));
	int *output = malloc(c * sizeof(int));

	int i = 1;
	while (i < c)
	{
		if (ft_atoi(v[i], input, i))
			return (1);
		i ++;
	}
	i = 1;
	while (i < c)
	{
		ft_add(input[i], output, i, c);
		i ++;
	}
	/*
	i = 1;
	while (i < c)
	{
		ft_putnbr(output[i]);
		i ++;
		if (i < c)
			write(1, ", ", 2);
	}
	*/

	ft_putnbr(ft_sum(output, 5));
	free(input);
	free(output);
	write(1, "\n", 1);
}
