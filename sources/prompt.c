/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:16:38 by lhutt             #+#    #+#             */
/*   Updated: 2023/01/29 02:51:41 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell	g_shell;

/**
 * It takes the current working directory
 * and replaces the user's home directory with a tilde.
 *
 * @return The path of the current directory.
 */
static char	*ft_prompt_path(void)
{
	char	*path;
	char	*temp;
	int		len;

	path = ft_strjoin("/Users/", g_shell.user);
	if (!path)
		return (0);
	len = ft_strlen(path);
	if (!ft_strncmp(g_shell.path, path, len))
	{
		(free(path), temp = ft_strdup(&g_shell.path[len]));
		if (!temp)
			return (0);
		free((path = ft_strjoin("~", temp), temp));
	}
	else
		(free(path), path = ft_strdup(g_shell.path));
	return (path);
}

/**
 * It prints the prompt
 *
 * @return A string with the user, path, and $
 */
char	*ft_prompt_print(void)
{
	char	*prompt;
	char	*path;

	prompt = ft_strjoin(RLS COLOR_GREY_LIGHT RLE, g_shell.user);
	if (!prompt)
		return (0);
	prompt = ft_strjoin_free(prompt,
			RLS COLOR_GREY RLE ": " RLS COLOR_INFO RLE);
	if (!prompt)
		return (0);
	path = ft_prompt_path();
	if (!path)
		return (0);
	free((prompt = ft_strjoin_free(prompt, path), path));
	if (!prompt)
		return (0);
	return (ft_strjoin_free(prompt,
			" " RLS COLOR_ACCENT RLE PROMPT_INPUT RLS COLOR_RESET RLE " "));
}

/**
 * It reads a line from the standard input and parses it
 */
void	ft_prompt(void)
{
	char	*prompt;
	char	*line;
	t_list	*cmds;

	prompt = ft_prompt_print();
	if (!prompt)
		return ;
	line = readline((const char *) prompt);
	free(prompt);
	if (!line)
		(key_add("?", "0", &g_shell.lst_env), g_shell.running = false);
	free((cmds = ft_parse(line), line));
	if (cmds == ERROR)
		return ;
	(ft_exec(cmds), ft_lstclear(&cmds, ft_cmd_free));
}
