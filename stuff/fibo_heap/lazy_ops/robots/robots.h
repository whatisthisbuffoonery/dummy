#ifndef ROBOTS_H
# define ROBOTS_H

typedef struct
{
	int	ore;
	int	clay;
	int	obsidian;
	int	geode;
}		type;

typedef struct
{
	int	ore;
	int	clay;
	int	obsidian[2];
	int	geode[2];
}		type2;

typedef struct 		child
{
	int				data;
	struct child	*N;
}					node;

typedef struct
{
	int				size;
	int				curr;
	node			*map;
}					node_list;


#endif
