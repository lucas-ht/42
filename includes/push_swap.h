/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 03:45:26 by lucas             #+#    #+#             */
/*   Updated: 2023/02/12 13:25:21 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "error.h"
# include "stacks.h"
# include "op.h"

// parser/parser.c
t_stacks	*ft_parse(int ac, char **av);

// rank/rank.c
void		ft_rank(t_stacks *stacks);

// rank/chunk.c
int			ft_chunk_size(t_stacks *stacks, int i, int chunk);
int			ft_chunk_largest(t_stacks *stacks, int i);
int			ft_chunk_smallest(t_stacks *stacks, int i);
void		ft_chunk(t_stacks *stacks);

// sorter/action.c
int			ft_find_position(t_stacks *stacks, int i, int rank);
int			ft_find_largest(t_stacks *stacks, int i, int chunk);
int			ft_find_smallest(t_stacks *stacks, int i, int chunk);
void		ft_move(t_stacks *stacks, int i, int position);

// sorter/sorter.c
void		ft_sorter(t_stacks *stacks);

// sorter/sorted.c
bool		ft_is_sorted(t_stacks *stacks);

// sorter/small.c
void		ft_sort_3(t_stacks *stacks, int i);
void		ft_sort_small(t_stacks *stacks);

// sorter/large.c
void		ft_sort_large(t_stacks *stacks);

#endif
