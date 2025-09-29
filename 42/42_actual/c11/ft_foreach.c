#include <unistd.h>

void	func(int n)
{
	char a = n + 48;
	write(1, &a, 1);
}

void	ft_foreach(int *tab, int length, void(*f)(int))
{
	int i = 0;
	while (i < length)
		f(tab[i++]);
}

int main (void)
{
	int a[10] = {0,1,2,3,4,5,6,7,8,9};
	ft_foreach(a, 10, func);
	write(1, "\n", 1);
}
