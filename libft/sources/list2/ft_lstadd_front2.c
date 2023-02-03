/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 05:45:24 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/02 05:39:47 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front2(t_list2 **lst, t_list2 *new)
{
	new->previous = 0;
	new->next = *lst;
	if (new->next)
		new->next->previous = new;
	*lst = new;
}
