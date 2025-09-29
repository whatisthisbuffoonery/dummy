void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int i = 0;
	char *tmp;
	int flag = 0;
	while (tab[i + 1])
	{
		if (cmp(tab[i], tab[i + 1]) > 0)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			flag ++;
		}
		i ++;
		if (!tab[i + 1] && flag)
		{
			flag = 0;
			i = 0;
		}
	}
}
