#include <unistd.h>

int		check(char *base, int *n)
{
	int i = -1;
	char a[129];

	while (++i < 128)
		a[i] = 0;
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		if (a[base[i]])
			return (1);
		else
			a[base[i]] = 1;
		i ++;
		*n += 1;
	}
	if (*n < 2)
		return (1);
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int n = 0;
	int t = 1;
	char a = 0;
	if (!check(base, &n))
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr = 0 - nbr;
		}
		while (nbr / t > n - 1)
			t *= n;
		while (t)
		{
			a = base[((nbr / t) % n)];
			write(1, &a, 1);
			t /= n;
		}
	}
}
