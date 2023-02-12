/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 00:17:13 by lhutt             #+#    #+#             */
/*   Updated: 2023/02/09 07:11:18 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

/**
 * It swaps the first two elements of a linked list
 * 
 * @param stack a pointer to the stack to swap
 * 
 * @return a boolean value.
 */
static bool	swap(t_list **stack)
{
	t_list	*first;

	if (ft_lstsize(*stack) < 2)
		return (false);
	first = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = 0;
	first->previous = *stack;
	first->next = (*stack)->next;
	(*stack)->next = first;
	if (first->next)
		first->next->previous = first;
	return (true);
}

/**
 * It swaps the first two elements of the stack
 * 
 * @param stacks a pointer to the t_stacks struct
 */
void	sa(t_stacks *stacks)
{
	if (!swap(&stacks->l[A]))
		return (ft_debug_warning(ERROR_OP, ft_op_str(SA)));
	ft_insert_op(stacks, SA);
}

/**
 * It swaps the first two elements of the stack
 * 
 * @param stacks a pointer to the t_stacks struct
 */
void	sb(t_stacks *stacks)
{
	if (!swap(&stacks->l[B]))
		return (ft_debug_warning(ERROR_OP, ft_op_str(SB)));
	ft_insert_op(stacks, SB);
}

/**
 * It swaps the first two elements of both stacks
 * 
 * @param stacks a pointer to the t_stacks struct
 */
void	ss(t_stacks *stacks)
{
	if (ft_lstsize(stacks->l[A]) < 2 || ft_lstsize(stacks->l[B]) < 2)
		return (ft_debug_warning(ERROR_OP, ft_op_str(SS)));
	(swap(&stacks->l[A]), swap(&stacks->l[B]));
	ft_insert_op(stacks, SS);
}
