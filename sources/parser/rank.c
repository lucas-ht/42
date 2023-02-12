/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 06:50:08 by lucas             #+#    #+#             */
/*   Updated: 2023/02/12 14:23:06 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * It returns the numers of chunks.
 * 
 * @param len the length of the string
 * 
 * @return The number of chunks.
 */
static int	ft_rank_chunk_n(int len)
{
	if (len <= 10)
		return (0);
	if (len <= 20)
		return (3);
	if (len <= 50)
		return (6);
	if (len <= 100)
		return (7);
	if (len <= 150)
		return (8);
	if (len <= 200)
		return (9);
	if (len <= 300)
		return (11);
	if (len <= 400)
		return (13);
	if (len <= 500)
		return (15);
	if (len <= 600)
		return (17);
	if (len <= 800)
		return (19);
	if (len <= 1500)
		return (21);
	return (25);
}

/**
 * It assigns a chunk number to each value in the stack
 * 
 * @param stacks the structure containing the stacks
 */
static void	ft_rank_chunk(t_stacks *stacks)
{
	int		n;
	int		range;
	t_list	*list;
	t_value	*value;

	n = 1;
	range = stacks->len[A] / ft_rank_chunk_n(stacks->len[A]) + 1;
	while (n <= ft_rank_chunk_n(stacks->len[A]))
	{
		list = stacks->l[A];
		while (list)
		{
			value = (t_value *) list->content;
			if (value->rank < range * n && !value->chunk)
				value->chunk = n;
			list = list->next;
		}
		n++;
	}
}

/**
 * It assigns a rank to each element in the stack
 * 
 * @param stacks The structure that holds the stacks.
 */
void	ft_rank(t_stacks *stacks)
{
	t_list	*list;
	t_list	*next;
	t_value	*value;

	list = stacks->l[A];
	while (list)
	{
		next = stacks->l[A];
		value = (t_value *) list->content;
		while (next)
		{
			if (value->value > ((t_value *) next->content)->value)
				value->rank++;
			next = next->next;
		}
		list = list->next;
	}
	ft_rank_chunk(stacks);
}
