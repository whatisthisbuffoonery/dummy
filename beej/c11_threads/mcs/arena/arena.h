#ifndef ARENA_H
# define ARENA_H

#include <sys/mman.h>

typedef struct			s_generic
{
	struct s_generic	*self;
	struct s_generic	*next;
}						t_generic;

typedef struct
{
	int					size;
	int					front;
	t_generic			*head;
	t_generic			*tail;
}						t_book;

#endif
