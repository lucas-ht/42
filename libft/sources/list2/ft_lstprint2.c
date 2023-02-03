/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 01:31:36 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/07 01:44:59 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint2(t_list2 *lst)
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
