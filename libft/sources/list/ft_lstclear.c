/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:49:30 by lucas             #+#    #+#             */
/*   Updated: 2023/03/26 20:49:47 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It takes a pointer to a pointer to a linked list, and a pointer to a function
 * that takes a void
 * pointer and returns nothing. It then iterates through the linked list, calling
 * the function on each
 * element, and then frees the element
 * 
 * @param lst a pointer to the first element of a linked list
 * @param del a pointer to a function that takes a single void pointer argument
 * and returns nothing.
 * 
 * @return A pointer to the first element of the new list.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*l;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		l = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = l;
	}
}
