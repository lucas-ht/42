/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:26:21 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/05 00:15:50 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include "libft.h"

typedef struct s_stacks
{
	struct s_list2	*l[2];
	int				len[2];
}	t_stacks;

enum e_stacks {	a, b };

typedef struct s_range
{
	int		start;
	int		end;
	int		increment;
}	t_range;

#endif
