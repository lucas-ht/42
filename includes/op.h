/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 08:31:44 by lucas             #+#    #+#             */
/*   Updated: 2023/02/12 03:57:07 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# include "libft.h"
# include "stacks.h"
# include "error.h"

typedef enum e_op
{
	OP_NONE							= 0,
	SA								= 1,
	SB								= 2,
	SS								= 3,
	PA								= 4,
	PB								= 5,
	RA								= 6,
	RB								= 7,
	RR								= 8,
	RRA								= 9,
	RRB								= 10,
	RRR								= 11
}	t_op;

// op.c
void	ft_insert_op(t_stacks *stacks, t_op op);
char	*ft_op_str(t_op op);
void	ft_op_print(t_stacks *stacks);

// swap.c
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);

// push.c
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);

// rotate.c
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);

// reverse_rotate.c
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);

#endif
