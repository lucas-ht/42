/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 04:58:47 by lucas             #+#    #+#             */
/*   Updated: 2023/02/12 14:25:31 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * It rotates the stack until the first element is the smallest,
 * then it swaps the first two elements
 * if the second element is smaller than the first
 * 
 * @param stacks the stacks struct
 */
static void	ft_post_chunk(t_stacks *stacks)
{
	t_value	*first;
	t_value	*last;
	t_value	*prev;

	first = (t_value *) stacks->l[A]->content;
	last = (t_value *) ft_lstlast(stacks->l[A])->content;
	while (first->rank + 1 >= last->rank)
	{
		rra(stacks);
		first = (t_value *) stacks->l[A]->content;
		prev = (t_value *) stacks->l[A]->next->content;
		if (first->rank > prev->rank)
			sa(stacks);
		first = (t_value *) stacks->l[A]->content;
		last = (t_value *) ft_lstlast(stacks->l[A])->content;
	}
}

/**
 * It checks if the first two elements of
 * the stack are in order, and if they are, it swaps them
 * 
 * @param stacks the stacks struct
 * 
 * @return the number of elements in the list.
 */
static void	ft_post_each(t_stacks *stacks)
{
	t_value	*current;
	t_value	*prev;

	if (!stacks->l[A] || !stacks->l[A]->next)
		return ;
	current = (t_value *) stacks->l[A]->content;
	prev = (t_value *) stacks->l[A]->next->content;
	if (current->rank == prev->rank + 1)
		sa(stacks);
}

/**
 * If the chunk size is 1,
 * push it to A, otherwise, if the value is the second largest, push it to A,
 * otherwise, if the value is the smallest, push it to A and rotate A, otherwise,
 * if the value is the second smallest, push it to A and rotate A
 * 
 * @param stacks the stacks struct
 * @param chunk the chunk of the stack we're sorting
 * 
 * @return A boolean value.
 */
static bool	ft_sort_move_if(t_stacks *stacks, int chunk)
{
	t_value	*value;

	if (ft_chunk_size(stacks, B, chunk) == 1)
		return (true);
	value = (t_value *) stacks->l[B]->content;
	if (value->rank == ft_find_largest(stacks, B, chunk) - 1)
		return (pa(stacks), false);
	if (value->rank == ft_find_smallest(stacks, B, chunk))
		return (pa(stacks), ra(stacks), false);
	if (value->rank == ft_find_smallest(stacks, B, chunk) + 1
		&& true)
		return (pa(stacks), ra(stacks), false);
	return (true);
}

/**
 * It moves the largest value in stack B to the top of stack B
 * 
 * @param stacks the stacks struct
 * @param largest the largest value in the chunk
 * @param chunk the size of the chunk we're currently sorting
 */
static void	ft_sort_move(t_stacks *stacks, int largest, int chunk)
{
	int		position;
	void	(*op)(t_stacks *stacks);
	t_value	*value;

	position = ft_find_position(stacks, B, largest);
	op = t_p(position <= stacks->len[B] / 2, rb, rrb);
	value = (t_value *) stacks->l[B]->content;
	while (value->rank != largest)
	{
		if (ft_sort_move_if(stacks, chunk))
			op(stacks);
		value = (t_value *) stacks->l[B]->content;
	}
}

/**
 * It sorts the stack by chunking it into groups of 3,
 * then sorting each chunk individually, then
 * sorting the chunks together
 * 
 * @param stacks the structure containing the stacks
 */
void	ft_sort_large(t_stacks *stacks)
{
	int		chunk;
	int		largest;

	ft_chunk(stacks);
	while (stacks->l[B])
	{
		chunk = ft_chunk_largest(stacks, B);
		while (stacks->l[B] && chunk == ft_chunk_largest(stacks, B))
		{
			largest = ft_find_largest(stacks, B, chunk);
			ft_sort_move(stacks, largest, chunk);
			pa(stacks);
			ft_post_each(stacks);
		}
		ft_post_chunk(stacks);
	}
}
