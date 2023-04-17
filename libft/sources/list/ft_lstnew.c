/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:51:45 by lucas             #+#    #+#             */
/*   Updated: 2023/03/26 20:51:46 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It creates a new list element, and returns a pointer to it
 * 
 * @param content the content of the new list element
 * 
 * @return A pointer to a new list element.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*l;

	l = (t_list *) malloc(sizeof(t_list));
	if (!l)
		return (0);
	l->content = content;
	l->previous = 0;
	l->next = 0;
	return (l);
}
