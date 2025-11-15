#include <unistd.h>
#include <threads.h>

int my_static(void)
{
	thread_local static int i = 10;
	i ++;
	return (i);
}

int run(void *a)
{
	(void) a;
	int i = 0;
	int b;
	while (i < 5)
	{
		b = my_static();
		i ++;
	}
	return (b);
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

int main(void)
{
	int dest = 0;
	thrd_t t;
	thrd_create(&t, run, 0);
	thrd_join(t, &dest);
	ft_putnbr(dest);
	thrd_create(&t, run, 0);
	thrd_join(t, &dest);
	ft_putnbr(dest);
}
