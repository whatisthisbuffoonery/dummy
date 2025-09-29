#include <unistd.h>

int		main(int c, char **v)
{
	int i = 0;
	int k = c;

	while (k > 1)
	{
		while (v[k - 1][i])
			i ++;
		write(1, v[k - 1], i);
		write(1, "\n", 1);
		k --;
		i = 0;
	}
}
