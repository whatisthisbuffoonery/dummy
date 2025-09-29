char	*ft_strcapitalize(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] > 96 && str[i] < 123)
			str[i] -= 32;
		i ++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] > 64 && str[i] < 91)
		{
			if (str[i - 1] > 64 && str[i - 1] < 91)
				str[i] += 32;
			if (str[i - 1] > 96 && str[i - 1] < 123)
				str[i] += 32;
			if (str[i - 1] > 48 && str[i - 1] < 57)
				str[i] += 32;
		}
		i ++;
	}
}
