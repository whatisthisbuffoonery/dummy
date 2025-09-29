#include <fcntl.h>
#include <unistd.h>

int		main(int c, char **v)
{
	if (c < 2)
	{
		write(1, "File name missing\n", 18);
		return (1);
	}
	if (c > 2)
	{
		write(1, "Too many arguments\n", 19);
		return (1);
	}
	int fd = open(v[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "Cannot read file\n", 25);
		return (1);
	}
	int b = 1024;
	char buf[1024];

	int size = read(fd, buf, b);

	write(1, buf, size);

	while (size == 1204)
	{
		read(fd, buf, b);
		write(1, buf, size);
	}
}
