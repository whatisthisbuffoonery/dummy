int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if (!n)
		return (0);

	unsigned int i = 0;

	while (i < n && s1[i] && s1[i] == s2[i])
		i ++;

	return (s1[i] - s2[i]);
}
