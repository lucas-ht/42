/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:51:34 by lucas             #+#    #+#             */
/*   Updated: 2023/03/26 20:51:37 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It takes a list, a function that returns a pointer to a new element,
 * and a function that deletes an
 * element, and returns a new list with the new elements
 * 
 * @param lst The list to iterate over.
 * @param f a function that takes a void pointer and returns a void pointer
 * @param del a function that will be used to free the content of the list
 * 
 * @return A new list with the content of the old list mapped by the function f.
 */
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
