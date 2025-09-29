int		ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index < 2)
		return (index);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

#include <unistd.h>

int main(void)
{
	char a = ft_fibonacci(5) + 48;
	write(1, &a, 1);
	write(1, "\n", 1);
}
