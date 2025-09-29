int		ft_sqrt(int nb)//fuck binary search
{
	int i = 0;

	while (i * i < nb)
		i ++;
	if (i * i > nb)
		return (0);
	return (i);
}
