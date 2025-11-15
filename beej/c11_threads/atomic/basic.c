#include <threads.h>
#include <unistd.h>
#include <stdatomic.h>
atomic_int x;//bootlog mutex
int y = 0;//not atomic

int thread1(void *arg)
{
	(void) arg;
//	thrd_sleep(&(struct timespec){.tv_sec = 0, .tv_nsec=100000000}, 0);

	y = 1;
	x = 2;//mutex release, global read/writes before this sync up to release
//	y = 1;
	return (0);
}

void ft_putnbr(int n)
{
	int t = 1;
	char a;
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

int thread2(void *arg)
{
	(void) arg;
	while (x != 2) {}//mutex lock

	ft_putnbr(y);

	return (0);
}

int main(void)
{
	x = 0;

	thrd_t t1, t2;

	thrd_create(&t1, thread1, 0);
	thrd_create(&t2, thread2, 0);

	thrd_join(t1, 0);
	thrd_join(t2, 0);
}
