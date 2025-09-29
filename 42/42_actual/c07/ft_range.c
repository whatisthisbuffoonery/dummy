#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int size = max - min;
	if (size < 1)
		return (NULL);
	int i = 0;
	int *a = malloc((size) * sizeof(int));
	if (!a)
		return (NULL);

	while (min + i < max)
	{
		a[i] = min + i;
		i ++;
	}
	return (a);
}
