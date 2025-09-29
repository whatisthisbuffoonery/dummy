#include <unistd.h>

void	mem_print(unsigned long n, int recurse)
{
	if (n > 15)
		mem_print(n / 16, recurse + 1);
	if (n < 16 && recurse < 16)
	{
		while (recurse++ < 16)
			write(1, "0", 1);
	}
	char a = (n % 16);

	if (a > 9)
		a += 87;
	else
		a += 48;
	write(1, &a, 1);
}

void	hex_help(char str)
{
	char a = 0;

	a = (str / 16) + 48;
	if ((str / 16) > 9)
		a = (str / 16) + 87;
	write(1, &a, 1);

	a = (str % 16) + 48;
	if ((str % 16) > 9)
		a = (str % 16) + 87;
	write(1, &a, 1);
}

void	hex_print(char *str, unsigned int size)
{
	unsigned int i = 0;
	unsigned int a = 0;

	while (i < size)
	{
		hex_help(str[i++]);
		if (i < size)
		{
			hex_help(str[i++]);
			write(1, " ", 1);
		}
	}
	if (i < 16)
		a = (2 * (16 - i)) + ((16 - i) / 2);
	a += a % 2;
	while (a--)
		write(1, " ", 1);
}

void	jus_print(char *str, unsigned int size)
{
	unsigned int i = 0;

	while (i < size)
	{
		if (str[i] < 31)
			write(1, ".", 1);
		else
			write(1, &str[i], 1);
		i ++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char *str = (char*) addr;

	unsigned long nbr = 0;
	unsigned int i = 0;
	unsigned int n = 0;

	while (i < size)
	{
		while (i + n < size && n < 16)
			n ++;
		nbr = (unsigned long) &str[i];
		mem_print(nbr, 1);
		write(1, " :", 2);
		hex_print(&str[i], n);
		jus_print(&str[i], n);
		write(1, "\n", 1);
		i += n;
		n = 0;
	}
	return (addr);
}

#include <fcntl.h>

int main(int c, char **v)
{
	if (c < 2)
		return (1);
	char buf[29000];
	int buf_size = 29000;
	int fd = open(v[1], O_RDONLY);
	int size = read(fd, buf, buf_size);
	ft_print_memory((void*)&buf[0], size);
}
