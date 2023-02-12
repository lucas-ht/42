/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 01:14:57 by lucas             #+#    #+#             */
/*   Updated: 2023/02/12 03:56:45 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

/**
 * It takes the last element of the list and puts it at the front
 * 
 * @param stack a pointer to a pointer to the first element of the stack
 * 
 * @return A pointer to the first element of the list.
 */
static bool	reverse_rotate(t_list **stack)
{
	t_list	*last;

	if (ft_lstsize(*stack) < 2)
		return (false);
	last = ft_lstlast(*stack);
	last->previous->next = 0;
	ft_lstadd_front(stack, last);
	return (true);
}

/**
 * It takes the last element of the stack A and puts it at the front
 * 
 * @param stacks a pointer to the t_stacks structure
 */
void	rra(t_stacks *stacks)
{
	if (!reverse_rotate(&stacks->l[A]))
		return (ft_debug_warning(ERROR_OP, ft_op_str(RRA)));
	ft_insert_op(stacks, RRA);
}

/**
 * It takes the last element of the stack A and puts it at the front
 * 
 * @param stacks a pointer to the t_stacks struct
 */
void	rrb(t_stacks *stacks)
{
	if (!reverse_rotate(&stacks->l[B]))
		return (ft_debug_warning(ERROR_OP, ft_op_str(RRB)));
	ft_insert_op(stacks, RRB);
}

/**
 * It takes the last element of both stacks and puts it at the front
 * 
 * @param stacks a pointer to the t_stacks struct
 */
void	rrr(t_stacks *stacks)
{
	if (ft_lstsize(stacks->l[A]) < 2 || ft_lstsize(stacks->l[B]) < 2)
		return (ft_debug_warning(ERROR_OP, ft_op_str(RRR)));
	(reverse_rotate(&stacks->l[A]), reverse_rotate(&stacks->l[B]));
	ft_insert_op(stacks, RRR);
}
