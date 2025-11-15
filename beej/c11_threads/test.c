#include <unistd.h>

int main (void)
{
	char buf[10];
	read(0, buf, 10);
	(void) buf;
}
