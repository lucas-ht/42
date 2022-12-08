/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 05:00:54 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/06 00:38:49 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_find_largest(t_stacks *stacks, int e)
{
	int		i;
	int		p;

	i = 0;
	p = 0;
	while (ft_lstat2(stacks->l[e], i))
	{
		if (*(int *) ft_lstat2(stacks->l[e], i)->content
			> *(int *) ft_lstat2(stacks->l[e], p)->content)
			p = i;
		i++;
	}
	return (p);
}

int	ft_sort_find_smallest(t_stacks *stacks, int e)
{
	int		i;
	int		p;

	i = 0;
	p = 0;
	while (ft_lstat2(stacks->l[e], i))
	{
		if (*(int *) ft_lstat2(stacks->l[e], i)->content
			< *(int *) ft_lstat2(stacks->l[e], p)->content)
			p = i;
		i++;
	}
	return (p);
}

void	ft_sort_push(t_stacks *stacks, int e, int i)
{
	if (i <= (stacks->len[e]) / 2)
		while (i--)
			rx(stacks, e, 1);
	else
		while (i++ < stacks->len[e])
			rrx(stacks, e, 1);
}
