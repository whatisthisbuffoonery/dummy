#include <unistd.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int size = max - min;
	if (size < 1)
	{
		*range = NULL;
		return (0);
	}
	int i = 0;
	*range = malloc(size * sizeof(int));
	if (!(*range))
		return (0);

	while (min + i < max)
	{
		(*range)[i] = min + i;
		i ++;
	}
	return (size);
}
