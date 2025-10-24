#include <unistd.h>

void	ft_putstr(char *a)
{
	int i = 0;

	while(a[i])
		i ++;
	write(1, a, i);
}

void	ft_putnbr(int n)
{
	int t = 1;
	char a;

	while(n / t > 9)
		t *= 10;
	while(t)
	{
		a = ((n / t) % 10) + 48;
		write(1, &a, 1);
		t /= 10;
	}
}

int		assert(int a, int line, char *err)
{
	if(!a)
	{
		ft_putstr(__FILE__);
		write(1, ":", 1);
		ft_putnbr(line);
		write(1, ": assertion failed: ", 20);
		ft_putstr(err);
		write(1, "\n", 1);
		return (1);
	}
	return (0);
}

int		main(void)
{
	int i = 1;
	assert(i > 10, __LINE__, "i aint bigger than 10");
}
