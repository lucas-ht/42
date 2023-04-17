/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:51:51 by lucas             #+#    #+#             */
/*   Updated: 2023/03/26 20:51:56 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It prints the content of a linked list
 * 
 * @param lst the list to print
 */
void	ft_lstprint(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		printf("list (%d) @ %p:\n", i++, (void *) lst);
		ft_printf("previous: %p\n", lst->previous);
		if (lst->content)
			ft_printf("content : %p\n", lst->content);
		else
			ft_printf("content : (null)\n");
		ft_printf("next    : %p\n\n", lst->next);
		lst = lst->next;
	}
}
