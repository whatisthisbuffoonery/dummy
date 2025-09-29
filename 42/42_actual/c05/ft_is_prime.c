int		ft_is_prime(int nb)
{
	int i = 2;
	int b = nb / 2;

	while (i < b && nb % i)
		i ++;
	if (nb % i == 0)
		return (0);
	return (1);
}
