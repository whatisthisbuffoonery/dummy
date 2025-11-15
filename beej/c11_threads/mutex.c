#include <unistd.h>
#include <threads.h>

mtx_t serial_mtx;

int some(void *a)
{
	mtx_lock(&serial_mtx);
	(void) a;
	static int i = 0; //not thread local
	char c =  i + 48;
	write(1, &c, 1);
	write(1, "\n", 1);
	i ++;
	mtx_unlock(&serial_mtx);
	return (0);
}


int main(void)
{
	mtx_init(&serial_mtx, mtx_plain);
	int i = 0;
	thrd_t arr[10];
	while (i < 10)
	{
		thrd_create(&arr[i], some, 0);
		i ++;
	}
	i = 0;
	while (i < 10)
	{
		thrd_join(arr[i], 0);
		i ++;
	}
	mtx_destroy(&serial_mtx);
}
