/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 01:25:43 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/05 23:57:50 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int	reverse_rotate(t_list2 **stack)
{
	t_list2	*l;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	l = ft_lstlast2(*stack);
	if (!l || !l->previous)
		return (0);
	l->previous->next = 0;
	ft_lstadd_front2(stack, l);
	return (1);
}

void	rra(t_stacks *stacks, int should_print)
{
	if (reverse_rotate(&stacks->l[a]))
		if (should_print)
			ft_printf("rra\n");
}

void	rrb(t_stacks *stacks, int should_print)
{
	if (reverse_rotate(&stacks->l[b]))
		if (should_print)
			ft_printf("rrb\n");
}

void	rrr(t_stacks *stacks, int should_print)
{
	if (reverse_rotate(&stacks->l[a]) && reverse_rotate(&stacks->l[b]))
		if (should_print)
			ft_printf("rrr\n");
}

void	rrx(t_stacks *stacks, int e, int should_print)
{
	if (!e)
		rra(stacks, should_print);
	else
		rrb(stacks, should_print);
}
