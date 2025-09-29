#include <unistd.h>

int		straight(int a[], int index)
{
	int i = 0;
	int b[10];

	while (i < 10)
		b[i++] = 0;

	i = 0;
	while (i < index + 1)//yes i added one
	{
		if (b[a[i]])
			return (1);
		else
			b[a[i]] = 1;
		i ++;
	}
	return (0);
}

int		diag(int a[], int index)
{
	int i = 0;
	int k;

	while (i < index)
	{
		k = i + 1;
		while (k < index + 1)
		{
			if (a[k] == a[i] + (k - i) || a[k] == a[i] - (k - i))
				return (1);
			k ++;
		}
		i ++;
	}
	return (0);
}

void	ft_print(int a[], int *n)
{
	int i = 0;
	char c = 0;

	*n += 1;
	while (i < 10)
	{
		c = a[i] + 48;
		write(1, &c, 1);
		i ++;
	}
	write(1, "\n", 1);
}

void	solve(int a[], int *n, int index)
{
	int value = 0;

	while (value < 10)
	{
		a[index] = value;
		if (index < 9 && !straight(a, index))//lock recursions behind valid current answers
		{
			if(!diag(a, index))//lock this On^2 bih behind bars
				solve(a, n, index + 1);
		}
		if (index == 9 && !straight(a, index))
		{
			if (!diag(a, index))
				ft_print(a, n);
		}
		value ++;
	}
	a[index] = -42;
}

int		ft_ten_queens_puzzle(void)
{
	int n = 0;
	int board[10];
	int i = 0;

	/*
	int straight[10] = {0};
	int diag[19] = {0};			//(10 * 2) - 1 = 19 possible diagonal lines
	int anti_diag[19] = {0};
	*/
	while (i < 10)
		board[i++] = -42;
	solve(board, &n, 0);

	return (n);
}

void	ft_putnbr(int n)
{
	int t = 1;
	char a = 0;

	while (n / t > 9)
		t *= 10;

	while (t)
	{
		a = ((n / t) % 10) + 48;
		write(1, &a, 1);
		t /= 10;
	}
	write(1, "\n", 1);
}

int		main(void)
{
	ft_putnbr(ft_ten_queens_puzzle());
}
