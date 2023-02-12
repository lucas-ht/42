/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 05:35:37 by lucas             #+#    #+#             */
/*   Updated: 2023/02/11 04:57:52 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * It returns true if the list is sorted, false otherwise
 * 
 * @param stacks The stacks struct that contains the stacks.
 * 
 * @return A boolean value.
 */
bool	ft_is_sorted(t_stacks *stacks)
{
	t_list	*list;
	t_value	*prev;
	t_value	*value;

	list = stacks->l[A];
	prev = 0;
	while (list)
	{
		value = (t_value *) list->content;
		if (prev && prev->value > value->value)
			return (false);
		prev = value;
		list = list->next;
	}
	return (true);
}
