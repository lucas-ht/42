/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:29:10 by lucas             #+#    #+#             */
/*   Updated: 2023/01/29 03:52:33 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "libft.h"
# include "parser.h"

# ifndef DEBUG
#  define DEBUG				0
# endif
# ifndef DEBUG_LEAKS
#  define DEBUG_LEAKS		0
# endif

void	ft_debug_leaks(void);
void	ft_debug_parse(t_cmd *cmd, t_cmd *prev);
void	ft_debug_process(t_list *cmds, int pipes[2], int prev);

#endif