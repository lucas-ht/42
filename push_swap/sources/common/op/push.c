/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 00:32:55 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/06 00:48:27 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int	push(t_list2 **stack1, t_list2 **stack2)
{
	t_list2	*l;

	if (!stack1 || !*stack1 || !stack2)
		return (0);
	l = *stack1;
	*stack1 = (*stack1)->next;
	if (*stack1)
		(*stack1)->previous = 0;
	ft_lstadd_front2(stack2, l);
	return (1);
}

void	pa(t_stacks *stacks, int should_print)
{
	if (push(&stacks->l[b], &stacks->l[a]))
	{
		if (should_print)
			ft_printf("pa\n");
		stacks->len[a]++;
		stacks->len[b]--;
	}
}

void	pb(t_stacks *stacks, int should_print)
{
	if (push(&stacks->l[a], &stacks->l[b]))
	{
		if (should_print)
			ft_printf("pb\n");
		stacks->len[a]--;
		stacks->len[b]++;
	}
}
