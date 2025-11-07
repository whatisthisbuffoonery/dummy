#ifndef TRIE_H
# define TRIE_H
//yeah no we are not doing function containers
typedef struct
{
	long double 	(*x)(double);
	long double		(*y)(double, double);
	int				args;
}					t_func;

typedef struct		s_node
{
	char			data;
	struct **s_node	child;
	t_func			*func;
}					t_node;

typedef struct		t_trie
{
	node			*nil_root;
	...
