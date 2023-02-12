/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 03:46:26 by lucas             #+#    #+#             */
/*   Updated: 2023/02/12 09:14:23 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include "libft.h"

# define A							0
# define B							1

typedef struct s_value
{
	int								value;
	int								rank;
	int								chunk;
}	t_value;

typedef struct s_stacks
{
	int								len[2];
	t_list							*l[2];
	t_list							*op;
}	t_stacks;

void	ft_stack_print(t_stacks *stacks, int i);

#endif
