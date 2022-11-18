#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	c;

	if (!lst)
		return (0);
	c = 1;
	while (lst->next)
	{
		c++;
		lst = lst->next;
	}
	return (c);
}
