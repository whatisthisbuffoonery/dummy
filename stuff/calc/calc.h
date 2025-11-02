#ifndef CALC_H
# define CALC_H

#include <unistd.h>
#include <stdlib.h>

typedef struct	s_stack
{
	s_stack 	*nil;
	s_stack 	*next;
	char		*data;
}				stack;

typedef enum
{
	num,
	op
}				t_type;

typedef struct	s_op
{
	t_type		type;
	int			data;

