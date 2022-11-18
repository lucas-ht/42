#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l;
	t_list	*n;
	void	*content;

	if (!lst || !f || !del)
		return (0);
	l = 0;
	while (lst)
	{
		content = f(lst->content);
		n = ft_lstnew(content);
		if (!n)
		{
			ft_lstclear(&l, del);
			del(content);
			return (0);
		}
		ft_lstadd_back(&l, n);
		lst = lst->next;
	}
	return (l);
}
