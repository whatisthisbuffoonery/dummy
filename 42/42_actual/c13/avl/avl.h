#ifndef AVL_H
# define AVL_H

# include <unistd.h>
# include <stdlib.h>

typedef struct		child
{
	struct child	*P;
	struct child	*L;
	struct child	*R;
	int				H;
	void			*data;
}					node;

typedef struct
{
	char			nil;
	node			*at;
}					maybe;

#endif
