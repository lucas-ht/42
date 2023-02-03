/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 02:21:09 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/06 04:32:05 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "stacks.h"
# include "op.h"
# include "parser.h"
# include "sorted.h"

char	**ft_reader(void);
int		ft_isop(char **s);

void	ft_op(t_stacks *stacks, char *op, int verbose);
void	ft_checker(t_stacks *stacks, char **op, int verbose);

#endif
