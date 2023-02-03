/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extern.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:32:55 by matfranc          #+#    #+#             */
/*   Updated: 2023/02/03 01:01:13 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell	g_shell;

/**
 * It checks if a file is a directory
 * 
 * @param path The path to the file.
 * 
 * @return The return value is a boolean value.
 */
static bool	ft_extern_isdir(char *path)
{
	struct stat	s;

	if (!stat(path, &s))
		return (!!(s.st_mode & S_IFDIR));
	else
		return (ft_warning(ERROR_FILE), false);
}

/**
 * It takes a command and a path, and if the command
 * is executable in the path, it executes it
 * 
 * @param cmd a pointer to a t_cmd struct.
 * @param path the path to the directory to search in
 * 
 * @return The return value of the function is a boolean.
 */
static bool	ft_extern_path(t_cmd *cmd, char *path)
{
	char	*command;

	command = ft_strjoin3(path, "/", cmd->cmd);
	if (!command)
		return (false);
	if (access(command, X_OK) != -1)
	{
		if (ft_extern_isdir(command))
			return (ft_warning(ERROR_DIR), false);
		cmd->av = ft_split_insert(cmd->av, command, 0);
		if (!cmd->av)
			return (free(command), false);
		execve(command, cmd->av, g_shell.envp);
	}
	return (free(command), true);
}

/**
 * It takes a command, and if it's not a builtin,
 * it will try to find it in the PATH
 * 
 * @param cmd a pointer to a t_cmd struct.
 * 
 * @return the value of the key in the list.
 */
static void	ft_extern_paths(t_cmd *cmd)
{
	t_venv	*path;
	char	**paths;
	int		i;

	path = key_get("PATH", &g_shell.lst_env);
	if (!path)
		return ;
	paths = ft_split(path->value, ":");
	if (!paths)
		return ;
	i = -1;
	while (paths[++i] && ft_extern_path(cmd, paths[i]))
		;
	ft_free_split(paths);
}

/*
 * It checks if the command is an absolute path,
 * and if it is, it checks if it's executable, and if it
 * is, it checks if it's a directory, and if it isn't, it executes it
 * 
 * @param cmd a pointer to a t_cmd structure.
 * 
 * @return The return value of the function.
 */
static void	ft_exec_absolute(t_cmd *cmd)
{
	char	*path;

	if (*cmd->cmd == '/')
		path = ft_strdup(cmd->cmd);
	else
		path = ft_strjoin("/", cmd->cmd);
	if (!path)
		return ((void) ft_warning(ERROR_EXTERN));
	if (access(path, X_OK) != -1)
	{
		if (ft_extern_isdir(path))
			return ((void) ft_warning(ERROR_DIR));
		cmd->av = ft_split_insert(cmd->av, path, 0);
		if (!cmd->av)
			return ((void) ft_warning(ERROR_EXTERN));
		execve(path, cmd->av, g_shell.envp);
	}
	free(path);
}

/**
 * It checks if the command is a relative path,
 * if it is, it adds the current working directory to the
 * command, then it checks if the command
 * is an absolute path, if it is, it executes the command, if it
 * isn't, it returns an error
 * 
 * @param cmd the command to execute
 * 
 * @return The return value of the function is a pointer to a void.
 */
void	*ft_extern_exec(t_cmd *cmd)
{
	char	*path;

	if (!ft_strncmp(cmd->cmd, "./", 2))
	{
		path = (char *) ft_calloc(ft_strlen(g_shell.path)
				+ ft_strlen(cmd->cmd), sizeof(char));
		if (!path)
			return (ft_warning(ERROR_EXTERN));
		ft_strlcpy(path, g_shell.path, ft_strlen(g_shell.path) + 1);
		path[ft_strlen(g_shell.path)] = '/';
		ft_strlcpy(&path[ft_strlen(g_shell.path) + 1], &cmd->cmd[2],
			ft_strlen(cmd->cmd) - 1);
		cmd->cmd = (free(cmd->cmd), path);
	}
	errno = 0;
	if (ft_extern_paths(cmd), errno && errno != 2)
		return (ft_warning(ERROR_EXTERN));
	else if (ft_exec_absolute(cmd), errno && errno != 2)
		return (ft_warning(ERROR_EXTERN));
	else
		return (errno = 0, ft_warning_input(ERROR_UNKNOWN, cmd->cmd));
	return (EXEC_SUCCESS);
}
