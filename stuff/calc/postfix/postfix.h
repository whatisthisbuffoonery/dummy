#ifndef POSTFIX_H
# define POSTFIX_H

#include <unistd.h>
#include <stdlib.h>

typedef enum
{
	p = 7,
	e = 6,
	md = 5,
	as = 4,
	num = 3,
	alg = 2,
	nil = 1
}				t_type;

typedef struct	s_op
{
	t_type		type;
	struct s_op	*next;
	char		*num;
	char		data;
}				t_op;

typedef struct
{
	int			top;
	t_op		*arr;
}				t_stack;

typedef struct	s_queue
{
	int			size;
	t_op		*nil;
	t_op		*back;
	t_op		*front;
}				t_queue;

#endif
