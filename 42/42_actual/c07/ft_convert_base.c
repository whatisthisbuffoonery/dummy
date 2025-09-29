#include <stdlib.h>

void	set_b(int *b)
{
	int i = 0;
	while (i < 128)
	{
		b[i] = 0;
		i ++;
	}
}

int		check_base(char *base, int *n, int *b)
{
	int i = 0;

	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		if (b[(unsigned char)base[i]])
			return (1);
		else
		{
			*n += 1;
			b[(unsigned char)base[i]] = *n;
		}
		i ++;
	}
	if (*n < 2)
		return (1);
	return (0);
}

int		ft_atoi(char *nbr, int n, int *b)
{
	int i = 0;
	long a = 0;
	int flag = 0;
	while (nbr[i] == 32 || (nbr[i] > 8 && nbr[i] < 14))
		i ++;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			flag ++;
		i ++;
	}
	while (b[(unsigned char)nbr[i]])
	{
		a *= n;
		a += b[(unsigned char)nbr[i]] - 1;
		i ++;
	}
	if (flag % 2)
		a = 0 - a;
	i = a;
	return (i);
}

char	*ft_convert(int input, int n, char *b)
{
	long tmp = input;
	int size = 2;
	int t = n;
	int i = 0;
	char *a;

	if (tmp < 0)
		tmp = 0 - tmp;
	while (t < tmp)
	{
		size ++;
		t *= n;
	}
	if (input < 0)
	{
		a = malloc((size + 1) * sizeof(char));
		a[i] = '-';
		i ++;
	}
	else
		a = malloc(size * sizeof(char));
	t = 1;
	while (tmp / t > n - 1)
		t *= n;
	while (t)
	{
		a[i] = b[(tmp / t) % n];
		t /= n;
		i ++;
	}
	a[i] = '\0';
	return(a);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int n = 0;
	int *b = malloc(128 * sizeof(int));
	set_b(b);
	if (check_base(base_from, &n, b) || !nbr || !nbr[0])
		return (NULL);
	int input = ft_atoi(nbr, n, b);
	n = 0;
	set_b(b);
	if (check_base(base_to, &n, b))
		return (NULL);
	char *a = ft_convert(input, n, base_to);
	free(b);

	return (a);
}

#include <unistd.h>

int main(void)
{
	char *a = ft_convert_base("-2748", "0123456789", "0123456789abcdef");
	int i = 0;
	while (a[i])
		i ++;
	write(1, a, i);
	write(1, "\n", 1);
	free(a);
}
