#ifndef ROBOTS_H
# define ROBOTS_H

typedef struct
{
	int	ore;
	int clay;
	int	obsidian;
	int	geode;
}		type;

typedef struct
{
	int	ore;
	int clay;
	int	obsidian[2];
	int	geode[2];
}		type2;

#endif
