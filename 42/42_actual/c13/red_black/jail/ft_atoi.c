int		ft_atoi(char *str)
{
	int flag = 0;
	int a = 0;
	int i = 0;

	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i ++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag ++;
		i ++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		a *= 10;
		a += str[i] - 48;
		i ++;
	}
	if (flag % 2)
		a = 0 - a;
	return (a);
}

int		int_cmp(void *a, void *b)
{
	return (ft_atoi((char *)a) - ft_atoi((char *)b));
}

#include <unistd.h>

void	ft_putnbr(int n)
{
	int t = 1;
	char a;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
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

int main(int c, char **v)
{
	if (c < 2)
		return (1);
	ft_putnbr(int_cmp((void *)v[1], (void *)v[2]));
	write(1, "\n", 1);
}
