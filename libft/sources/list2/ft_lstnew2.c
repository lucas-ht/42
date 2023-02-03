/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 05:40:58 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/01 00:13:47 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list2	*ft_lstnew2(void *content)
{
	t_list2	*l;

	l = (t_list2 *) malloc(sizeof(t_list2));
	if (!l)
		return (0);
	l->content = content;
	l->previous = 0;
	l->next = 0;
	return (l);
}
