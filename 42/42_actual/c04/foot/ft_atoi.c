#include <unistd.h>

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

int main(void)
{
	char c = ft_atoi("9") + 48;
	write(1, &c, 1);
	write(1, "\n", 1);
}
