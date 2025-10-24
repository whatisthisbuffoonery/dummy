#include <unistd.h>

void	ft_putstr(char *a)
{
	int i = 0;

	while(a[i])
		i ++;
	write(1, a, i);
	write(1, "\n", 1);
}

int		main(void)
{
	int i = 0;
	while(__environ[i])
		ft_putstr(__environ[i++]);
}
