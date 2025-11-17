#ifndef TR_H
# define TR_H

#include <unistd.h>
#include <stdlib.h>
#include <threads.h>
#include <stdatomic.h>

typedef struct					s_node
{
	_Atomic (struct s_node *)	next;
	atomic_int					data;
}								t_node;

typedef struct
{
	_Atomic (t_node *)			head;
	_Atomic (t_node *)			top;
}								t_stack;

#endif
