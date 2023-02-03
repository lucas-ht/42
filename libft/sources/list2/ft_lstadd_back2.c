/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 05:55:45 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/04 23:40:06 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back2(t_list2 **lst, t_list2 *new)
{
	t_list2	*l;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		if (new)
			new->previous = 0;
		return ;
	}
	l = ft_lstlast2(*lst);
	if (l)
		l->next = new;
	if (!new)
		return ;
	new->previous = l;
	new->next = 0;
}
