#include <unistd.h>

void	print_hex(char a)
{
	char big = a / 16;
	char smol = a % 16;
	char c = 92;

	write(1, &c, 1);

	if (big > 9)
		c = big + 87;
	else
		c = big + 48;
	write(1, &c, 1);

	if (smol > 9)
		c = smol + 87;
	else
		c = smol + 48;
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] < 32)
			print_hex(str[i]);
		else
			write(1, &str[i], 1);
		i ++;
	}
}

int main(void)
{
	ft_putstr_non_printable("what\n is going \t on");
	write(1, "\n", 1);
}
