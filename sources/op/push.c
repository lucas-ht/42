/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 08:17:38 by lucas             #+#    #+#             */
/*   Updated: 2023/02/09 07:08:09 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

/**
 * It takes the first element of stack1 and adds it to the front of stack2
 * 
 * @param stack1 The stack to push from
 * @param stack2 the stack to push to
 * 
 * @return A boolean value.
 */
static bool	push(t_list **stack1, t_list **stack2)
{
	t_list	*first;

	if (!*stack1)
		return (false);
	first = *stack1;
	*stack1 = (*stack1)->next;
	if (*stack1)
		(*stack1)->previous = 0;
	ft_lstadd_front(stack2, first);
	return (true);
}

/**
 * It pushes the top element of stack B onto stack A
 * 
 * @param stacks a pointer to the t_stacks structure
 */
void	pa(t_stacks *stacks)
{
	if (!push(&stacks->l[B], &stacks->l[A]))
		return (ft_debug_warning(ERROR_OP, ft_op_str(PA)));
	ft_insert_op(stacks, PA);
	stacks->len[A]++;
	stacks->len[B]--;
}

/**
 * It pushes the top element of stack A onto stack B
 * 
 * @param stacks a pointer to the t_stacks struct
 */
void	pb(t_stacks *stacks)
{
	if (!push(&stacks->l[A], &stacks->l[B]))
		return (ft_debug_warning(ERROR_OP, ft_op_str(PB)));
	ft_insert_op(stacks, PB);
	stacks->len[A]--;
	stacks->len[B]++;
}
