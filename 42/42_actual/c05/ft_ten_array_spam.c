#include <unistd.h>

typedef struct {
	int hori[10];
	int diag[19];
	int anti[19];
	int fred;
}		notes;

void	ft_print(int (*a)[], int *n)
{
	int i = 0;
	char c[10];

	*n += 1;
	while (i < 10)
		c[i] = (*a)[i++] + 48;
	write(1, c, i);
	write(1, "\n", 1);
}

void	solve(int (*a)[], int *n, int index, notes *mark)
{
	int value = 0;

	while (value < 10)
	{
		(*a)[index] = value;
		if (index < 9 && !mark->hori[value])
		{
			mark->hori[value] = 1;
			if(!mark->diag[index + value] && !mark->anti[(value - index) + mark->fred])
			{
				mark->diag[index + value] = 1;
				mark->anti[(value - index) + mark->fred] = 1;
				solve(a, n, index + 1, mark);
				mark->diag[index + value] = 0;
				mark->anti[(value - index) + mark->fred] = 0;
			}
			mark->hori[value] = 0;
		}
		if (index == 9 && !mark->hori[value])
		{
			if(!mark->diag[index + value] && !mark->anti[(value - index) + mark->fred])
				ft_print(a, n);
		}
		value ++;
	}
}

int		ft_ten_array_spam(void)//update of 10 queens
{
	int n = 0;
	int board[10];

	//(10 * 2) - 1 = 19 possible diagonal lines

	notes mark = {
		.hori = {0},
		.diag = {0},
		.anti = {0},
		.fred = 10 - 1
	};
	solve(&board, &n, 0, &mark);

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
	ft_putnbr(ft_ten_array_spam());
}
