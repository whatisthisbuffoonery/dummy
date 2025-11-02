#ifndef RB_H
# define RB_H

#include <unistd.h>
#include <stdlib.h>

typedef enum
{
	red,
	black
}					colour;

typedef struct		child
{
	struct child	*L;
	struct child	*R;
	struct child	*P;
	colour			C;
	void			*data;
}					node;

typedef struct
{
	node			**root;
	node			*nil;
}					tree;

node	*btree_create_node(void *data, node *nil);
node	*btree_search(tree *dis, void *data, int (*cmpf)(void *, void *));

void	btree_insert_data(tree *dis, void *data, int (*cmpf)(void *, void*), int b[], int verbose);
void	btree_delete(tree *dis, node *curr, void (*free_fct)(node *), int b[], int verbose);
void	btree_prefix(node *root, node *nil, int k);
void	rotate_mux(tree *dis, node *x, char a, int verbose);
void	redden(node *a, tree *dis, int flag);

void	btree_clear(tree *dis);

void	ft_putstr(char *a);
void	ft_putnbr(int n);

char	ft_child_not(node *a);
char	ft_child(node *a);

int		btree_level_count(tree *dis);

int		ft_good_atoi(char *str);
int		ft_atoi(char *);

#endif
