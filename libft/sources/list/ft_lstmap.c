/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.4.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0/11/03 :4:05 by lhutt             #+#    #+#             */
/*   Updated: 0/11/30 3:45:35 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstma(t_list *lst, void *(*f)(void *), void (*del)(void *))
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
