#include <unistd.h>

int		main(int c, char **v)
{
	int i = 0;
	(void) c;

	while (v[0][i])
		i ++;
	write(1, v[0], i);
	write(1, "\n", 1);
}
