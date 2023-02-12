/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 07:26:16 by lucas             #+#    #+#             */
/*   Updated: 2023/02/12 07:28:00 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "error.h"
# include "stacks.h"
# include "op.h"

// parser/parser.c
t_stacks	*ft_parse(int ac, char **av);

// sorter/sorted.c
bool		ft_is_sorted(t_stacks *stacks);

#endif
