/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:37:21 by lucas             #+#    #+#             */
/*   Updated: 2023/01/30 02:35:54 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell	g_shell;

/*
	Permets de récupérer un mot avant un espace et/ou blanc.
	Donc ce cas précis, ça me sert à récupérer le nom de la variable
	d'environnement.
*/
static char	*getword(char *line)
{
	int		count;
	char	*word;

	count = 0;
	word = NULL;
	if (*line == '-' || *line == '?' || ft_isdigit(*line))
	{
		word = (char *)ft_calloc(2, sizeof(char));
		if (!word)
			return (ft_warning(ERROR_PARSING));
		ft_strlcpy(word, line, 2);
		return (word);
	}
	while (line[count] && (ft_isalnum(line[count])
			|| (ft_strchr("_", line[count]))) && line[count] != '-')
	{
		count++;
	}
	word = (char *)ft_calloc((count + 1), sizeof(char));
	if (!word)
		return (ft_warning(ERROR_PARSING));
	ft_strlcpy(word, line, count + 1);
	return (word);
}

/*
	Pour faire fonctionner venv_linesize
*/
static void	*venv_linesize_loop(char *line, int *i, int *count)
{
	t_venv	*env;
	char	*variable;

	variable = getword(&(line[*i + 1]));
	if (variable == ERROR)
		return (ERROR);
	if (key_exist(&g_shell.lst_env, variable))
	{
		env = key_exist(&g_shell.lst_env, variable)->content;
		*count += ft_strlen(env->value);
		*i += ft_strlen(env->key) + 1;
		free(variable);
		return (0);
	}
	*i += ft_strlen(variable) + 1;
	if (variable)
		free(variable);
	return (0);
}

/*
	Pour faire fonctionner venv_line
*/
static void	*venv_line_loop(char *line, char *new_line, int *i, int *offset)
{
	char	*variable;
	t_venv	*env;

	env = 0;
	variable = getword(&(line[*i + 1]));
	if (variable == ERROR)
		return (ERROR);
	if (key_exist(&g_shell.lst_env, variable))
	{
		env = key_exist(&g_shell.lst_env, variable)->content;
		ft_strlcpy(&new_line[*offset], env->value, ft_strlen(env->value) + 1);
		*i += ft_strlen(env->key) + 1;
		*offset += ft_strlen(env->value);
		free(variable);
		return (0);
	}
	*i += ft_strlen(variable) + 1;
	new_line[*offset] = line[*i];
	if (variable)
		free(variable);
	return (0);
}

/*
	Permet de retrouner la taille de la ligne avec les variables d'environement
	pour un malloc
*/
static int	venv_linesize(char *line, int *j)
{
	int		i;
	int		count;

	*j = 0;
	i = 0;
	count = 0;
	if (!line || line == ERROR)
		return (ERROR_INT);
	while (line[i])
	{
		if (line[i] == '$' && line[i + 1]
			&& (ft_isalnum(line[i + 1]) || ft_strchr("_-?", line[i + 1]))
			&& ft_parse_quote(line, &line[i]) != QUOTES_SINGLE)
		{
			if (venv_linesize_loop(line, &i, &count) == ERROR)
				return (ERROR_INT);
			continue ;
		}
		count++;
		i++;
	}
	return (count);
}

/*
	Retourne la ligne avec tout les $ remplacé par les valeurs
*/
char	*venv_line(char *line)
{
	int		i;
	int		offset;
	char	*new_line;
	int		nl_size;

	offset = 0;
	nl_size = venv_linesize(line, &i);
	if (nl_size == ERROR_INT || !nl_size)
		return (ERROR);
	new_line = (char *)ft_calloc(nl_size + 1, sizeof(char));
	if (!new_line)
		return (ft_warning(ERROR_PARSING));
	new_line[nl_size] = 0;
	while (offset < nl_size)
	{
		if (line[i] == '$' && (ft_isalnum(line[i + 1])
				|| ft_strchr("_-?", line[i + 1]))
			&& ft_parse_quote(line, &line[i]) != QUOTES_SINGLE)
		{
			venv_line_loop(line, new_line, &i, &offset);
			continue ;
		}
		new_line[offset++] = line[i++];
	}
	return (new_line);
}
