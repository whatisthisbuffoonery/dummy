#include <unistd.h>

void	ft_putnbr(int nb)
{
	int t = 1;
	char a = 0;

	while (nb / t > 9)
		t *= 10;

	while (t)
	{
		a = ((nb / t) % 10) + 48;
		write(1, &a, 1);
		t /= 10;
	}
}

int main(void)
{
	ft_putnbr(1234567890);
	write(1, "\n", 1);
}
