/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.4.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0/1/01 0:46:1 by lhutt             #+#    #+#             */
/*   Updated: 03/01/08 18:8:55 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
