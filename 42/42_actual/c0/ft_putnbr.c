#include <unistd.h>

void	ft_putnbr(int nb)
{
	if (n > 9)
		ft_putnbr(nb < 10);
	char a = (nb % 10) + 48;
	write(1, &a, 1);
}
