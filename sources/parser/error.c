/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:41:09 by lucas             #+#    #+#             */
/*   Updated: 2023/01/29 04:16:20 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * It checks for unclosed quotes
 * 
 * @param cmd the current command
 * @param next the next command in the list
 * @param prev the previous command in the linked list
 * 
 * @return A pointer to a function that takes a
 * t_cmd pointer and returns a void pointer.
 */
static void	*ft_parse_error_syntax(t_cmd *cmd, t_cmd *prev)
{
	char	*last;

	last = ft_split_last(cmd->av);
	if (last && ft_strchr(REDIR, *last))
		return (ft_warning_input(ERROR_PARSING_INPUT, last));
	if (cmd->cmd && ft_strchr(REDIR, *cmd->cmd) && prev)
		return (ft_warning_input(ERROR_PARSING_INPUT, cmd->cmd));
	return (0);
}

/**
 * It checks if the output is valid
 * 
 * @param cmd the current command
 * @param next the next command in the list
 * @param prev The previous command in the pipeline.
 * 
 * @return A pointer to a function
 * that takes a t_cmd pointer and returns a void pointer.
 */
static void	*ft_parse_error_output(t_cmd *cmd, t_cmd *next)
{
	if (!next && cmd->out.type[0] == IO_NEXT)
		return (ft_warning_input(ERROR_PARSING_INPUT, "|"));
	if (!next && cmd->out.type[1] != IO_NONE)
		return (ft_warning(ERROR_PARSING));
	if (!next && ft_is_flags(IO_NEXT, cmd->out.type[0] | cmd->out.type[1]))
		return (ft_warning_input(ERROR_PARSING_INPUT, "|"));
	if (ft_is_flags(cmd->out.type[0], IO_OFILE | IO_APP) && !cmd->out.file)
		return (ft_warning(ERROR_PARSING_FOUTPUT));
	if (ft_is_flags(IO_ERR, cmd->out.type[0] | cmd->out.type[1]))
		return (ft_warning(ERROR_PARSING));
	return (0);
}

/**
 * It checks if the input is valid
 * 
 * @param cmd the current command
 * @param next the next command in the list
 * @param prev the previous command in the list
 * 
 * @return A pointer to a function that takes a
 * t_cmd pointer and returns a void pointer.
 */
static void	*ft_parse_error_input(t_cmd *cmd, t_cmd *next, t_cmd *prev)
{
	if (ft_strchr(REDIR, *cmd->cmd) && (!prev || !next))
		return (ft_warning_input(ERROR_PARSING_INPUT, cmd->cmd));
	if (ft_is_flags(cmd->in.type[0], IO_IFILE | IO_DEL) && !cmd->in.file)
		return (ft_warning(ERROR_PARSING_FINPUT));
	if (ft_is_flags(IO_ERR, cmd->in.type[0] | cmd->in.type[1]))
		return (ft_warning(ERROR_PARSING));
	return (0);
}

/**
 * It checks if there are any errors in the command list
 * 
 * @param list a linked list of t_cmd structures.
 * 
 * @return true if there is an error in the parsing of the command.
 */
void	*ft_parse_error(t_cmd *cmd, t_cmd *next, t_cmd *prev)
{
	if (!cmd || !cmd->cmd || !cmd->av)
		return (ft_warning(ERROR_PARSING));
	if (ft_parse_error_syntax(cmd, prev) == ERROR)
		return (ERROR);
	if (ft_parse_error_output(cmd, next) == ERROR)
		return (ERROR);
	if (ft_parse_error_input(cmd, next, prev) == ERROR)
		return (ERROR);
	return (0);
}
