#include <unistd.h>

int ft_atoi(char *v)
{
	int i = 0;
	int a = 0;
	int flag = 0;
	while (v[i] == 32 || (v[i] > 8 && v[i] < 14))
		i ++;
	while (v[i] == '-' || v[i] == '+')
	{
		if (v[i] == '-')
			flag ++;
		i ++;
	}
	while (v[i] > 47 && v[i] < 58)
	{
		a *= 10;
		a += v[i] - 48;
		i ++;
	}
	if (flag % 2)
		a = 0 - a;
	return (a);
}

int		ft_math(int a, int b, char op, int *complain)
{
	if (!b)
	{
		if (op == '/')
			write(1, "Stop : division by zero\n", 24);
		if (op == '%')
			write(1, "Stop : modulo by zero\n", 22);
		*complain = 1;
		return (0);
	}
	if (op == '/')
		return (a / b);
	if (op == '%')
		return (a % b);
	return (-42);
}

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
	write(1, "\n", 1);
}

int		main(int c, char **v)
{
	if (c != 4)
		return (1);
	int complain = 0;
	int a = ft_atoi(v[1]);
	int b = ft_atoi(v[3]);
	char op = v[2][0];
	int result = 0;
	if (op == '+')
		result = a + b;
	if (op == '-')
		result = a - b;
	if (op == '*')
		result = a * b;
	if (op == '%' || op == '/')
		result = ft_math(a, b, op, &complain);
	if (!complain)
		ft_putnbr(result);
}
