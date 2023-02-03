/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 07:41:48 by lucas             #+#    #+#             */
/*   Updated: 2023/01/29 19:49:22 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * It takes a command and a previous command, and if
 * the previous command's input is a file, it checks
 * if the file is readable, and if it is, it sets
 * the previous command's input to the command's input,
 * and frees the command
 * 
 * @param cmd the current command
 * @param prev the previous command in the linked list
 * 
 * @return A pointer to a void.
 */
static void	*ft_loop_input(t_cmd *cmd, t_cmd *prev)
{
	int	i;

	if (prev->in.type[1] == IO_IFILE
		&& access(prev->in.file, R_OK) == ERROR_INT)
		return (ft_cmd_free(cmd), ft_warning(ERROR_FILE));
	if (prev->out.type[0] == IO_NONE)
		prev->out.type[0] = cmd->out.type[0];
	else
		prev->out.type[1] = cmd->out.type[0];
	free(prev->in.file);
	prev->in.file = ft_strdup(cmd->cmd);
	if (!prev->in.file)
		return (ft_warning(ERROR_PARSING));
	i = -1;
	while (cmd->av[++i])
	{
		prev->av = ft_split_insert(prev->av, cmd->av[i],
				ft_split_len(prev->av));
		if (!prev->av)
			return (ft_warning(ERROR_PARSING));
	}
	ft_cmd_free(cmd);
	return (0);
}

/**
 * It opens a file, and if it can't, it returns an error
 * 
 * @param cmd the current command
 * @param prev the previous command in the linked list
 * 
 * @return A pointer to a function.
 */
static void	*ft_loop_file(t_cmd *prev)
{
	int	fd;
	int	flags;

	if (prev->out.type[0] == IO_OFILE)
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	if (prev->out.type[0] == IO_APP)
		flags = O_WRONLY | O_CREAT | O_APPEND;
	fd = open(prev->out.file, flags, FILE_PERMISSION);
	if (fd == ERROR_INT)
		return (ft_warning(ERROR_PARSING));
	if (close(fd) == ERROR_INT)
		return (ft_warning(ERROR_PARSING));
	return (0);
}

/**
 * It takes a command and a previous command, and sets
 * the output of the command to the output of the
 * previous command
 * 
 * @param cmd the current command
 * @param prev the previous command in the pipeline
 * 
 * @return The address of the cmd struct.
 */
static void	*ft_loop_output(t_cmd *cmd, t_cmd *prev)
{
	int	i;

	if (!ft_is_flags(prev->out.type[0], IO_OFILE | IO_APP))
		return (cmd);
	ft_debug_parse(cmd, 0);
	if (ft_loop_file(prev) == ERROR)
		return (ft_cmd_free(cmd), ERROR);
	prev->out.type[0] = prev->out.type[1];
	prev->out.type[1] = cmd->out.type[0];
	free(prev->out.file);
	prev->out.file = ft_strdup(cmd->cmd);
	if (!prev->out.file)
		return (ft_warning(ERROR_PARSING));
	i = -1;
	while (cmd->av[++i])
	{
		prev->av = ft_split_insert(prev->av, cmd->av[i],
				ft_split_len(prev->av));
		if (!prev->av)
			return (ft_warning(ERROR_PARSING));
	}
	ft_cmd_free(cmd);
	return (0);
}

/**
 * It loops through the
 * command list, and if it finds a command that has a file descriptor as input or
 * output, it will set the file descriptor of the next command to the same value
 * 
 * @param cmd the current command
 * @param prev the previous command in the pipeline
 * 
 * @return a pointer to a t_cmd struct.
 */
void	*ft_loop(t_cmd *cmd, t_cmd *prev)
{
	if (!prev || ft_strchr(REDIR, *prev->cmd))
		return (cmd);
	if (ft_is_flags(prev->in.type[1], IO_IFILE | IO_DEL))
		return (ft_loop_input(cmd, prev));
	if (ft_is_flags(prev->out.type[0], IO_OFILE | IO_APP)
		&& ft_is_flags(prev->out.type[1], IO_OFILE | IO_APP))
		return (ft_loop_output(cmd, prev));
	return (cmd);
}
