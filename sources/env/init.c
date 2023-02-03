/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:22:13 by matfranc          #+#    #+#             */
/*   Updated: 2023/01/29 01:38:25 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell	g_shell;

/*
	Check si c'est un varaible d'environement global que
	l'on va modifier pour notre shell
*/
static int	is_customenv(char *venv)
{
	int		i;
	char	*_venv;
	char	**tab_venv;

	i = 0;
	_venv = ft_strdup("SHLVL USER SHELL PWD OLDPWD");
	tab_venv = ft_split(_venv, " ");
	while (tab_venv[i])
	{
		if (ft_strncmp(tab_venv[i], venv, ft_strlen(tab_venv[i])) == 0)
		{
			ft_free_split(tab_venv);
			free(_venv);
			return (1);
		}
		i++;
	}
	ft_free_split(tab_venv);
	free(_venv);
	return (0);
}

/*
	Configure les variables d'environement
*/
static void	set_customenv(int _shlvl)
{
	char	*path;
	char	*shlvl;

	path = getcwd(0, 0);
	shlvl = ft_itoa(_shlvl);
	if (!key_exist(&g_shell.lst_env, "USER"))
		key_add("USER", g_shell.user, &g_shell.lst_env);
	else if (!key_exist(&g_shell.lst_env, "PWD"))
		key_add("PWD", g_shell.path, &g_shell.lst_env);
	else if (!key_exist(&g_shell.lst_env, "SHELL"))
		key_add("SHELL", path, &g_shell.lst_env);
	else if (!key_exist(&g_shell.lst_env, "OLDPWD"))
		key_add("OLDPWD", g_shell.path, &g_shell.lst_env);
	else if (!key_exist(&g_shell.lst_env, "SHLVL"))
		key_add("SHLVL", shlvl, &g_shell.lst_env);
	(free(shlvl), free(path));
}

/*
	Copies toutes les variables d'environnement dans notre liste locale et
	effectuer les modifications nécessaires pour correspondent à notre programme.
*/
void	init_venv(char **envp)
{
	int		i;
	char	**g_venv;

	i = -1;
	g_venv = NULL;
	while (envp[++i])
	{
		if (!is_customenv(envp[i]))
		{
			g_venv = ft_split(envp[i], "=");
			if (!key_exist(&g_shell.lst_env, envp[i])
				&& ft_split_len(g_venv) == 2)
				key_add(g_venv[0], g_venv[1], &g_shell.lst_env);
			if (g_venv)
				ft_free_split(g_venv);
		}
		else
			set_customenv(ft_atoi(getenv("SHLVL")) + 1);
		if (!key_exist(&g_shell.lst_env, "?"))
			key_add("?", "0", &g_shell.lst_env);
		if (!key_exist(&g_shell.lst_env, "-"))
			key_add("-", "0", &g_shell.lst_env);
	}
}
