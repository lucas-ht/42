/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:50:40 by lucas             #+#    #+#             */
/*   Updated: 2023/03/26 20:50:41 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Adds a new element to the beginning of a linked list.
 * 
 * @param lst A pointer to a pointer to the first element of a linked list.
 * @param new the new element to add to the list
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->previous = 0;
	new->next = *lst;
	if (new->next)
		new->next->previous = new;
	*lst = new;
}
