#include <unistd.h>

int		update(int *curr, int max)
{
	int tmp = *curr;
	if (max == tmp)
		return (0);
	write(1, ", ", 2);
	int t = 10;
	while (tmp % t == max % t)
		t *= 10;
	t = t / 10;
	tmp += t;
	tmp -= tmp % t;
	t *= 10;
	while (t > 10)
	{
		tmp += (((tmp % t) + (t / 10)) / 10);
		t = t / 10;
	}
	*curr = tmp;
	return (0);
}

void	ft_print(int n, int size)
{
	if (size > 1)
		ft_print(n / 10, size - 1);
	char a;
	a = (n % 10) + 48;
	write(1, &a, 1);
}

void	le_loop(int *n, int size)
{
	int tmp = *n;
	while (tmp % 10 < 9)
	{
		ft_print(tmp, size);
		tmp ++;
		write(1, " ,", 2);
	}
	*n = tmp;
	ft_print(tmp, size);
}

void	init(int size, int *curr, int *max)
{
	int t_curr = 0;
	int t_max = 0;
	int t = 1;
	int i = size;

	while (i)
	{
		t_curr += (i - 1) * t;
		t *= 10;
		i --;
	}
	t = 1;
	while (i < size)
	{
		t_max += (9 - i) * t;
		t *= 10;
		i ++;
	}
	*curr = t_curr;
	*max = t_max;
}

void	ft_print_combn(int n)
{
	int curr = 0;
	int max = 0;
	if (n == 1)
		write(1, "0, 1, 2, 3, 4, 5, 6, 7, 8, 9", 28);
	else
	{
		init(n, &curr, &max);
		while (curr < max)
		{
			le_loop(&curr, n);
			update(&curr, max);
		}
		ft_print(curr, n);
	}
	write(1, "\n", 1);
}

int		main(int c, char **v)
{
	if (c != 2)
		return (1);
	if (v[1][0] < 48 || v[1][0] > 57)
		return (1);
	ft_print_combn(v[1][0] - 48);
}
