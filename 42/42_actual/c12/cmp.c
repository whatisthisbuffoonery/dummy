int		ft_voidcmp_char(void *a, void *b)
{
	char *c = (char *)a;
	char *d = (char *)b;

	int i = 0;

	while (c[i] && c[i] == d[i])
		i ++;
	return (c[i] - d[i]);
}
