/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 02:22:57 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/06 02:56:31 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* Bruteforce tht most optimize solution for 3 numbers.
*/

void	ft_sort_3(t_stacks *stacks)
{
	int	n[3];

	n[0] = *(int *) ft_lstat2(stacks->l[a], 0)->content;
	n[1] = *(int *) ft_lstat2(stacks->l[a], 1)->content;
	n[2] = *(int *) ft_lstat2(stacks->l[a], 2)->content;
	if (n[2] > n[0] && n[0] > n[1])
		sa(stacks, 1);
	else if (n[0] > n[1] && n[1] > n[2])
	{
		sa(stacks, 1);
		rra(stacks, 1);
	}
	else if (n[0] > n[2] && n[2] > n[1])
		ra(stacks, 1);
	else if (n[1] > n[2] && n[2] > n[0])
	{
		sa(stacks, 1);
		ra(stacks, 1);
	}
	else if (n[1] > n[0] && n[0] > n[2])
		rra(stacks, 1);
}

/*
* Push the smallest number to stack b until there are only 3 numbers
* left on stack a.
*/

void	ft_sort_small(t_stacks *stacks)
{
	if (stacks->len[a] == 2)
	{
		ra(stacks, 1);
		return ;
	}
	while (stacks->len[a] > 3)
	{
		ft_sort_push(stacks, a, ft_sort_find_smallest(stacks, a));
		pb(stacks, 1);
	}
	ft_sort_3(stacks);
	while (stacks->l[b])
		pa(stacks, 1);
}
