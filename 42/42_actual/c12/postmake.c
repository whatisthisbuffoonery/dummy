#include "ft_list.h"

void	postmake_putstr(int fd, char *v)
{
	int i = 0;
	while (v[i])
		i ++;
	write(fd, v, i);
}

int		postmake(void)
{
	int fd = open("ft_postmake.c", O_CREAT | O_WRONLY | O_EXCL, 0644);
	if (fd < 0)
	{
		postmake_putstr(1, strerror(errno));
		return (1);
	}
	postmake_putstr(fd, "t_list  *ft_create_elem(void *data);\n");
	postmake_putstr(fd, "t_list  *ft_create_elem_char(void *data);\n");
	postmake_putstr(fd, "t_list  *ft_list_last(t_list *begin_list);\n");
	postmake_putstr(fd, "t_list  *ft_list_push_strs(int size, char **strs);\n");
	postmake_putstr(fd, "t_list  *ft_list_at(t_list *begin_list, unsigned int nbr);\n");
	postmake_putstr(fd, "t_list  *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)(void *, void *));\n");
	postmake_putstr(fd, "void    ft_list_push_front(t_list **begin_list, void *data);\n");
	postmake_putstr(fd, "void    ft_list_push_back(t_list **begin_list, void *data);\n");
	postmake_putstr(fd, "void    ft_list_clear(t_list *begin_list, void (*free_fct)(void *));\n");
	postmake_putstr(fd, "void    ft_list_reverse(t_list **begin_list);\n");
	postmake_putstr(fd, "void    ft_list_foreach(t_list *begin_list, void (*f)(void *));\n");
	postmake_putstr(fd, "void    ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)(void *, void *));\n");
	postmake_putstr(fd, "void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *), void (*free_fct)(void *));\n");
	postmake_putstr(fd, "void    ft_list_merge(t_list **begin_list1, t_list *begin_list2);\n");
	postmake_putstr(fd, "void    ft_list_sort(t_list **begin_list, int (*cmp)(void *, void *));\n");
	postmake_putstr(fd, "void    ft_list_reverse_fun(t_list *begin_list);\n");
	postmake_putstr(fd, "int        ft_list_size(t_list *begin_list);\n\n\n");
	postmake_putstr(fd, "int		ft_voidcmp_char(void *a, void *b);\n");
	postmake_putstr(fd, "void	ft_elem_free(void *a);\n\n");

	close(fd);
	return (0);
}
