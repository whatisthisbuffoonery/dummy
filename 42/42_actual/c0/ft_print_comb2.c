#include <unistd.h>

void	ft_print(int n)
{
	char a;

	a = (n / 10) + 48;
	write(1, &a, 1);
	a = (n % 10) + 48;
	write(1, &a, 1);
}

void	le_loop(int *t, int *o)
{
	while (*o < 100)
	{
		ft_print(*t);
		write(1, " ", 1);
		ft_print(*o);
		write(1, ", ", 2);
		*o += 1;
	}
}

void	ft_print_comb2(void)
{
	int t = 0;
	int o = 1;

	while (t < 99)
	{
		le_loop(&t, &o);
		t ++;
		o = t + 1;
	}
}

int		main(void)
{
	ft_print_comb2();
	write(1, "\n", 1);
}
