/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:46:15 by lucas             #+#    #+#             */
/*   Updated: 2023/01/24 05:11:42 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * It checks if the command is a builtin
 * 
 * @param cmd The command to be executed.
 * 
 * @return A boolean value.
 */
bool	ft_is_builtin(t_cmd *cmd)
{
	int		len;

	len = ft_strlen(cmd->cmd);
	if (!ft_strncmp(cmd->cmd, "echo", len) && len == 4)
		return (true);
	if (!ft_strncmp(cmd->cmd, "cd", len) && len == 2)
		return (true);
	if (!ft_strncmp(cmd->cmd, "pwd", len) && len == 3)
		return (true);
	if (!ft_strncmp(cmd->cmd, "export", len) && len == 6)
		return (true);
	if (!ft_strncmp(cmd->cmd, "unset", len) && len == 5)
		return (true);
	if (!ft_strncmp(cmd->cmd, "env", len) && len == 3)
		return (true);
	if (!ft_strncmp(cmd->cmd, "exit", len) && len == 4)
		return (true);
	return (false);
}

/**
 * It executes builtin commands
 * 
 * @param cmd The command to be executed.
 */

int	ft_builtin_exec(t_cmd *cmd)
{
	int	len;

	len = ft_strlen(cmd->cmd);
	if (!ft_strncmp(cmd->cmd, "echo", len))
		return (ft_echo(cmd));
	if (!ft_strncmp(cmd->cmd, "cd", len))
		return (ft_cd(cmd));
	if (!ft_strncmp(cmd->cmd, "pwd", len))
		return (ft_pwd(cmd));
	if (!ft_strncmp(cmd->cmd, "export", len))
		return (ft_export(cmd));
	if (!ft_strncmp(cmd->cmd, "unset", len))
		return (ft_unset(cmd));
	if (!ft_strncmp(cmd->cmd, "env", len))
		return (ft_env(cmd));
	if (!ft_strncmp(cmd->cmd, "exit", len))
		return (ft_exit(cmd));
	return (EXEC_ERROR);
}
