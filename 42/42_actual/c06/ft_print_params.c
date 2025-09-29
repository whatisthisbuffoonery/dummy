#include <unistd.h>

int		main(int c, char **v)
{
	int i = 0;
	int k = 1;

	while (k < c)
	{
		while (v[k][i])
			i ++;
		write(1, v[k], i);
		write(1, "\n", 1);
		k ++;
		i = 0;
	}
}
