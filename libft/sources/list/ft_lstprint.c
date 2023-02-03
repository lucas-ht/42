/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.4.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0/1/01 01:31:36 by lhutt             #+#    #+#             */
/*   Updated: 0/1/07 01:44:59 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		ft_printf("list (%d) @ %p:\n", i++, lst);
		ft_printf("previous: %p\n", lst->previous);
		if (lst->content)
			ft_printf("content : %x\n", *(int *) lst->content);
		else
			ft_printf("content : NULL\n");
		ft_printf("next    : %p\n\n", lst->next);
		lst = lst->next;
	}
}
