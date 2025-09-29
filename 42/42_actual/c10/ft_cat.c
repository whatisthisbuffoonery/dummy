#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int		ft_strlen(char *a)
{
	int i = 0;
	while (a[i])
		i ++;
	return (i);
}

int		main(int c, char **v)
{
	int size = 0;
	char buf[29000];
	int b = 29000;
	while (c == 1)
	{
		size = read(1, buf, b);
		if (size < 0)
		{
			write(1, strerror(errno), ft_strlen(strerror(errno)));
			return (1);
		}
		write(1, buf, size);
	}
	int i = 1;
	int fd;
	while (i < c)
	{
   		fd = open(v[i], O_RDONLY);
		if (fd < 0)
		{
			write(1, strerror(errno), ft_strlen(strerror(errno)));
			return (1);
		}
		size = read(fd, buf, b);
		while (size > 0)
		{
			write(1, buf, size);
			size = read(fd, buf, b);
		}
		i ++;
	}
}
