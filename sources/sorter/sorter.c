/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 08:38:09 by lucas             #+#    #+#             */
/*   Updated: 2023/02/11 05:03:35 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorter(t_stacks *stacks)
{
	if (ft_is_sorted(stacks))
		return ;
	if (stacks->len[A] <= 10)
		return (ft_sort_small(stacks));
	ft_sort_large(stacks);
}
