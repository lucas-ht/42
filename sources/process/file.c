/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:09:27 by lucas             #+#    #+#             */
/*   Updated: 2023/01/29 08:34:54 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * It reads input from the user
 * until the delimiter is reached,
 * then writes the input to the pipe
 * 
 * @param cmd The command that is being executed.
 * @param pipes The pipes that are used to
 * communicate between the parent and child.
 */
static void	ft_file_delimiter_child(t_cmd *cmd, int pipes[2])
{
	char	*line;

	ft_signal_disable();
	while (true)
	{
		line = readline((const char *) "> ");
		if (!line || (cmd->in.file && ft_strlen(cmd->in.file) == ft_strlen(line)
				&& !ft_strncmp(cmd->in.file, line, ft_strlen(line))))
			break ;
		ft_putendl_fd(line, pipes[FD_OUT]);
		free(line);
	}
	close(pipes[FD_IN]);
	close(pipes[FD_OUT]);
	exit(0);
}

/**
 * It creates a pipe, forks, and in the child process,
 * it opens the file and writes to the pipe, and in
 * the parent process, it closes the write end of
 * the pipe and sets the read end of the pipe as the
 * input for the next command
 * 
 * @param cmd the command to be executed
 * @param prev the previous file descriptor
 * 
 * @return A boolean value.
 */
static bool	ft_file_delimiter(t_cmd *cmd, int *prev)
{
	pid_t	pchild;
	int		pipes[2];

	if (cmd->in.type[0] != IO_DEL)
		return (true);
	if (pipe(pipes) == ERROR_INT)
		ft_error(ERROR_PIPE);
	pchild = fork();
	if (pchild == FORK_CHILD)
		ft_file_delimiter_child(cmd, pipes);
	else if (pchild > FORK_CHILD)
	{
		wait(0);
		if (close(pipes[FD_OUT]) == ERROR_INT)
			ft_error(ERROR_PIPE);
		if (*prev != STDIN_FILENO && close(*prev) == ERROR_INT)
			ft_error(ERROR_PIPE);
		*prev = pipes[FD_IN];
	}
	else
		ft_error(ERROR_FORK);
	return (true);
}

/**
 * It opens the file for reading, and if it fails, it prints an error message
 * 
 * @param cmd The command to be executed.
 * @param prev the file descriptor of the previous command's output
 * 
 * @return A boolean value.
 */
static bool	ft_file_input(t_cmd *cmd, int *prev)
{
	if (cmd->in.type[0] != IO_IFILE)
		return (true);
	if (!cmd->in.file || access(cmd->in.file, R_OK) == ERROR_INT)
		return (ft_warning(ERROR_FILE), false);
	if (*prev != STDIN_FILENO && close(*prev) == ERROR_INT)
		ft_error(ERROR_PIPE);
	*prev = open(cmd->in.file, O_RDONLY);
	if (*prev == ERROR_INT)
		return (ft_warning(ERROR_FILE), false);
	return (true);
}

/**
 * It opens the file for writing, and returns false if it fails
 * 
 * @param cmd the command to execute
 * @param pipes This is the pipe array
 * that we will use to pass the file descriptor to the child
 * process.
 * 
 * @return A boolean value.
 */
static bool	ft_file_output(t_cmd *cmd, int (*pipes)[2])
{
	int	flags;

	if (!ft_is_flags(cmd->out.type[0], IO_OFILE | IO_APP))
		return (true);
	if ((*pipes)[FD_OUT] != STDOUT_FILENO
		&& close((*pipes)[FD_OUT]) == ERROR_INT)
		ft_error(ERROR_PIPE);
	if (cmd->out.type[0] == IO_OFILE)
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	if (cmd->out.type[0] == IO_APP)
		flags = O_WRONLY | O_CREAT | O_APPEND;
	(*pipes)[FD_OUT] = open(cmd->out.file, flags, FILE_PERMISSION);
	if ((*pipes)[FD_OUT] == ERROR_INT)
		return (ft_warning(ERROR_FILE), false);
	return (true);
}

/**
 * It closes the input pipe if the previous command didn't output
 * to the next command, and it opens the output pipe if the next
 * command doesn't input from the previous command
 * 
 * @param cmds a list of commands
 * @param pipes the pipes array
 * @param prev the file descriptor of the previous command's output
 * 
 * @return A boolean value.
 */
bool	ft_file(t_list *cmds, int (*pipes)[2], int *prev)
{
	t_cmd	*cmd;
	t_cmd	*previous;

	cmd = (t_cmd *) cmds->content;
	if (ft_special(cmd) == ERROR)
		return (false);
	if (cmds->previous)
		previous = (t_cmd *) cmds->previous->content;
	if (cmds->previous && previous->out.type[0] != IO_NEXT)
	{
		if (close(*prev) == ERROR_INT)
			return (ft_warning(ERROR_FILE), false);
		*prev = STDIN_FILENO;
	}
	if (!ft_file_input(cmd, prev))
		return (false);
	if (!ft_file_output(cmd, pipes))
		return (false);
	if (!ft_file_delimiter(cmd, prev))
		return (false);
	return (true);
}
