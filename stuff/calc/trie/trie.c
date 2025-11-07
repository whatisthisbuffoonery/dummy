#include "trie.h"

t_node	*trie_create(char src)
{
	t_node *a = malloc(sizeof(t_node));
	a->next = malloc(sizeof
	a->data = 

int		main(int c, char **v)
{
	if (c < 2)
		return (1);
	int i = 1;
	char buf[1024];
	int fd = open("test.txt", O_RDOLNY);
	if (fd == -1)
		return (1);
	int r = read(fd, buf, 1024);
	int k = 0;
	t_node *trie = trie_create(0);
	while (k < 1024)
	{
		trie_insert(trie, buf, &k);
		k ++;
	}
	while (i < c)
	{
		trie_search(trie, v[i]);
		i ++;
	}
}
