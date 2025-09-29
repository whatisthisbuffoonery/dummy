int		ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int b = length - 1;
	while (i < b)
	{
		if (f(tab[i]), f(tab[i + 1]) > 0)
		   return (0);
		i ++;
	}
	return (1);
}
