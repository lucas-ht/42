/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:58:52 by lhutt             #+#    #+#             */
/*   Updated: 2023/01/30 02:05:13 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * If the character is the same as the quote character,
 * increment the count and the index, and return 1
 *
 * @param c the current character
 * @param quote the current quote type
 * @param count the number of times the quote character has been found
 * @param i the index of the current character in the string
 */
static int	ft_quotes_ignore(char c, char *quote, int *count, int *i)
{
	if (*count >= 2 && (c == '\'' || c == '\"'))
	{
		*quote = c;
		*count = 1;
		(*i)++;
		return (1);
	}
	else if (c == *quote)
	{
		(*count)++;
		(*i)++;
		return (1);
	}
	return (0);
}

/**
 * It counts the number of characters in a string that are not escaped
 *
 * @param line the line to be parsed
 * @param quote the current quote character
 *
 * @return The length of the line minus the number of
 * characters that are ignored.
 */
static int	ft_quotes_line_size(char *line, char quote)
{
	int	i;
	int	count;
	int	count_dquote;

	i = 0;
	count = 0;
	count_dquote = 0;
	while (line[i])
	{
		if (ft_quotes_ignore(line[i], &quote, &count_dquote, &i) == 1)
			continue ;
		count++;
		i++;
	}
	return (count);
}

/**
 * It deletes all the quotes from a line
 *
 * @param line the line to be parsed
 * @param quote the type of quote we're looking for
 *
 * @return A pointer to a string.
 */
static char	*ft_quotes_delete(char	*line, char quote)
{
	char	*new_line;
	int		i;
	int		j;
	int		count;
	int		size;

	size = ft_quotes_line_size(line, quote);
	new_line = (char *)ft_calloc(size + 1, sizeof(char));
	if (!new_line)
		return (ft_warning(ERROR_PARSING));
	new_line[size] = '\0';
	i = 0;
	j = 0;
	count = 0;
	while (line[i])
	{
		if (ft_quotes_ignore(line[i], &quote, &count, &i) == 1)
			continue ;
		new_line[j] = line[i];
		j++;
		i++;
	}
	return (new_line);
}

/**
 * It returns the first quote character it finds in a string,
 * or 0 if there are no quotes
 *
 * @param line the line to be checked
 *
 * @return the character that is being quoted.
 */
static int	ft_no_quotes(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '\"')
			return (line[i]);
		i++;
	}
	return (0);
}

/**
 * It takes a string and returns a string with all the quotes removed
 *
 * @param line the line to be parsed
 *
 * @return A string with the quotes removed.
 */
char	*ft_quotes(char	*line)
{
	char	*new_line;
	char	quote;

	new_line = NULL;
	if (ft_strlen(line) == 0)
		return (ft_strdup(line));
	if (ft_parse_quote(line, &line[ft_strlen(line)]))
		return (ft_warning(ERROR_PARSING_QUOTES));
	quote = ft_no_quotes(line);
	if (!quote)
		return (ft_strdup(line));
	new_line = ft_quotes_delete(line, quote);
	if (ft_strlen(new_line) == 0)
		return (free(new_line), NULL);
	return (new_line);
}
