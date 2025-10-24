#include "rb.h"

void	clear_help(node *root, node *nil)
{
	if(root->L != nil)
		clear_help(root->L, nil);
	if(root->R != nil)
		clear_help(root->R, nil);
	if (root != nil)
		free(root);
}

void	btree_clear(tree *dis)
{
	if(*dis->root != dis->nil)
		clear_help(*dis->root, dis->nil);
	free(dis->nil);
	free(dis);
}
