#include <stdlib.h>

int		*ft_map(int *tab, int length, int(*f)(int))
{
	int i = 0;
	int *result = malloc(length * sizeof(int));
	while (i < length)
	{
		result[i] = f(tab[i]);
		i ++;
	}
	return (result);
}

int		func(int n)
{
	return (n + 1);
}

#include <unistd.h>

int		main(void)
{
	int *a = ft_map((int[]){0,1,2,3}, 4, func);//this runs fine
	int i = 0;
	char c;
	while (i < 4)
	{
		c = a[i] + 48;
		write(1, &c, 1);
		i ++;
	}
	write(1, "\n", 1);
	free(a);
}
