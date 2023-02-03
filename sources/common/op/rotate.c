/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 01:06:25 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/05 23:58:16 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int	rotate(t_list2 **stack)
{
	t_list2	*l;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	l = *stack;
	*stack = l->next;
	(*stack)->previous = 0;
	ft_lstadd_back2(stack, l);
	return (1);
}

void	ra(t_stacks *stacks, int should_print)
{
	if (rotate(&stacks->l[a]))
		if (should_print)
			ft_printf("ra\n");
}

void	rb(t_stacks *stacks, int should_print)
{
	if (rotate(&stacks->l[b]))
		if (should_print)
			ft_printf("rb\n");
}

void	rr(t_stacks *stacks, int should_print)
{
	if (rotate(&stacks->l[a]) && rotate(&stacks->l[b]))
		if (should_print)
			ft_printf("rr\n");
}

void	rx(t_stacks *stacks, int e, int should_print)
{
	if (!e)
		ra(stacks, should_print);
	else
		rb(stacks, should_print);
}
