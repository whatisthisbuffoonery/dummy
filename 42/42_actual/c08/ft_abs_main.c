#include <unistd.h>
#include "ft_abs.h"

int main(void)
{
	char a = ABS(0) + 48;

	write(1, &a, 1);
	write(1, "\n", 1);
}
