#include <unistd.h>
#include <threads.h>

#define N 5

int num[N] = {0};
int count = 0;
//int flag = 1;

mtx_t addmtx;
cnd_t wait;

int ft_atoi(char *v, int size)
{
	int i = 0;
	if (!size)
	{
		write(1, "waa\n", 4);
		//*complain = 1;
	}
	else
		return (v[i] - 48);
	return (0);
}

void ft_putnbr(int n)
{
	char a;
	int t = 1;
	while (n / t > 9)
		t *= 10;
	while (t)
	{
		a = ((n / t) % 10) + 48;
		write(1, &a, 1);
		t /= 10;
	}
	write(1, "\n", 1);
//	flag = 0;
}

int run(void *a)
{
	(void) a;
	int i = 0;
	int t;
	while (1)
	{
		mtx_lock(&addmtx);
		while (count < N)
			cnd_wait(&wait, &addmtx);
		t = 0;
		write(1, "wake\n", 5);
		while (i < count)
			t += num[i++];
		ft_putnbr(t);
		mtx_unlock(&addmtx);
		break;
	}
	return (0);
}
//detach bad, detach lousy
int main(void)
{
	thrd_t child;

	mtx_init(&addmtx, mtx_plain);
	cnd_init(&wait);

	thrd_create(&child, run, 0);

	int n;
	char buf[1024];
	while (count < N)
	{
		mtx_lock(&addmtx);

		n = read(0, buf, 1024);
		num[count++] = ft_atoi(buf, n);
		if (count == N)
		{
			cnd_signal(&wait);
		}
		mtx_unlock(&addmtx);
	}
	thrd_join(child, 0);
	mtx_destroy(&addmtx);
	cnd_destroy(&wait);
}
