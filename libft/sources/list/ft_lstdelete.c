/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:50:54 by lucas             #+#    #+#             */
/*   Updated: 2023/03/26 20:50:55 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It deletes a node from a doubly linked list
 * 
 * @param lst The list to delete from.
 * @param node the node to delete
 * @param del a function pointer to a function that will be used to
 * delete the content of the node.
 * 
 * @return the number of elements in the list.
 */
void	ft_lstdelete(t_list **lst, t_list *node, void (*del)(void *))
{
	if (!lst || !node)
		return ;
	if (node->previous)
	{
		node->previous->next = node->next;
		if (node->next)
			node->next->previous = node->previous;
	}
	else
	{
		*lst = node->next;
		if (node->next)
			node->next->previous = 0;
	}
	if (del)
		del(node->content);
}
