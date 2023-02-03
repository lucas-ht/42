/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prev.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:28:48 by lucas             #+#    #+#             */
/*   Updated: 2023/01/26 07:41:36 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * It takes a command and
 * replaces it with a new command if it's a redirection
 * 
 * @param prev the previous command in the linked list
 * 
 * @return the number of arguments in the array.
 */
static void	ft_redirection_special(t_cmd *prev)
{
	if (!ft_strchr(REDIR_IN REDIR_OUT, *prev->cmd))
		return ;
	if (ft_split_len(prev->av))
	{
		(free(prev->cmd), prev->cmd = ft_strdup(prev->av[0]));
		prev->av = ft_split_pop(prev->av, 0);
		return ;
	}
	if (ft_flags(prev->cmd) == IO_IFILE)
		(free(prev->cmd), prev->cmd = ft_strdup("less"));
	else if (ft_flags(prev->cmd) == IO_DEL)
		(free(prev->cmd), prev->cmd = ft_strdup("cat"));
	else
	{
		(free(prev->cmd), prev->cmd = ft_strdup("cat"));
		if (prev->in.type[0] == IO_NONE)
		{
			prev->in.type[0] = IO_DEL;
			prev->in.file = ft_strdup("\0");
		}
	}
}

/**
 * It takes a command and a pointer to an array of strings,
 * and it fills the command's av and
 * redirection fields with the strings in the array
 * 
 * @param av the array of arguments
 * @param prev the previous command
 * 
 * @return the value of the first element of the array.
 */
static void	ft_prev_av(char **av, t_cmd *prev)
{
	while (*av && !ft_strchr(REDIR, **av))
	{
		prev->av = ft_split_insert(prev->av, *av, ft_split_len(prev->av));
		if (!prev->av)
			return (prev->in.type[0] = IO_ERR, (void) 0);
		av++;
	}
	ft_redirection_special(prev);
	if (!*av)
		return ;
	if (ft_strchr(REDIR_IN, **av))
	{
		if (prev->in.type[0] == IO_NONE)
			prev->in.type[0] = ft_flags(*av);
		else
			prev->in.type[1] = ft_flags(*av);
	}
	if (ft_strchr(REDIR_OUT REDIR_NEXT, **av))
	{
		if (prev->out.type[0] == IO_NONE)
			prev->out.type[0] = ft_flags(*av);
		else
			prev->out.type[1] = ft_flags(*av);
	}
}

/**
 * It takes a list of arguments, and a pointer to a list of commands,
 * and if the last command in the list has a file as its input or output,
 * it sets the file to the last argument in the list of arguments
 * 
 * @param av The arguments that were passed to the command.
 * @param p The list of commands.
 * 
 * @return A boolean value.
 */
bool	ft_prev(char **av, t_cmd *prev)
{
	if (!prev)
		return (false);
	if (ft_is_flags(IO_NEXT, prev->out.type[0] | prev->out.type[1]))
		return (false);
	if (!ft_split_len(av) || ft_strchr(REDIR, **av))
		return (false);
	if (ft_is_flags(prev->in.type[0], IO_IFILE | IO_DEL) && !prev->in.file)
	{
		prev->in.file = ft_strdup(*av++);
		if (!prev->in.file)
			return (prev->in.type[0] = IO_ERR, true);
		ft_prev_av(av, prev);
		return (true);
	}
	if (ft_is_flags(prev->out.type[0], IO_OFILE | IO_APP) && !prev->out.file)
	{
		prev->out.file = ft_strdup(*av++);
		if (!prev->out.file)
			return (prev->in.type[0] = IO_ERR, true);
		ft_prev_av(av, prev);
		return (true);
	}
	return (false);
}
