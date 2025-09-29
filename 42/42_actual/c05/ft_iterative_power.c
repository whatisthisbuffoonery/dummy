int		ft_iterative_power(int nb, int power)
{
	int a = 1;
	if (power < 0)
		return (0);
	while (power--)
		a *= nb;
	return (a);
}
