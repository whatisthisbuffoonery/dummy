int		ft_iterative_factorial(int nb)
{
	int a = nb;

	if (nb < 0)
		return (0);
	if (!nb)
		return (1);
	while (--nb)
		a *= nb;
	return (a);
}
