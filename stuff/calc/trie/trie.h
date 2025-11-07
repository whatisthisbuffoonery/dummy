#ifndef TRIE_H
# define TRIE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef union
{
    float (*float_1)(float);
    float (*float_2)(float, float);
	double (*double_1)(double);
	double (*double_2)(double, double);
	long double (*l_double_1)(long double);
	long double (*l_double_2)(long double, long double);
}	FU;

typedef enum
{
	f1 = 1,
	f2 = 2,
	d1 = 3,
	d2 = 4,
	ld1 = 5,
	ld2 = 6
}	FU_index;

typedef struct
{
	FU			f;
	FU_index	which;
}				t_tr;

typedef struct	s_node
{
	char		data;
	s_node		**next;
	t_tr		func;
}				t_node;

//variable func containers. waw.
//
//the other solution was to wrap every math func in its own double (*f)(double, double) placeholder and adjust as needed

#endif
