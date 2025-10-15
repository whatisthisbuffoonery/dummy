#ifndef RB_H
# define RB_H

#include <unistd.h>
#include <stdlib.h>

typedef enum
{
	red,
	black
}					lmao;

typedef struct		child
{
	struct child	*L;
	struct child	*R;
	struct child	*P;
	lmao			colour;
	void			*data;
}					node;

typedef struct
{
	node			**root;
	node			*nil;
}					tree;

#endif
