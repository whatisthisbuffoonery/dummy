#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] && s1[i] == s2[i])
		i ++;
	return (s1[i] - s2[i]);
}

int		ft_strlen(char *a)
{
	int i = 0;

	while (a[i])
		i ++;
	return (i);
}

int		main(int c, char **v)
{
	if (c < 2)
		return (1);
	int i = 1;
	int b = c - 1;
	char *tmp;
	int flag = 0;

	while (i < b)
	{
		if (ft_strcmp(v[i], v[i + 1]) > 0)
		{
			tmp = v[i];
			v[i] = v[i + 1];
			v[i + 1] = tmp;
			flag ++;
		}
		i ++;
		if (i >= b && flag)
		{
			i = 1;
			flag = 0;
		}
	}
	i = 1;
	while (i < c)
	{
		write(1, v[i], ft_strlen(v[i]));
		write(1, "\n", 1);
		i ++;
	}
}
