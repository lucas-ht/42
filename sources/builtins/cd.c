/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:46:37 by lhutt             #+#    #+#             */
/*   Updated: 2023/01/30 02:32:53 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell	g_shell;

/**
 * It sets the PWD environment variable to the current working directory
 */
static void	ft_setpwd(void)
{
	char	*cwd;

	cwd = getcwd(0, 0);
	if (g_shell.path)
		free(g_shell.path);
	g_shell.path = ft_strdup(cwd);
	key_add("PWD", g_shell.path, &g_shell.lst_env);
	if (cwd)
		free(cwd);
}

/**
 * It takes a path, a parameter, and an oldpwd, and returns a path
 *
 * @param path the path to the directory to change to
 * @param params the string that the user typed after the cd command
 * @param oldpwd the old working directory
 *
 * @return The return value of the function.
 */
static int	ft_cd_abre(char **path, char *params, char *oldpwd)
{
	if (*params == '-')
	{
		if (ft_strncmp(params, "--", 2))
			*path = ft_strdup(oldpwd);
		else if (!ft_strncmp(params, "--\0", 3))
		{
			*path = getcwd(0, 0);
			if (!(*path))
				return (EXIT_FAILURE);
			key_add("OLDPWD", *path, &g_shell.lst_env);
		}
		else
			return (key_add("OLDPWD", oldpwd, &g_shell.lst_env), EXIT_FAILURE);
	}
	else if (!ft_strncmp(params, "..", 2)
		&& !ft_strncmp(params, "/", 1))
		*path = ft_strjoin3(g_shell.path, "/", params);
	else
		*path = ft_strdup(params);
	if (!(*path))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * It changes the current working directory
 * to the one specified in the first argument, and if it
 * succeeds, it sets the PWD environment variable to the new directory
 *
 * @param path The path to change to.
 *
 * @return The return value of the function.
 */
static int	ft_cd_exec(char **path, char **oldpwd)
{
	if (*path)
	{
		if (chdir(*path) == -1)
			return (free(*oldpwd), free(*path), EXIT_FAILURE);
		ft_setpwd();
		free(*path);
	}
	return (EXIT_SUCCESS);
}

/**
 * It changes the current working directory
 *
 * @param params the command parameters
 *
 * @return The return value of the function.
 */
int	ft_cd(t_cmd *params)
{
	char	*oldpwd;
	char	*path;

	oldpwd = ft_strdup(key_get("OLDPWD", &g_shell.lst_env)->value);
	if (!oldpwd)
		return (EXEC_ERROR);
	if (key_add("OLDPWD", g_shell.path, &g_shell.lst_env), !params->av[0])
	{
		path = ft_strdup(getenv("HOME"));
		if (!path)
			return (free(oldpwd), ft_warning_exec(ERROR_BUILTIN));
	}
	else
	{
		if (ft_cd_abre(&path, params->av[0], oldpwd))
			return (free(oldpwd), ft_warning_exec(ERROR_BUILTIN));
	}
	if (ft_cd_exec(&path, &oldpwd))
		return (ft_warning_exec(ERROR_BUILTIN));
	return (free(oldpwd), EXIT_SUCCESS);
}
