#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int i = 0;
	int k = 0;
	int count = 0;
	char *a;

	if (size < 1)
	{
		a = malloc(sizeof(char));
		a[0] = '\0';
		return (a);
	}
	while (i < size)
	{
		while (strs[i][k])
		{
			k ++;
			count ++;
		}
		k = 0;
		i ++;
	}
	i = 0;
	while (sep[i])
		i ++;

	a = malloc(((count + 1) + (i * (size - 1))) * sizeof(char));
	i = 0;

	if (!a)
	{
		a = malloc(sizeof(char));
		a[0] = '\0';
		return (a);
	}

	count = 0;
	while (i < size)
	{
		k = 0;
		while (strs[i][k])
		{
			a[count] = strs[i][k];
			count ++;
			k ++;
		}
		k = 0;
		i ++;
		while (i < size && sep[k])
		{
			a[count] = sep[k];
			count ++;
			k ++;
		}
	}
	a[count] = '\0';
	return (a);
}

#include <unistd.h>

int main(int c, char **v)
{
	if (c < 2)
		return (1);
	char *a = ft_strjoin(c - 1, &v[1], " wololo ");
	int i = 0;

	while (a[i])
		i ++;
	write(1, a, i);
	write(1, "\n", 1);
}
