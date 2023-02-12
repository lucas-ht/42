/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 01:06:25 by lhutt             #+#    #+#             */
/*   Updated: 2023/02/12 03:56:54 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

/**
 * It rotates the stack by
 * moving the first element to the end of the stack
 * 
 * @param stack a pointer to a pointer to the first element of the list
 * 
 * @return A boolean value.
 */
static bool	rotate(t_list **stack)
{
	t_list	*first;

	if (ft_lstsize(*stack) < 2)
		return (false);
	first = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = 0;
	ft_lstadd_back(stack, first);
	return (true);
}

/**
 * It rotates the stack by
 * moving the first element to the end of the stack
 * 
 * @param stack a pointer to a pointer to the first element of the list
 */
void	ra(t_stacks *stacks)
{
	if (!rotate(&stacks->l[A]))
		return (ft_debug_warning(ERROR_OP, ft_op_str(RA)));
	ft_insert_op(stacks, RA);
}

/**
 * It rotates the stack by
 * moving the first element to the end of the stack
 * 
 * @param stack a pointer to a pointer to the first element of the list
 */
void	rb(t_stacks *stacks)
{
	if (!rotate(&stacks->l[B]))
		return (ft_debug_warning(ERROR_OP, ft_op_str(RB)));
	ft_insert_op(stacks, RB);
}

/**
 * It rotates the stacks by
 * moving the first element to the end of the stack
 * 
 * @param stack a pointer to a pointer to the first element of the list
 */
void	rr(t_stacks *stacks)
{
	if (ft_lstsize(stacks->l[A]) < 2 || ft_lstsize(stacks->l[B]) < 2)
		return (ft_debug_warning(ERROR_OP, ft_op_str(RR)));
	(rotate(&stacks->l[A]), rotate(&stacks->l[B]));
	ft_insert_op(stacks, RR);
}
