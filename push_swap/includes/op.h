/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 00:16:35 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/05 23:58:56 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# include "libft.h"
# include "stacks.h"

int		swap(t_list2 **stack);
void	sa(t_stacks *stacks, int should_print);
void	sb(t_stacks *stacks, int should_print);
void	ss(t_stacks *stacks, int should_print);

int		push(t_list2 **stack1, t_list2 **stack2);
void	pa(t_stacks *stacks, int should_print);
void	pb(t_stacks *stacks, int should_print);

int		rotate(t_list2 **stack);
void	ra(t_stacks *stacks, int should_print);
void	rb(t_stacks *stacks, int should_print);
void	rr(t_stacks *stacks, int should_print);
void	rx(t_stacks *stacks, int e, int should_print);

int		reverse_rotate(t_list2 **stack);
void	rra(t_stacks *stacks, int should_print);
void	rrb(t_stacks *stacks, int should_print);
void	rrr(t_stacks *stacks, int should_print);
void	rrx(t_stacks *stacks, int e, int should_print);

#endif
