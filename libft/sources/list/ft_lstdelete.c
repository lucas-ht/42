/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.4.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 03/01/15 16:59:43 by lucas             #+#    #+#             */
/*   Updated: 03/01/15 17:07:34 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
