/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 08:34:17 by lucas             #+#    #+#             */
/*   Updated: 2023/01/30 02:46:30 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * It takes a string, and if it starts with a tilde,
 * it replaces it with the user's home directory
 * 
 * @param line the line to be parsed
 * 
 * @return A pointer to a string.
 */
char	*ft_special_tilde(char *line)
{
	char	*tilde;

	if (!line)
		return (ERROR);
	if (*line != '~' || (line[1] && line[1] != '/'))
	{
		tilde = ft_strdup(line);
		if (!tilde)
			return (ft_warning(ERROR_PARSING));
		return (tilde);
	}
	tilde = (char *) ft_calloc(ft_strlen(getenv("HOME"))
			+ ft_strlen(line), sizeof(char));
	if (!tilde)
		return (ft_warning(ERROR_PARSING));
	ft_strlcpy(tilde, getenv("HOME"), ft_strlen(getenv("HOME")) + 1);
	ft_strlcpy(&tilde[ft_strlen(tilde)], &line[1], ft_strlen(line));
	return (tilde);
}

/**
 * It takes a string,
 * checks if it's a valid environment variable, and if so, returns the
 * value of that variable, with quotes removed
 * 
 * @param av the argument passed to the function
 * 
 * @return A pointer to a string.
 */
static char	*ft_special_parse(char *av)
{
	char	*tilde;
	char	*venv;
	char	*quotes;

	tilde = ft_special_tilde(av);
	if (tilde == ERROR)
		return (ERROR);
	venv = venv_line(tilde);
	free(tilde);
	if (venv == ERROR)
		return (ERROR);
	if (!*venv)
		return (free(venv), (void *) 0);
	quotes = ft_quotes(venv);
	free(venv);
	if (quotes == ERROR)
		return (ERROR);
	return (quotes);
}

/**
 * It splits the command name
 * and arguments by spaces, and then inserts the arguments into the command's
 * argument list
 * 
 * @param cmd a pointer to the command structure
 * @param name the name of the command
 * 
 * @return The name of the command.
 */
static char	*ft_special_cmd_space(t_cmd *cmd, char *name)
{
	char	**av;
	int		i;

	av = ft_split(name, SPACES);
	if (!av)
		return (ft_warning(ERROR_PARSING));
	free(name);
	name = ft_strdup(*av);
	if (!name)
		return (ft_free_split(av), ft_warning(ERROR_PARSING));
	i = 0;
	while (av[++i])
	{
		cmd->av = ft_split_insert(cmd->av, av[i], ft_split_len(cmd->av));
		if (!cmd->av)
			return (free(name), ft_free_split(av), ft_warning(ERROR_PARSING));
	}
	ft_free_split(av);
	return (name);
}

/**
 * It parses the command
 * line for special characters and replaces them with their corresponding
 * environment variable
 * 
 * @param cmd The command to be parsed.
 * 
 * @return a pointer to a void.
 */
static void	*ft_special_cmd(t_cmd *cmd)
{
	char	*name;
	int		i;

	name = ft_special_parse(cmd->cmd);
	if (!name || name == ERROR)
		return (ERROR);
	i = -1;
	while (!ft_strchr(SPACES, name[++i]))
		;
	if (name[i])
		name = ft_special_cmd_space(cmd, name);
	if (name == ERROR)
		return (ERROR);
	free(cmd->cmd);
	cmd->cmd = ft_strlower(name);
	free(name);
	if (!cmd->cmd)
		return (ft_warning(ERROR_PARSING));
	return (0);
}

/**
 * It takes a command, splits it into arguments,
 * and then replaces the arguments with the expanded
 * version of the arguments
 * 
 * @param cmd the command structure
 * 
 * @return a pointer to a char **.
 */
void	*ft_special(t_cmd *cmd)
{
	char	**av;
	int		i;
	int		j;

	if (ft_special_cmd(cmd) == ERROR)
		return (ERROR);
	av = (char **) ft_calloc(ft_split_len(cmd->av) + 1, sizeof(char *));
	if (!av)
		return (ft_warning(ERROR_PARSING));
	i = -1;
	j = -1;
	while (cmd->av[++i])
	{
		av[++j] = ft_special_parse(cmd->av[i]);
		if (av[j] == ERROR)
			return (ft_split_error(av, --j), ERROR);
		if (!av[j])
			j--;
	}
	av[++j] = 0;
	ft_free_split(cmd->av);
	cmd->av = av;
	cmd->ac = ft_split_len(cmd->av);
	return (0);
}
