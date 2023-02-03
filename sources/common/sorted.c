/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 02:16:33 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/05 02:19:04 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorted.h"

/*
* Checks if stack a is sorted and stack b is empty.
*/

int	ft_is_sorted(t_stacks *stacks)
{
	t_list2	*l;
	int		n;

	if (!stacks || !stacks->l[a] || stacks->l[b])
		return (0);
	l = stacks->l[a];
	n = *(int *) l->content;
	while (l)
	{
		if (!l->content || n > *(int *) l->content)
			return (0);
		n = *(int *) l->content;
		l = l->next;
	}
	return (1);
}
