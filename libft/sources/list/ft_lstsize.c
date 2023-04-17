/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:52:05 by lucas             #+#    #+#             */
/*   Updated: 2023/03/26 20:52:06 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It counts the number of elements in a linked list.
 * 
 * @param lst The list to be counted.
 * 
 * @return The number of elements in the list.
 */
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
