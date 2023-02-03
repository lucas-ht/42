/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 04:25:39 by lhutt             #+#    #+#             */
/*   Updated: 2023/01/29 08:34:15 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"

/**
 * It counts the number of
 * arguments in a string
 * 
 * @param str the string to be parsed
 * 
 * @return The number of arguments in the string.
 */
static int	ft_split_args_count(char *str)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_strchr(SPACES, str[i]))
			i++;
		c = t(str[i] && (ft_parse_quote(str, &str[i])
					|| !ft_strchr(SPACES REDIR, str[i])), c + 1, c);
		while (str[i] && (ft_parse_quote(str, &str[i])
				|| !ft_strchr(SPACES REDIR, str[i])))
			i++;
		c = t(str[i] && ft_strchr(REDIR, str[i]), c + 1, c);
		while (str[i] && ft_strchr(REDIR, str[i]))
			i++;
	}
	return (c);
}

/**
 * It splits the argument
 * from the rest of the string
 * 
 * @param str the string to be parsed
 * 
 * @return A pointer to a string.
 */
static char	*ft_split_arg(char *str)
{
	int		i;
	char	*arg;

	i = 0;
	while (str[i] && (ft_parse_quote(str, &str[i])
			|| !ft_strchr(SPACES REDIR, str[i])))
		i++;
	if (!i)
		while (str[i] && ft_strchr(REDIR, str[i]))
			i++;
	arg = (char *) ft_calloc(i + 1, sizeof(char));
	if (!arg)
		return (ft_warning(ERROR_PARSING));
	ft_strlcpy(arg, str, i + 1);
	return (arg);
}

/**
 * It takes a string, splits it into arguments, and returns an array of strings
 * 
 * @param str the string to be split
 * 
 * @return A pointer to a pointer to a char.
 */
char	**ft_split_args(char *str)
{
	int		i;
	char	**av;

	if (!ft_split_args_count(str))
		return (ft_warning(ERROR_PARSING));
	av = (char **) ft_calloc(
			ft_split_args_count(str) + 1, sizeof(char *));
	if (!av)
		return (ft_warning(ERROR_PARSING));
	i = 0;
	while (*str)
	{
		while (*str && ft_strchr(SPACES, *str))
			str++;
		if (!*str)
			break ;
		av[i] = ft_split_arg(str);
		if (av[i] == ERROR)
			return (ft_split_error(av, i), ERROR);
		str += ft_strlen(av[i]) * sizeof(char);
		i++;
	}
	av[i] = 0;
	return (av);
}
