/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:42:56 by lucas             #+#    #+#             */
/*   Updated: 2023/01/29 05:43:32 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * It prints a nice header and footer for the debug output
 * 
 * @param is_start if true, the function will print the start of the debug block
 * @param is_end if true, the function will print the end of the debug box
 * @param name The name of the function you're debugging.
 */
static void	ft_debug_format(bool is_start, bool is_end, char *name)
{
	int	i;

	if (is_start)
	{
		i = 49 - ft_strlen(name) / 2;
		ft_putstr_fd("\n" COLOR_GREY_DARK, 1);
		while (i--)
			ft_putstr_fd("━", 1);
		ft_putstr_fd(" " COLOR_RESET, 1);
		ft_putstr_fd(name, 1);
		ft_putstr_fd(COLOR_RESET " " COLOR_GREY_DARK, 1);
		i = 49 - ft_strlen(name) / 2;
		while (i--)
			ft_putstr_fd("━", 1);
		ft_putendl_fd(COLOR_GREY_LIGHT, 1);
	}
	if (is_end)
	{
		ft_putstr_fd(COLOR_RESET COLOR_GREY_DARK, 1);
		i = 100;
		while (i--)
			ft_putstr_fd("━", 1);
		ft_putendl_fd(COLOR_RESET "\n", 1);
	}
}

/**
 * It prints the leaks of the program if the DEBUG flag is set
 * It's a preprocessor directive. It's a way to conditionally compile code.
 */
#if DEBUG_LEAKS == 1

void	ft_debug_leaks(void)
{
	ft_debug_format(true, false, "LEAKS");
	system("leaks minishell");
	ft_debug_format(false, true, 0);
}
#else

void	ft_debug_leaks(void)
{
	return ;
}
#endif

/**
 * It prints out the contents of a t_cmd struct
 * 
 * @param cmd the command to be parsed
 * @param prev the previous command in the linked list
 * 
 * @return The return value of the last command executed.
 */
void	ft_debug_parse(t_cmd *cmd, t_cmd *prev)
{
	int		i;

	if (!DEBUG)
		return ;
	(ft_debug_format(!prev, false, "PARSING"));
	printf("cmd                 : %s\n", cmd->cmd);
	printf("ac                  : %d\n", cmd->ac);
	i = -1;
	while (cmd->av && cmd->av[++i])
		printf("av[%d]               : %s\n", i, cmd->av[i]);
	printf("input.type[0]       : %s\n", ft_flags_str(cmd->in.type[0]));
	printf("input.type[1]       : %s\n", ft_flags_str(cmd->in.type[1]));
	printf("input.file          : %s\n", cmd->in.file);
	printf("output.type[0]      : %s\n", ft_flags_str(cmd->out.type[0]));
	printf("output.type[1]      : %s\n", ft_flags_str(cmd->out.type[1]));
	printf("output.file         : %s\n", cmd->out.file);
	ft_putchar_fd('\n', 1);
}

/**
 * It prints the content of a t_cmd struct
 * 
 * @param cmds the list of commands
 * @param pipes the pipes that are used to communicate between processes.
 * @param prev the file descriptor of the previous pipe.
 */
void	ft_debug_process(t_list *cmds, int pipes[2], int prev)
{
	t_cmd	*cmd;
	int		i;

	if (!DEBUG)
		return ;
	cmd = (t_cmd *) cmds->content;
	if (!cmds->previous)
		ft_debug_format(!cmds->previous, false, "PROCESS");
	printf("cmd                 : %s\n", cmd->cmd);
	printf("ac                  : %d\n", cmd->ac);
	i = -1;
	while (cmd->av && cmd->av[++i])
		printf("av[%d]               : %s\n", i, cmd->av[i]);
	printf("pipes[FD_IN]        : %d\n", pipes[0]);
	printf("pipes[FD_OUT]       : %d\n", pipes[1]);
	printf("prev                : %d\n", prev);
	if (!cmds->next)
		ft_debug_format(false, !cmds->next, 0);
	else
		ft_putchar_fd('\n', 1);
}
