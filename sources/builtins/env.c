/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:48:55 by lhutt             #+#    #+#             */
/*   Updated: 2023/01/30 02:35:28 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell	g_shell;

static void	swap_xor(char ***buffer, char ****name, int i)
{
	(*buffer)[i] = (char *)((size_t)(*buffer)[i]
			^ (size_t)(*buffer)[i + 1]);
	(*buffer)[i + 1] = (char *)((size_t)(*buffer)[i]
			^ (size_t)(*buffer)[i + 1]);
	(*buffer)[i] = (char *)((size_t)(*buffer)[i]
			^ (size_t)(*buffer)[i + 1]);
	(*name)[i][0] = (char *)((size_t)(*name)[i][0]
			^ (size_t)(*name)[i + 1][0]);
	(*name)[i + 1][0] = (char *)((size_t)(*name)[i][0]
			^ (size_t)(*name)[i + 1][0]);
	(*name)[i][0] = (char *)((size_t)(*name)[i][0]
			^ (size_t)(*name)[i + 1][0]);
}

static void	swap_venv_array(char ***buffer, char ****name)
{
	int	i;
	int	len;

	i = 0;
	while ((*name)[i + 1])
	{
		len = ft_strlen((*name)[i][0]);
		if (len < (int)ft_strlen((*name)[i + 1][0]))
			len = ft_strlen((*name)[i + 1][0]);
		if (ft_strncmp((*name)[i][0], (*name)[i + 1][0], len) > 0)
		{
			swap_xor(buffer, name, i);
			i = 0;
			continue ;
		}
		i++;
	}
}

static void	ft_env_exprint(char ***buffer, char ****name)
{
	int	i;

	i = 0;
	while ((*buffer)[i])
	{
		if (*(*name)[i][0] != '?' && *(*name)[i][0] != '_'
			&& *(*name)[i][0] != '-')
			printf("%s\n", (*buffer)[i]);
		i++;
	}
	ft_free_split((*buffer));
	i = 0;
	while ((*name)[i])
	{
		ft_free_split((*name)[i]);
		i++;
	}
	free(*name);
}

int	ft_env_export(t_cmd *params)
{
	char	**buffer;
	char	***name;
	int		i;

	i = 0;
	if ((void) params, !g_shell.lst_env)
		return (ft_warning_exec(ERROR_BUILTIN));
	buffer = key_toarray(&g_shell.lst_env);
	name = (char ***)ft_calloc(ft_lstsize(g_shell.lst_env) + 1,
			sizeof(char **));
	name[ft_lstsize(g_shell.lst_env)] = 0;
	while (buffer[i])
	{
		name[i] = ft_split(buffer[i], "=");
		i++;
	}
	swap_venv_array(&buffer, &name);
	ft_env_exprint(&buffer, &name);
	return (EXEC_SUCCESS);
}

int	ft_env(t_cmd *params)
{
	t_list	*tmp;
	t_venv	*data;

	if ((void) params, !g_shell.lst_env)
		return (ft_warning_exec(ERROR_BUILTIN));
	tmp = g_shell.lst_env;
	while (tmp)
	{
		if (!tmp->content)
		{
			tmp = tmp->next;
			continue ;
		}
		data = (t_venv *) tmp->content;
		if (*data->key != '?' && *data->key != '-')
			printf("%s=%s\n", data->key, data->value);
		tmp = tmp->next;
	}
	return (EXEC_SUCCESS);
}
