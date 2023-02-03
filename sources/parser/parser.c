/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:53:24 by lucas             #+#    #+#             */
/*   Updated: 2023/01/29 08:22:42 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * It returns the quote character
 * that is currently open, or false if there is no open quote
 * 
 * @param line the line to parse
 * @param p pointer to the beginning of the line
 * 
 * @return The quote character.
 */
char	ft_parse_quote(char *line, char *p)
{
	char	quote;

	quote = false;
	while (*line)
	{
		if (line > p)
			break ;
		if (ft_strchr(QUOTES, *line))
		{
			if (!quote)
				quote = *line;
			else if (quote == *line && p != line)
				quote = false;
		}
		line++;
	}
	return (quote);
}

/**
 * It prints out the contents of the linked list of commands
 * 
 * @param cmds a linked list of t_cmds
 */
static void	*ft_parse_post(t_list *cmds)
{
	t_cmd	*cmd;
	t_cmd	*prev;
	t_cmd	*next;

	while (cmds)
	{
		cmd = (t_cmd *) cmds->content;
		prev = 0;
		if (cmds->previous)
			prev = (t_cmd *) cmds->previous->content;
		next = 0;
		if (cmds->next)
			next = (t_cmd *) cmds->next->content;
		ft_debug_parse(cmd, prev);
		if (ft_parse_error(cmd, next, prev) == ERROR)
			return (ERROR);
		cmds = cmds->next;
	}
	return (0);
}

/**
 * It takes a list of commands,
 * and returns a token of the list
 * 
 * @param cmds a NULL-terminated array of strings, each string being a command
 * 
 * @return A list of commands.
 */
static t_list	*ft_parse_cmds(char **cmds)
{
	int		i;
	t_list	*list;
	t_cmd	*cmd;

	i = -1;
	list = 0;
	while (cmds[++i])
	{
		cmd = ft_cmd(cmds[i], ft_lstlast(list));
		if (cmd == ERROR)
			return (ft_lstclear(&list, ft_cmd_free), ERROR);
		if (cmd)
			ft_lstadd_back(&list, ft_lstnew((void *) cmd));
	}
	return (list);
}

/**
 * It takes a line,
 * trims it, and then returns the result of `venv_line` on it
 * 
 * @param line the line to parse
 * 
 * @return A pointer to a string.
 */
static char	*ft_parse_prompt(char *line)
{
	if (!line || !*line || ft_striter_if(line, ft_iswhite))
		return (ERROR);
	add_history(line);
	line = ft_strtrim(line, SPACES);
	if (!line)
		return (ft_warning(ERROR_PARSING));
	return (line);
}

/**
 * It takes a string, splits it into commands,
 * and parses each command into a list of tokens
 * 
 * @param line the line to parse
 * 
 * @return A list of commands.
 */
t_list	*ft_parse(char *line)
{
	char	*prompt;
	char	**cmds;
	t_list	*list;

	prompt = ft_parse_prompt(line);
	if (prompt == ERROR)
		return (ERROR);
	cmds = ft_split_cmds(prompt);
	free(prompt);
	if (cmds == ERROR)
		return (ERROR);
	list = ft_parse_cmds(cmds);
	ft_free_split(cmds);
	if (list == ERROR)
		return (ERROR);
	if (ft_parse_post(list) == ERROR)
		return (ft_lstclear(&list, ft_cmd_free), ERROR);
	return (list);
}
