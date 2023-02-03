/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 04:25:39 by lhutt             #+#    #+#             */
/*   Updated: 2023/01/29 04:46:27 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"

/**
 * It counts the number of commands in a line
 * 
 * @param line the line to be parsed
 * 
 * @return The number of commands in the line.
 */
static int	ft_split_cmds_count(char *line)
{
	int	c;
	int	i;

	c = 1;
	i = -1;
	while (line[++i])
	{
		if (ft_parse_quote(line, &line[i]))
			continue ;
		if (line[i + 1] && !ft_strchr(REDIR, line[i + 1]))
			c = t(!!ft_strchr(REDIR, line[i]), c + 1, c);
	}
	return (c);
}

/**
 * It splits the command from the rest of the line
 * 
 * @param line the line to be parsed
 * 
 * @return A string containing the command.
 */
static char	*ft_split_cmd(char *line)
{
	int		i;
	char	*command;

	i = -1;
	while (line[++i])
	{
		if (ft_parse_quote(line, &line[i]))
			continue ;
		if (ft_strchr(REDIR, line[i]) && line[i + 1]
			&& !ft_strchr(REDIR, line[i + 1]))
			break ;
	}
	if (line[i])
		++i;
	command = (char *) ft_calloc(i + 1, sizeof(char));
	if (!command)
		return (ft_warning(ERROR_PARSING));
	command[i] = 0;
	while (--i >= 0)
		command[i] = line[i];
	return (command);
}

/**
 * It splits a line into commands, and returns an array of commands
 * 
 * @param line the line to be parsed
 * 
 * @return a pointer to a pointer to a char.
 */
char	**ft_split_cmds(char *line)
{
	int		i;
	char	**commands;

	commands = (char **) ft_calloc(ft_split_cmds_count(line) + 1,
			sizeof(char *));
	if (!commands)
		return (ft_warning(ERROR_PARSING));
	i = 0;
	while (*line)
	{
		commands[i] = ft_split_cmd(line);
		if (commands[i] == ERROR)
			return (ft_split_error(commands, i), ERROR);
		line += ft_strlen(commands[i]) * sizeof(char);
		i++;
	}
	commands[i] = 0;
	return (commands);
}
