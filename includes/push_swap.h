/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:20:44 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/05 02:56:28 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stacks.h"
# include "op.h"
# include "parser.h"
# include "sorted.h"

void	ft_sorter(t_stacks *stacks);

int		ft_sort_find_largest(t_stacks *stacks, int e);
int		ft_sort_find_smallest(t_stacks *stacks, int e);
void	ft_sort_push(t_stacks *stacks, int e, int i);

void	ft_sort_3(t_stacks *stacks);
void	ft_sort_small(t_stacks *stacks);

void	ra_optimized(t_stacks *stacks, int i);
void	rra_optimized(t_stacks *stacks, int i);

int		ft_sort_large_top(t_stacks *stacks, t_range *range);
int		ft_sort_large_bottom(t_stacks *stacks, t_range *range);
void	ft_sort_large_push(t_stacks *stacks, t_range *range);
void	ft_sort_large(t_stacks *stacks, t_range *range);

#endif
