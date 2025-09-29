#include <unistd.h>

void	ft_print(int *i)
{
	char	a;
	int		n = *i;

	a = (n / 100) + 48;
	write(1, &a, 1);
	a = ((n % 100) / 10) + 48;
	write(1, &a, 1);
	a = (n % 10) + 48;
	write(1, &a, 1);
	write(1, "\n", 1);
}

void	le_loop(int *n)
{
	while (*n % 10 < 9)
	{
		ft_print(n);
		*n += 1;
	}
	ft_print(n);
}

void	ft_print_comb(void)
{
	int	n = 12;

	while (n < 789)
	{
		le_loop(&n);
		if (n % 100 == 89)
		{
			n += 100;
			n -= 89;
			n += (n / 10) + 10;
			n += (n / 100) + 2;
		}
		else
		{
			n += 10;
			n -= 9;
			n += ((n % 100) / 10) + 1;
		}
	}
	ft_print(&n);
}

int main(void)
{
	ft_print_comb();
}
