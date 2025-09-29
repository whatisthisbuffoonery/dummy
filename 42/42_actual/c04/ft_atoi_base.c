#include <unistd.h>
#include <stdio.h>

int		check(char *base, int *n, char (*b)[])
{
	int i = -1;

	while (++i < 128)
		(*b)[i] = 0;
	i = 0;
	while (base[i])
	{
		*n += 1;
		if (base[i] == '+' || base[i] == '-')
			return (1);
		if ((*b)[(unsigned char)base[i]])
			return (1);
		else
			(*b)[(unsigned char)base[i]] += *n;
		i ++;
	}
	if (*n < 2)
		return (1);
	return (0);
}

int		ft_atoi_base(char *str, char *base)
{
	int n = 0;
	char b[129];
	if (check(base, &n, &b))
		return (0);
	int i = 0;
	int a = 0;
	int flag = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i ++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag ++;
		i ++;
	}
	while (b[(unsigned char)str[i]])
	{
		a *= n;
		a += b[(unsigned char)str[i]] - 1;
		i ++;
	}
	if (flag % 2)
		a = 0 - a;
	return (a);
}

int		main(void)
{
	int a = ft_atoi_base("ff", "0123456789abcdef");
	printf("%d", a);
	printf("\n");
}
