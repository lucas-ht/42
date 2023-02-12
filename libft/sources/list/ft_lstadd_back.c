/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.4.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0/11/03 05:55:45 by lhutt             #+#    #+#             */
/*   Updated: 0/1/04 3:40:06 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
