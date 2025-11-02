#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "robots.h"

int		fill(int fd, int *complain)
{
	int flag = 0;
	char c[1];
	int a = 0;
	int rd = 0;
	while (!flag)
	{
		if ((rd = read(fd, c, 1)) < 1)
		{
			*complain = 1;
			return (0);
		}
		while (c[0] >= '0' && c[0] <= '9'&& rd == 1)
		{
			flag = 1;
			a *= 10;
			a += c[0] - 48;
			rd = read(fd, c, 1);
		}
	}
	return (a);
}
	
type2	bitmap(char *v, int *complain)
{
	int fd = open(v, O_RDONLY);
	type2 result = {0, 0, {0, 0}, {0, 0}};
	if (fd == -1)
	{
		*complain = 1;
		return (result);
	}
	result.ore = fill(fd, complain);
	result.clay = fill(fd, complain);
	result.obsidian[0] = fill(fd, complain);
	result.obsidian[1] = fill(fd, complain);
	result.geode[0] = fill(fd, complain);
	result.geode[1] = fill(fd, complain);
	return (result);
}	

void	tick(type *res, type *robots)
{
	res->ore += robots->ore;
	res->clay += robots->clay;
	res->obsidian += robots->obsidian;
	res->geode += robots->geode;
}

void	ft_putstr(char *a)
{
	int i = 0;
	while (a[i])
		i ++;
	write(1, a, i);
}

int		main(int c, char **v)//common modes: 32 turns, 24 turns
{
	if (c != 2)
	{
		write(1, "Usage: ", 7);
		ft_putstr(v[0]);
		write(1, " test.txt\n", 9);
		return (1);
	}
	int complain = 0;
	type2 blueprints = bitmap(v[1], &complain);
	if (complain)
	{
		write(1, "complain\n", 9);
		return (1);
	}
	type res = {0, 0, 0, 0};
	type robots = {1, 0, 0, 0};
	solve(
}
