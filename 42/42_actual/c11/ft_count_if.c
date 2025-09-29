int		ft_count_if(char **tab, int length, int (*f)(char *))
{
	int i = 0;
	int a = 0;
	while (i < length)
	{
		if (f(tab[i]))
			a ++;
		i ++;
	}
	return (a);
}
