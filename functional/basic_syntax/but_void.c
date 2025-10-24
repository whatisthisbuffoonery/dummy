#include <unistd.h>

void	hi(void)
{
	write(1, "hi\n", 3);
}

void	hey(void)
{
	write(1, "hey\n", 4);
}

void	(*huh(int flag))(void)
{
	if (flag)
		return (hi);
	return (hey);
}

int		main(int c, char **v)
{
	if (c != 2)
	{
		write(1, "either 1 or 0\n", 14);
		return (1);
	}
	huh(v[1][0] - 48)();
}
