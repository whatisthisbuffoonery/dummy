#include <unistd.h>
#include <stdlib.h>

int main(int c, char **v)
{
	if (c < 3)
	{
		write(1, "provide N, then C\n", 18);
		return (1);
	}
	int complain = 0;
	int num_n = ft_atoi(v[1], &complain);
	int num_c = ft_atoi(v[2], &complain);
	if (complain || num_c > num_n)
	{
		write(1, "complain\n", 9);
		return (1);
	}
	if (num_n - num_c == 0)
	{
		write(1, "1\n", 2);
		return (0);
	}
	if (num_c == 1 || num_n - num_c == 1)
	{
		ft_putnbr(num_n);
		return (0);
	}
	int memo[num_c] = {0};
	int i = 1;
	while (i < num_c)
	{
		memo[i] = i * memo[i - 1];
		i ++;
	}
}
