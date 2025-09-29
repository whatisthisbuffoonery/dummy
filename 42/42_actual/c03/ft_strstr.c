#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int i = 0;
	int k = 0;

	while (str[i])
	{
		if (str[i] == to_find[k])
			k ++;
		else
		{
			i -= k;
			k = 0;
		}
		if (!to_find[k])
			return (&str[i - (k - 1)]);
		i ++;
	}
	return (0);
}

int main(void)
{
	char *a = "sssstr";
	char *b = "str";
	int i = 0;

	while (b[++i]);
	write(1, ft_strstr(a, b), i);
	write(1, "\n", 1);
}
