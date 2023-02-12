/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 01:35:08 by lucas             #+#    #+#             */
/*   Updated: 2023/02/12 08:05:08 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

/**
 * It creates a new operation,
 * adds it to the end of the list of operations,
 * 
 * @param stacks a pointer to the stacks structure
 * @param op The operation to be inserted.
 */
void	ft_insert_op(t_stacks *stacks, t_op op)
{
	t_op	*pop;
	t_list	*list;

	pop = (t_op *) ft_calloc(1, sizeof(t_op));
	if (!pop)
		ft_error(ERROR_FATAL);
	*pop = op;
	list = ft_lstnew((void *) pop);
	if (!list)
		ft_error(ERROR_FATAL);
	ft_lstadd_back(&stacks->op, list);
}

/**
 * It returns a string
 * representation of the operation
 * 
 * @param op the operation to be performed
 * 
 * @return A string that corresponds to the operation.
 */
char	*ft_op_str(t_op op)
{
	if (op == SA)
		return ("sa");
	if (op == SB)
		return ("sb");
	if (op == SS)
		return ("ss");
	if (op == PA)
		return ("pa");
	if (op == PB)
		return ("pb");
	if (op == RA)
		return ("ra");
	if (op == RB)
		return ("rb");
	if (op == RR)
		return ("rr");
	if (op == RRA)
		return ("rra");
	if (op == RRB)
		return ("rrb");
	if (op == RRR)
		return ("rrr");
	return (0);
}

/**
 * If the current operation and the next operation are the same,
 * but for the stack they operate on,
 * then replace the current operation with the combined operation
 * and set the next operation to OP_NONE
 * 
 * @param op the current operation
 * @param next the next operation in the list
 */
static void	ft_op_optimize(t_op *op, t_op *next)
{
	if ((*op == SA && *next == SB) || (*op == SB && *next == SA))
	{
		*op = SS;
		*next = OP_NONE;
	}
	if ((*op == RA && *next == RB) || (*op == RB && *next == RA))
	{
		*op = RR;
		*next = OP_NONE;
	}
	if ((*op == RRA && *next == RRB) || (*op == RRB && *next == RRA))
	{
		*op = RRR;
		*next = OP_NONE;
	}
}

/**
 * It prints the operations
 * that have been performed on the stacks
 * 
 * @param stacks The structure that contains the stacks and the operations.
 */
void	ft_op_print(t_stacks *stacks)
{
	t_list	*list;
	t_op	*op;
	t_op	*next;

	list = stacks->op;
	while (list)
	{
		op = (t_op *) list->content;
		if (list->next)
		{
			next = (t_op *) list->next->content;
			ft_op_optimize(op, next);
		}
		if (*op != OP_NONE)
			ft_printf("%s\n", ft_op_str(*op));
		list = list->next;
	}
}
