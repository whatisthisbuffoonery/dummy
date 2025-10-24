#include <unistd.h>

int		by_2(int n)
{
	return (2 * n);
}

int		(*uh(int flag))(int)
{
	if (flag)
		return (by_2);
	return (0);
}

int		main(void)
{
	int i = 0;
	i = uh(1)(5);
	if (i == 10)
		write(1, "really\n", 7);

	int (*f)(int) = (*uh(1));
	if (f(2) == 4)
		write(1, "hmm\n", 4);
}
