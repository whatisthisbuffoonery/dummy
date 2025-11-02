#include <unistd.h>

unsigned long long	ft_iterative_factorial(int nb)
{
	unsigned long long a = (unsigned long long)nb;

	if (nb < 0)
		return (0);
	if (!nb)
		return (1);
	while (--nb)
		a *= nb;
	return (a);
}

void				ft_putnbr(unsigned long long n)
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

int					ft_atoi(char *src, int *dst)
{
	int i = 0;
	int a = 0;

	while (src[i])
	{
		if (src[i] < 48 || src[i] > 57)
			return (1);
		a *= 10;
		a += src[i] - 48;
		i ++;
	}
	*dst = a;
	return (0);
}

int					main(int c, char **v)
{
	if (c < 2)
		return (1);
	int a = 0;
	if(ft_atoi(v[1], &a))
		return (1);
	if (!a)
		return (1);
	unsigned long long b = ft_iterative_factorial(2 * a);
	unsigned long long c_d = ft_iterative_factorial(a);
	ft_putnbr(b / (c_d * c_d));
	write(1, "\n", 1);
}
