/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 07:11:41 by lucas             #+#    #+#             */
/*   Updated: 2023/02/12 14:25:12 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * It returns the number of elements in a stack that are in a given chunk
 * 
 * @param stacks The stacks struct
 * @param i the stack to check
 * @param chunk the chunk we're looking for
 * 
 * @return The size of the chunk.
 */
int	ft_chunk_size(t_stacks *stacks, int i, int chunk)
{
	t_list	*list;
	t_value	*value;
	int		size;

	list = stacks->l[i];
	size = 0;
	while (list)
	{
		value = (t_value *) list->content;
		size = t(value->chunk == chunk, size + 1, size);
		list = list->next;
	}
	return (size);
}

/**
 * It returns the largest chunk in a stack
 * 
 * @param stacks The stacks struct
 * @param i the stack to check
 * 
 * @return The largest chunk.
 */
int	ft_chunk_largest(t_stacks *stacks, int i)
{
	t_list	*list;
	t_value	*value;
	int		largest;

	list = stacks->l[i];
	value = (t_value *) list->content;
	largest = value->chunk;
	while (list)
	{
		value = (t_value *) list->content;
		largest = t(value->chunk > largest, value->chunk, largest);
		list = list->next;
	}
	return (largest);
}

/**
 * It returns the smallest chunk in a stack
 * 
 * @param stacks The stacks struct
 * @param i the stack to check
 * 
 * @return The smallest chunk in the list.
 */
int	ft_chunk_smallest(t_stacks *stacks, int i)
{
	t_list	*list;
	t_value	*value;
	int		smallest;

	list = stacks->l[i];
	value = (t_value *) list->content;
	smallest = value->chunk;
	while (list)
	{
		value = (t_value *) list->content;
		smallest = t(value->chunk < smallest, value->chunk, smallest);
		list = list->next;
	}
	return (smallest);
}

/**
 * It returns the position of the closest value to the chunk
 * 
 * @param stacks The stacks struct
 * @param chunk the chunk we're looking for
 * 
 * @return The position of the closest chunk.
 */
static int	ft_chunk_closest(t_stacks *stacks, int chunk)
{
	t_list	*list;
	t_value	*value;
	int		position;

	position = 0;
	list = stacks->l[A];
	while (list)
	{
		value = (t_value *) list->content;
		if (value->chunk == chunk || value->chunk == chunk + 1)
			break ;
		list = list->next;
		position++;
	}
	return (position);
}

/**
 * It takes the smallest chunk of values
 * from the stack A and moves them to the stack B
 * 
 * @param stacks the stacks struct
 */
void	ft_chunk(t_stacks *stacks)
{
	int		chunk;
	int		position;
	t_value	*value;

	while (stacks->l[A])
	{
		chunk = ft_chunk_smallest(stacks, A);
		while (stacks->l[A] && chunk == ft_chunk_smallest(stacks, A))
		{
			position = ft_chunk_closest(stacks, chunk);
			ft_move(stacks, A, position);
			pb(stacks);
			value = (t_value *) stacks->l[B]->content;
			if (value->chunk != chunk)
				rb(stacks);
		}
	}
}
