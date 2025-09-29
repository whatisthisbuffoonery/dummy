#include "ft_stock_str.h"

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int i = 0;
	int k;

	if (ac < 1)
		return (NULL);
	t_stock_str *par = malloc((ac + 1) * sizeof(t_stock_str));
	if (!par)
		return (NULL);

	while (i < ac)
	{
		k = -1;
		par[i].str = av[i];
		while (av[i][++k]);
		par[i].copy = malloc((k + 1) * sizeof(char));
		if (!par[i].copy)
			return (NULL);
		par[i].size = k;
		k = -1;
		while (av[i][++k])
			par[i].copy[k] = av[i][k];
		i ++;
	}
	par[i].size = 0;
	par[i].str = NULL;
	par[i].copy = NULL;
	return (par);
}
