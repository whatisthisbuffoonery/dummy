#include "tr.h"

int main(void)
{
	int i = 0;
	int max = 10;
	int src[max];
	thrd_t t[max];

	while (i < max)
	{
		src[i] = i;
		thrd_create(&t[i], run, &src[i]);
		i ++;
	}
	i = 0;
	while (i < max)
		thrd_join(t[i++], 0);
	i = 0;
	while (i < max)
		thrd_create(&t[i++], pop, 0);
	i = 0;
	while (i < max)
		thrd_join(t[i++], 0);
	sd
