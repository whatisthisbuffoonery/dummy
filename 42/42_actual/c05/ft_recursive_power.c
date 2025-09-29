#include <unistd.h>

int		ft_recursive_power(int nb, int power)
{
	if (!power)
		return (1);
	if (power < 0)
		return (0);
	return (nb * ft_recursive_power(nb, power - 1));
}

int main(void)
{
	char a = ft_recursive_power(2, 3) + 48;
	write(1, &a, 1);
	write(1, "\n", 1);
}
