extern char **environ;
#include <stdio.h>
int main(void)
{
	int i = 0;
	while (environ[i])
		printf("%s\n", environ[i++]);
}
