int		ft_str_is_uppercase(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (!(str[i] > 64 && str[i] < 91))
			return (0);
		i ++;
	}
	return (1);
}
