#include <unistd.h>
#include <threads.h>
#ifdef __STDC_NO_THREADS__
#error I need threads to build this program!
#endif

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

int something(void *v)
{
	int a = *(int *)v;
	ft_putnbr(a);
	return (2);
}
//DIY int &(int){10}
//and do check valgrind for threads
int main(void)
{
	int dest = 0;
	int src = 10;
	thrd_t t;//can reuse after thrd_join, otherwise no
	thrd_t ymca;
	thrd_create(&t, something, (void *)&src);
	thrd_join(t, &dest);
	ft_putnbr(dest);
	thrd_create(&ymca, something, (void *)&src);
	thrd_detach(ymca);
    thrd_sleep(&(struct timespec){.tv_sec=1}, NULL);
}
