/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 05:57:30 by lucas             #+#    #+#             */
/*   Updated: 2023/01/26 03:13:05 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include "parser.h"

# define FD_IN				0
# define FD_OUT				1
# define FORK_CHILD			0
# define FILE_PERMISSION	0664

// exec.c
void	ft_exec(t_list *cmds);

// file.c
bool	ft_file(t_list *cmds, int (*pipes)[2], int *prev);

// extern.c
void	*ft_extern_exec(t_cmd *cmd);

// builtin.c
bool	ft_is_builtin(t_cmd *cmd);
int		ft_builtin_exec(t_cmd *cmd);

#endif