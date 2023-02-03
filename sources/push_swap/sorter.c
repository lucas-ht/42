/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 02:38:15 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/06 00:47:01 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* Determines the algorithm to use and sets a range accordingly.
*/

void	ft_sorter(t_stacks *stacks)
{
	t_range	range;

	if (ft_is_sorted(stacks))
		return ;
	if (stacks->len[a] <= 10)
	{
		ft_sort_small(stacks);
		return ;
	}
	if (stacks->len[a] <= 100)
		range.increment = 25;
	else
		range.increment = 500 / 11;
	range.start = *(int *) ft_lstat2(stacks->l[a],
			ft_sort_find_smallest(stacks, a))->content;
	range.end = range.start + range.increment;
	ft_sort_large(stacks, &range);
}
