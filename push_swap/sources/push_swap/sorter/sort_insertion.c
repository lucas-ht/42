/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 00:31:57 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/06 02:55:41 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* Finds the index of the closest number in the range
* starting at the top.
*/

int	ft_sort_large_top(t_stacks *stacks, t_range *range)
{
	int		i;
	t_list2	*stack;

	i = 0;
	stack = stacks->l[a];
	while (stack)
	{
		if (*(int *) stack->content >= range->start
			&& *(int *) stack->content <= range->end)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

/*
* Finds the index of the closest number in the range
* starting at the bottom.
*/

int	ft_sort_large_bottom(t_stacks *stacks, t_range *range)
{
	int		i;
	t_list2	*stack;

	i = ft_lstsize2(stacks->l[a]) - 1;
	stack = ft_lstlast2(stacks->l[a]);
	while (stack)
	{
		if (*(int *) stack->content >= range->start
			&& *(int *) stack->content <= range->end)
			return (i);
		stack = stack->previous;
		i--;
	}
	return (-1);
}

void	ft_sort_large_push(t_stacks *stacks, t_range *range)
{
	int	f[2];

	while (stacks->l[a])
	{
		f[0] = ft_sort_large_top(stacks, range);
		f[1] = ft_sort_large_bottom(stacks, range);
		if (f[0] == -1)
		{
			range->end += range->increment;
			continue ;
		}
		if (f[0] <= (stacks->len[a]) / 2)
			while (f[0]--)
				ra(stacks, 1);
		else
			while (f[1]++ < stacks->len[a])
				rra(stacks, 1);
		pb(stacks, 1);
	}
}

void	ft_sort_large(t_stacks *stacks, t_range *range)
{
	int	t;

	ft_sort_large_push(stacks, range);
	while (stacks->l[b])
	{
		t = ft_sort_find_largest(stacks, b);
		if (t < (stacks->len[b]) / 2)
			while (t--)
				rb(stacks, 1);
		else
			while (t++ < stacks->len[b])
				rrb(stacks, 1);
		pa(stacks, 1);
	}
}
