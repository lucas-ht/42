/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 22:24:05 by lhutt             #+#    #+#             */
/*   Updated: 2022/11/30 23:45:35 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list2	*ft_lstma2(t_list2 *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list2	*l;
	t_list2	*n;
	void	*content;

	if (!lst || !f || !del)
		return (0);
	l = 0;
	while (lst)
	{
		content = f(lst->content);
		n = ft_lstnew2(content);
		if (!n)
		{
			ft_lstclear2(&l, del);
			del(content);
			return (0);
		}
		ft_lstadd_back2(&l, n);
		lst = lst->next;
	}
	return (l);
}
