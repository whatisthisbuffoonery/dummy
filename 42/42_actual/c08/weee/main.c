#include "ft_stock_str.h"

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
void				ft_show_tab(struct s_stock_str *par);

int					main(int c, char **v)
{
	ft_show_tab(ft_strs_to_tab(c, v));
}
