/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 01:36:43 by lucas             #+#    #+#             */
/*   Updated: 2023/01/26 03:12:36 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell	g_shell;

/**
 * It takes a list of commands, a pipe, and a previous file descriptor,
 * and forks a child process that will execute the command in the list
 * 
 * @param cmd the current command to execute
 * @param pipes the pipes that are used to communicate between the processes
 * @param prev the previous pipe's input
 */
static void	ft_exec_fork(t_list *cmd, int pipes[2], int prev)
{
	if (prev != STDIN_FILENO)
	{
		if (dup2(prev, STDIN_FILENO) == ERROR_INT)
			ft_error(ERROR_PIPE);
		if (close(prev) == ERROR_INT)
			ft_error(ERROR_PIPE);
	}
	if (pipes[FD_OUT] != STDOUT_FILENO)
	{
		if (dup2(pipes[FD_OUT], STDOUT_FILENO) == ERROR_INT)
			ft_error(ERROR_PIPE);
		if (close(pipes[FD_OUT]) == ERROR_INT)
			ft_error(ERROR_PIPE);
	}
	ft_extern_exec((t_cmd *) cmd->content);
	exit(127);
}

/**
 * It forks a child process, and if the child process is created,
 * it executes the command, otherwise it exits with a status of 127
 * 
 * @param cmd the command to be executed
 * @param pipes the pipes that are used to communicate between the processes
 * @param prev is the previous pipe, if there is one.
 */
static void	ft_exec_extern(t_list *cmd, int pipes[2], int prev)
{
	pid_t	pchild;
	int		code;
	char	*status;

	pchild = fork();
	code = 0;
	if (pchild == FORK_CHILD)
		ft_exec_fork(cmd, pipes, prev);
	else if (pchild > FORK_CHILD)
	{
		wait(&code);
		status = ft_itoa(code);
		(key_add("?", status, &g_shell.lst_env), free(status));
	}
	else
		ft_error(ERROR_FORK);
}

/**
 * It executes a builtin command, and if there's a next command,
 * it redirects the output to the next command's input
 * 
 * @param cmd the current command to execute
 * @param pipes the pipes that are used to communicate between the processes
 */
static void	ft_exec_builtin(t_list *cmd, int pipes[2])
{
	int		fd_backup;
	int		code;
	char	*status;

	fd_backup = dup(STDOUT_FILENO);
	if (fd_backup == ERROR_INT)
		ft_error(ERROR_PIPE);
	if (dup2(pipes[FD_OUT], STDOUT_FILENO) == ERROR_INT)
		ft_error(ERROR_PIPE);
	if (dup2(pipes[FD_OUT], STDOUT_FILENO) == ERROR_INT)
		ft_error(ERROR_PIPE);
	code = ft_builtin_exec((t_cmd *) cmd->content);
	status = ft_itoa(code);
	if (dup2(fd_backup, STDOUT_FILENO) == ERROR_INT)
		ft_error(ERROR_PIPE);
	(key_add("?", status, &g_shell.lst_env), free(status));
}

/**
 * It takes a list of commands, and executes them one by one,
 * piping the output of each command to the input of the next
 * 
 * @param cmds a linked list of commands
 */
void	ft_exec(t_list *cmds)
{
	int	pipes[2];
	int	prev;

	pipes[FD_IN] = STDIN_FILENO;
	prev = STDIN_FILENO;
	while (cmds)
	{
		if (cmds->next && pipe(pipes) == ERROR_INT)
			ft_error(ERROR_PIPE);
		if (!cmds->next)
			pipes[FD_OUT] = STDOUT_FILENO;
		if (!ft_file(cmds, &pipes, &prev))
			break ;
		ft_debug_process(cmds, pipes, prev);
		if (ft_is_builtin((t_cmd *) cmds->content))
			ft_exec_builtin(cmds, pipes);
		else
			ft_exec_extern(cmds, pipes, prev);
		if (prev != STDIN_FILENO && close(prev) == ERROR_INT)
			ft_error(ERROR_PIPE);
		if (pipes[FD_OUT] != STDOUT_FILENO && close(pipes[FD_OUT]) == ERROR_INT)
			ft_error(ERROR_PIPE);
		prev = pipes[FD_IN];
		cmds = cmds->next;
	}
}
