#include <unistd.h>

int main(void)
{
	char buf[1024];
	int size;
	size = read(0, buf, 1);
	write(1, buf, size);
	while (size)// && buf[0] != '\n')
	{
		size = read(0, buf, 1);
		write(1, buf, size);
	}
	write(1, "\n", 1);
}
