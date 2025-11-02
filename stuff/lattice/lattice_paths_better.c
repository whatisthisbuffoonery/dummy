#include <unistd.h>

void				ft_putnbr(int n)
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

int					binomial_crinj(int n)
{
	int i = 1;
	int result = 1;

	while (i <= n)
	{
		result *= (n + i);
		result /= i;
		i ++;
	}
	return (result);
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
	int b = binomial_crinj(a);
	ft_putnbr(b);
	write(1, "\n", 1);
}
