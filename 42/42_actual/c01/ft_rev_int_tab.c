#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int i = 0;
	int b = size / 2;
	int tmp = 0;
	while (i < b)
	{
		tmp = tab[i];
		tab[i] = tab[(size - 1) - i];
		tab[(size - 1) - i] = tmp;
		i ++;
	}
}

int main(void)
{
	char a;
	int tab[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	ft_rev_int_tab(tab, 9);
	int i = 0;
	while (i < 9)
	{
		a = tab[i] + 48;
		write(1, &a, 1);
		i ++;
	}
	write(1, "\n", 1);
}
