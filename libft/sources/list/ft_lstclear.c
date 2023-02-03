/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.4.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0/11/03 :13:3 by lhutt             #+#    #+#             */
/*   Updated: 0/11/30 3:44:47 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*l;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		l = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = l;
	}
}
