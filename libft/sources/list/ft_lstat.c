/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:50:45 by lucas             #+#    #+#             */
/*   Updated: 2023/03/26 20:50:46 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Ft_lstat returns the nth element of a linked list, or NULL if the
 * list is shorter than n.
 * 
 * @param lst The list to search through
 * @param at the index of the element to return
 * 
 * @return The nth element of the list.
 */
t_list	*ft_lstat(t_list *lst, int at)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst && i++ < at)
		lst = lst->next;
	if (i < at)
		return (0);
	return (lst);
}
