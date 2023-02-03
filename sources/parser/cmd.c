/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:25:32 by lucas             #+#    #+#             */
/*   Updated: 2023/01/30 00:49:56 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * It frees the memory allocated for a command
 * 
 * @param c the command to free
 */
void	ft_cmd_free(void *c)
{
	t_cmd	*cmd;

	cmd = (t_cmd *) c;
	(free(cmd->in.file));
	(free(cmd->out.file));
	(free(cmd->cmd), ft_free_split(cmd->av), free(cmd));
}

/**
 * It initializes a command
 * structure with the command name and arguments
 * 
 * @param cmd The command structure to be filled.
 * @param av The arguments of the command.
 * 
 * @return A pointer to a command struct.
 */
static void	*ft_cmd_init(t_cmd *cmd, char **av, t_cmd *prev)
{
	char	*last;

	cmd->cmd = ft_strdup(*av++);
	if (!cmd->cmd)
		return (ft_warning(ERROR_PARSING));
	last = (char *) t_p(!!*av, (void *) ft_split_last(av), (void *) cmd->cmd);
	cmd->av = ft_split_ncopy(av, t(!!ft_strchr(REDIR, *last),
				ft_split_len(av) - 1, ft_split_len(av)));
	if (!cmd->av)
		return (ft_warning(ERROR_PARSING));
	cmd->ac = ft_split_len(cmd->av);
	cmd->in.type[0] = IO_NONE;
	if (prev && ft_is_flags(IO_NEXT, prev->out.type[0] | prev->out.type[1]))
		cmd->in.type[0] = IO_PREV;
	cmd->in.type[1] = IO_NONE;
	cmd->in.file = 0;
	cmd->out.type[0] = IO_NONE;
	cmd->out.type[1] = IO_NONE;
	cmd->out.file = 0;
	if (ft_flags(last) & (IO_IN | IO_ERR))
		cmd->in.type[0] = ft_flags(last);
	else if (ft_flags(last) & (IO_OUT | IO_ERR))
		cmd->out.type[0] = ft_flags(last);
	return (0);
}

/**
 * It takes a string, splits it into arguments,
 * checks if the command is a previous command redirection, and if
 * it's not, it creates a new command and initializes it
 * 
 * @param str the string to be parsed
 * @param p the list of commands
 * 
 * @return A pointer to a t_cmd struct.
 */
t_cmd	*ft_cmd(char *str, t_list *p)
{
	char	**av;
	t_cmd	*cmd;
	t_cmd	*prev;

	av = ft_split_args(str);
	if (av == ERROR)
		return (ERROR);
	prev = 0;
	if (p)
		prev = (t_cmd *) p->content;
	if (ft_prev(av, prev))
		return (ft_free_split(av), (void *) 0);
	cmd = (t_cmd *) ft_calloc(1, sizeof(t_cmd));
	if (!cmd)
		return (ft_free_split(av), ft_warning(ERROR_PARSING));
	if (ft_cmd_init(cmd, av, prev) == ERROR)
		return (ft_free_split(av), ERROR);
	cmd = ft_loop(cmd, prev);
	if (!cmd || cmd == ERROR)
		return (ft_free_split(av), cmd);
	ft_free_split(av);
	return (cmd);
}
