/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:50:59 by lucas             #+#    #+#             */
/*   Updated: 2023/03/26 20:51:01 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Delete a single list element
 * 
 * @param lst The address of a pointer to a link.
 * @param del a pointer to a function that takes a single argument
 * and returns nothing.
 * 
 * @return Nothing.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!del)
		return ;
	del(lst->content);
	free(lst);
}
