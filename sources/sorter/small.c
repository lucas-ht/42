/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 05:46:20 by lucas             #+#    #+#             */
/*   Updated: 2023/02/12 05:37:07 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * It sorts three elements in a stack
 * 
 * @param stacks the structure containing the stacks
 * @param i the stack to sort
 */
void	ft_sort_3(t_stacks *stacks, int i)
{
	int		n[3];
	void	(*sx)(t_stacks *stacks);
	void	(*rx)(t_stacks *stacks);
	void	(*rrx)(t_stacks *stacks);

	sx = t_p(i, sb, sa);
	rx = t_p(i, rb, ra);
	rrx = t_p(i, rrb, rra);
	n[0] = ((t_value *) ft_lstat(stacks->l[i], 0)->content)->rank;
	n[1] = ((t_value *) ft_lstat(stacks->l[i], 1)->content)->rank;
	n[2] = ((t_value *) ft_lstat(stacks->l[i], 2)->content)->rank;
	if (n[2] > n[0] && n[0] > n[1])
		sx(stacks);
	else if (n[0] > n[1] && n[1] > n[2])
		(sx(stacks), rrx(stacks));
	else if (n[0] > n[2] && n[2] > n[1])
		rx(stacks);
	else if (n[1] > n[2] && n[2] > n[0])
		(sx(stacks), rx(stacks));
	else if (n[1] > n[0] && n[0] > n[2])
		rrx(stacks);
}

/*
* Push the smallest number to stack b until there are only 3 numbers
* left on stack a.
*/

void	ft_sort_small(t_stacks *stacks)
{
	int	position;

	if (stacks->len[A] == 2)
	{
		ra(stacks);
		return ;
	}
	while (stacks->len[A] > 3)
	{
		position = ft_find_smallest(stacks, A, ft_chunk_smallest(stacks, A));
		position = ft_find_position(stacks, A, position);
		ft_move(stacks, A, position);
		pb(stacks);
	}
	ft_sort_3(stacks, A);
	while (stacks->l[B])
		pa(stacks);
}
