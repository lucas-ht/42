/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 00:17:13 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/05 23:58:34 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int	swap(t_list2 **stack)
{
	t_list2	*l;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	l = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = 0;
	l->previous = *stack;
	l->next = (*stack)->next;
	(*stack)->next = l;
	return (1);
}

void	sa(t_stacks *stacks, int should_print)
{
	if (swap(&stacks->l[a]))
		if (should_print)
			ft_printf("sa\n");
}

void	sb(t_stacks *stacks, int should_print)
{
	if (swap(&stacks->l[b]))
		if (should_print)
			ft_printf("sb\n");
}

void	ss(t_stacks *stacks, int should_print)
{
	if (swap(&stacks->l[a]) && swap(&stacks->l[b]))
		if (should_print)
			ft_printf("ss\n");
}
