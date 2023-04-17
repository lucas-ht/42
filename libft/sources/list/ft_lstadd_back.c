/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:50:33 by lucas             #+#    #+#             */
/*   Updated: 2023/03/26 20:50:35 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Adds the element new at the end of the list
 * 
 * @param lst A pointer to the first link of a list.
 * @param new The new element to add to the list.
 * 
 * @return The address of the last element of the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*l;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		if (new)
			new->previous = 0;
		return ;
	}
	l = ft_lstlast(*lst);
	if (l)
		l->next = new;
	if (!new)
		return ;
	new->previous = l;
	new->next = 0;
}
