#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int i = 0;
	while (src[i++]);

	char *dup = malloc(i * sizeof(char));
	if (!dup)
		return (0);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i ++;
	}
	dup[i] = '\0';
	return (dup);
}
