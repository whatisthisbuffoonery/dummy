#include "ft_stock_str.h"

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

void	ft_show_tab(struct s_stock_str *par)
{
	int i = 0;

	while (par[i].size)
	{
		write(1, par[i].str, par[i].size);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		write(1, par[i].copy, par[i].size);
		write(1, "\n", 1);
		i ++;
	}
}
