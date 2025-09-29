#include "ft_list.h"

t_list	*ft_create_elem(void *data);
t_list	*ft_list_last(t_list *begin_list);
t_list	*ft_list_push_strs(int size, char **strs);
t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);
t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)(void *, void *));
void	ft_list_push_front(t_list **begin_list, void *data);
void	ft_list_push_back(t_list **begin_list, void *data);
void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *));
void	ft_list_reverse(t_list **begin_list);
void	ft_list_foreach(t_list *begin_list, void (*f)(void *));
void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)(void *, void *));
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *), void (*free_fct)(void *));
void	ft_list_merge(t_list **begin_list1, t_list *begin_list2);
void	ft_list_sort(t_list **begin_list, int (*cmp)(void *, void *));
void	ft_list_reverse_fun(t_list *begin_list);

int		ft_list_size(t_list *begin_list);

void	ft_putstr(void *a)
{
	char *b = (char *)a;
	int i = 0;
	while (b[i])
		i ++;
	write(1, b, i);
	write(1, "\n-----\n", 7);
}

int		ft_strcmp(void *a, void *b)
{
	char *s1 = (char *)a;
	char *s2 = (char *)b;
	int i = 0;

	while (s1[i] && s1[i] == s2[i])
		i ++;
	return (s1[i] - s2[i]);
}

int		main(int c, char **v)
{
	if (c < 2)
		return (1);
	write(1, "-----\n", 6);
	t_list *a = ft_list_push_strs(c - 1, v + 1);
	ft_list_sort(&a, ft_strcmp);
	ft_list_reverse_fun(a);
	ft_list_reverse(&a);
	ft_list_foreach(a, ft_putstr);
	ft_list_clear(a, NULL);
}
