int		ft_iter_fibonacci(int index)
{
	int a = 0;
	int b = 1;

	if (index < 0)
		return (-1);
	if (index < 2)
		return (index);
	int i = 0;
	int lim = index - 1;

	while (i < lim)
	{
		b += a;
		a += b;
		i += 2;
	}
	if (i < index)
		b += a;
	if (a > b)
		return (a);
	return (b);
}

#include <unistd.h>

int main(void)
{
	char a = ft_fibonacci(5) + 48;
	write(1, &a, 1);
	write(1, "\n", 1);
}
