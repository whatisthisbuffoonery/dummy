#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int flag = 0;
	int i = 0;
	int b = size -1;
	int tmp = 0;
	while (i < b)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			flag ++;
		}
		i ++;
		if (flag && i >= b)
		{
			flag = 0;
			i = 0;
		}
	}
}

int main(void)
{
	int tab[11] = {5,6,3,4,7,9,8,0,1,2};
	int size = 10;
	int i = 0;
	char a;
	ft_sort_int_tab(tab, size);

	while (i < size)
	{
		a = tab[i] + 48;
		write(1, &a, 1);
		i ++;
	}
	write(1, "\n", 1);
}
