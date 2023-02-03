/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:30:49 by lucas             #+#    #+#             */
/*   Updated: 2023/01/28 21:02:16 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * It returns true if the flag is in the flags
 * 
 * @param flag The flag to check for.
 * @param flags The flags that are passed to the function.
 */
bool	ft_is_flags(t_iotype flag, int flags)
{
	return (((int) flag) & flags);
}

/**
 * It takes a string and returns an enum value
 * 
 * @param flag The string to be parsed.
 * 
 * @return The type of redirection.
 */
t_iotype	ft_flags(char *flag)
{
	if (!flag || !*flag || !ft_strchr(REDIR, *flag))
		return (IO_NONE);
	if (ft_strlen(flag) > 2 || (ft_strlen(flag) == 2 && *flag != flag[1]))
		return (IO_INV);
	if (ft_strlen(flag) == 2)
	{
		if (*flag == *REDIR_IN)
			return (IO_DEL);
		if (*flag == *REDIR_OUT)
			return (IO_APP);
		if (*flag == *REDIR_NEXT)
			return (IO_INV);
	}
	if (*flag == *REDIR_IN)
		return (IO_IFILE);
	if (*flag == *REDIR_OUT)
		return (IO_OFILE);
	if (*flag == *REDIR_NEXT)
		return (IO_NEXT);
	return (IO_INV);
}

/**
 * It returns a string
 * representation of the given `t_iotype` flag
 * 
 * @param flag The flag to be converted to a string.
 * 
 * @return A string that represents the flag.
 */
char	*ft_flags_str(t_iotype flag)
{
	if (flag == IO_NONE)
		return ("IO_NONE");
	if (flag == IO_OFILE)
		return ("IO_OFILE");
	if (flag == IO_APP)
		return ("IO_APPEND");
	if (flag == IO_NEXT)
		return ("IO_NEXT");
	if (flag == IO_PREV)
		return ("IO_PREV");
	if (flag == IO_IFILE)
		return ("IO_IFILE");
	if (flag == IO_DEL)
		return ("IO_DELEMITER");
	if (flag == IO_ERR)
		return ("IO_ERROR");
	if (flag == IO_INV)
		return ("IO_INVALID");
	return (0);
}
