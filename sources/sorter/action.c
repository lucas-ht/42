/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 07:25:11 by lucas             #+#    #+#             */
/*   Updated: 2023/02/12 09:08:58 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * It finds the position of a value in a stack
 * 
 * @param stacks the structure containing the stacks
 * @param i the stack to search
 * @param rank the rank of the value we're looking for
 * 
 * @return The position of the value in the list.
 */
int	ft_find_position(t_stacks *stacks, int i, int rank)
{
	t_list	*list;
	t_value	*value;
	int		position;

	list = stacks->l[i];
	position = 0;
	while (list)
	{
		value = (t_value *) list->content;
		if (value->rank == rank)
			return (position);
		position++;
		list = list->next;
	}
	return (ERROR_INT);
}

/**
 * It finds the largest value in a chunk
 * 
 * @param stacks the stacks struct
 * @param i the stack we're looking at
 * @param chunk the chunk we're looking for
 * 
 * @return The rank of the largest value in the chunk.
 */
int	ft_find_largest(t_stacks *stacks, int i, int chunk)
{
	t_list	*list;
	t_value	*value;
	int		rank;

	list = stacks->l[i];
	value = (t_value *) list->content;
	while (list && value->chunk != chunk)
	{
		list = list->next;
		value = (t_value *) list->content;
	}
	if (!list)
		ft_debug_warning(ERROR_ACTION, "action_largest");
	rank = value->rank;
	while (list)
	{
		value = (t_value *) list->content;
		if (value->chunk == chunk)
			rank = t(value->rank > rank, value->rank, rank);
		list = list->next;
	}
	return (rank);
}

/**
 * It finds the smallest value in a chunk
 * 
 * @param stacks the stacks struct
 * @param i the stack to search
 * @param chunk the chunk we're looking for
 * 
 * @return The rank of the smallest value in the chunk
 */
int	ft_find_smallest(t_stacks *stacks, int i, int chunk)
{
	t_list	*list;
	t_value	*value;
	int		rank;

	list = stacks->l[i];
	if (!list)
		ft_debug_warning(ERROR_ACTION, "action_smallest");
	value = (t_value *) list->content;
	while (list && value->chunk != chunk)
	{
		list = list->next;
		if (list)
			value = (t_value *) list->content;
	}
	if (!list)
		ft_debug_warning(ERROR_ACTION, "action_smallest");
	rank = value->rank;
	while (list)
	{
		value = (t_value *) list->content;
		if (value->chunk == chunk)
			rank = t(value->rank < rank, value->rank, rank);
		list = list->next;
	}
	return (rank);
}

/**
 * It moves the top of the stack to the position specified
 * 
 * @param stacks the structure containing the stacks
 * @param i the stack we're working on
 * @param position the position of the element in the stack
 */
void	ft_move(t_stacks *stacks, int i, int position)
{
	void	*value;
	void	(*op)(t_stacks *stacks);

	value = ft_lstat(stacks->l[i], position)->content;
	op = t_p(position <= stacks->len[i] / 2, t_p(i, rb, ra), t_p(i, rrb, rra));
	while (stacks->l[i]->content != value)
		op(stacks);
}
