#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int		ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] && s1[i] == s2[i])
		i ++;
	return (s1[i] - s2[i]);
}

int		c_flag(int c, char **v)
{
	char *a = "-C";
	int i = 1;
	while (i < c)
	{
		if (!ft_strcmp(v[i], a))
		{
			while (i + 1 < c)
			{
				v[i] = v[i + 1];
				i ++;
			}
			return (1);
		}
		i ++;
	}
	return (0);
}

int		ft_fd(char *v, int *fd)
{
	char *a;
	int i = 0;
	*fd = open(v, O_RDONLY);
	if (*fd < 0)
	{
		a = strerror(errno);
		while (a[i])
			i ++;
		write(1, a, i);
		return (1);
	}
	return (0);
}

int		add_buf(char buf[], char *v, int *size, int *fd)
{
	if (*fd)
		close(*fd);
	if (ft_fd(v, fd))
		return (1);
	char tmp[16];
	int diff = read(*fd, tmp, 16 - *size);
	if (!diff)
		return (0);
	int i = 0;
	while (i < diff)
	{
		buf[*size + i] = tmp[i];
		i ++;
	}
	*size += diff;
	return (0);
}

void	line_print(int n, int flag)
{
	int t = 1;//fuck you perplexity for initialising this as 15.
	char a;
	int i = !flag;

	while (i < 7)
	{
		t *= 16;
		i ++;
	}
	while (t)
	{
		a = ((n / t) % 16);
		if (a > 9)
			a += 87;
		else
			a += 48;
		write(1, &a, 1);
		t /= 16;
	}
}

void	hex_help(char a)
{
	char b;
	b = (a / 16) + 48;
	if (b > 57)
		b += 39;
	write(1, &b, 1);

	b = (a % 16) + 48;
	if (b > 57)
		b += 39;
	write(1, &b, 1);
}

void	hex_print(char buf[], int size, int flag)
{
	int i = 0;
	int b = size - 1;
	while (flag && i < size)
	{
		if (!(i % 8))
			write(1, " ", 1);
		write(1, " ", 1);
		hex_help(buf[i]);
		i ++;
	}
	while (flag && i < 16)
	{
		if (!(i % 8))
			write(1, " ", 1);
		write(1, "   ", 3);
		i ++;
	}
	if (flag)
		write(1, "  ", 2);
	while (i < size)
	{
		write(1, " ", 1);

		if (i < b)
			hex_help(buf[i + 1]);
		else
			hex_help('\0');

		hex_help(buf[i]);
		i = i + 2;
	}
	if (!flag)
		write(1, "\n", 1);
}

void	jus_print(char buf[], int size)
{
	int i = 0;
	write(1, "|", 1);
	while (i < size)
	{
		if (buf[i] < 32 || buf[i] > 126)
			write(1, ".", 1);
		else
			write(1, &buf[i], 1);
		i ++;
	}
	write(1, "|\n", 2);
}

void	ft_putnbr(int n)
{
	char a;
	int t = 1;
	write(1, "\n size: ", 8);
	while (n / t > 9)
		t *= 10;
	while (t)
	{
		a = ((n / t) % 10) + 48;
		write(1, &a, 1);
		t /= 10;
	}
	write(1, "\n", 1);
}

int		main(int c, char **v)
{
	int	flag = c_flag(c, v);
	if (flag)
		c --;
	if (c < 2)
		return (1);
	char buf[16];
	int buf_size = 16;
	int fd = 0;
	int size = 0;
	int line = 0;
	int i = 0;
	int valid = 0;

	while (i < c)
	{
		while (size < 16)
		{
			i ++;
			if (i >= c)
				break;
			if(add_buf(buf, v[i], &size, &fd))
				return (1);
		}
		if (size)
		{
		//	ft_putnbr(size);
			line_print(line, flag);
			valid = 1;
			line += size;
			hex_print(buf, size, flag);
			if (flag)
				jus_print(buf, size);
			if (i < c)
				size = read(fd, buf, buf_size);
		}
	}
	if (valid)
	{
		line_print(line, flag);
		write(1, "\n", 1);
	}
}
