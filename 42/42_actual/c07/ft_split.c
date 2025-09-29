#include <stdlib.h>
#include <unistd.h>

void	fill(char **result, char *a, int (*b)[])
{
	int i = 0;
	int offset = 0;
	int k = 0;

	while (a[offset + i])
	{
		while (!(*b)[(unsigned char)a[offset + i]] && a[offset + i])
		{
			result[k][i] = a[offset + i];
			i ++;
		}
		offset += i;
		if (!i)
			offset ++;
		else
		{
			result[k][i] = '\0';
			k ++;
		}
		i = 0;
	}
}

void	ft_size(char **result, char *a, int (*b)[])
{
	int i = 0;
	int offset = 0;
	int k = 0;

	while (a[offset + i])
	{
		while (!(*b)[(unsigned char)a[offset + i]] && a[offset + i])
			i ++;
		offset += i;
		if (!i)
			offset ++;
		else
			result[k++] = malloc((i + 1) * sizeof(char));
		i = 0;
	}
}

char	**ft_split(char *str, char *charset)
{
	if (!str || !str[0])
		return (NULL);
	int i = 0;
	int size = 1;
	int b[128];
	while (i < 128)
		b[i++] = 0;
	i = 0;
	while (charset[i])
		b[(unsigned char)charset[i++]] = 1;
	i = 0;
	while (str[i])
	{
		if (!b[(unsigned char)str[i]] && (!str[i + 1] || b[(unsigned char)str[i + 1]]))
			size ++;
		i ++;
	}

	char **result = malloc(size * sizeof(char *));
	ft_size(result, str, &b);
	fill(result, str, &b);
	result[size - 1] = NULL;
	return (result);
}

#include <stdio.h>

int		main(void)
{
	char **a = ft_split("abcdefg", "bcf");
	int i = 0;
	while (a[i])
		printf("%s\n", a[i++]);
}
