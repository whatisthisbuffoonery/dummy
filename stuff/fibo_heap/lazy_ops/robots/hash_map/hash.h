#ifndef HASH_H
# define HASH_H

#include <unistd.h>
#include <stdlib.h>

typedef struct 		child
{
	char			*data;
	char			nil;
	struct child	*N;
}					node;

typedef struct
{
	int				size;
	int				curr;
	node			*map;
}					node_list;

#endif
