#include <unistd.h>

void ft_xor(char data[], int key, int i, int result)
{
	if (result)
		data[i] = !(key) + 48;
	else
		data[i] = (key) + 48;
}

int main(void)
{
	int    key[20] = {0,1,1,0,0,0,1,1,1,1,1,0,0,0,0,1};
	int result[20] = {1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,1};

	char data[16];

	int i = 0;
	while (i < 16)
		data[i++] = 0;
	i = 0;
	while (i < 16)
	{
		ft_xor(data, key[i], i, result[i]);
		i ++;
	}
	write(1, data, 16);
	write(1, "\n", 1);
	data[0] = !key[0] + 48;
	data[6] = !key[6] + 48;
	data[13] = !key[13] + 48;
	write(1, data, 16);
	write(1, "\n", 1);
}
