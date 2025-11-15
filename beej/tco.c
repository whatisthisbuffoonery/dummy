#include <unistd.h>



//gotos do three things
//1. break out of super nested loops (why are you 5 layers deep)
//2. subsitute caller memory responsibility (ew)
//3. do idiotic loops as follows:




int	recursive(int n, int pow)//normal
{
	if (!pow)
		return (1);
	return (n * recursive(n, pow - 1));
}

int	tco(int n, int pow)//tco using goto
{
	int a = n;
muh_label:

	if (pow < 2)
		return ((n * pow) + (!pow));
	n *= a;
	pow --;
	goto muh_label;
}


void	ft_putnbr(int n)
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

int	main(void)
{
	ft_putnbr(recursive(2, 0));
	ft_putnbr(tco(2, 0));
}
