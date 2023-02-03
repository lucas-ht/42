/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:47:51 by lhutt             #+#    #+#             */
/*   Updated: 2023/01/30 02:52:52 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell	g_shell;

static int	ft_key_setup(t_cmd *params, int *i, int *j)
{
	char	*name;
	char	*value;
	char	*tilde;

	name = (char *) ft_calloc(++(*j), sizeof(char));
	if (!name)
		return (ft_warning_exec(ERROR_BUILTIN));
	ft_strlcpy(name, params->av[*i], *j);
	value = ft_strdup(&params->av[*i][*j]);
	if (!value)
		return (free(name), ft_warning_exec(ERROR_BUILTIN));
	tilde = ft_special_tilde(value);
	free(value);
	if (tilde == ERROR)
		return (free(name), EXEC_ERROR);
	(key_add(name, tilde, &g_shell.lst_env), free(name), free(tilde));
	return (0);
}

/**
 * It takes a command, checks if it has the correct
 * number of arguments, splits the first argument on
 * the equal sign, and if the split is successful,
 * adds the key and value to the environment
 *
 * @param params a pointer to a t_cmd struct.
 */
int	ft_export(t_cmd *params)
{
	int		i;
	int		j;

	if (params->ac == 0)
		return (ft_env_export(params));
	i = -1;
	while (++i < params->ac)
	{
		j = -1;
		if (*params->av[i] == '=' || ft_isdigit(*params->av[i]))
			return (ft_warning_exec(ERROR_EXPORT));
		while (params->av[i][++j] && (ft_isalnum(params->av[i][j])
			|| params->av[i][j] == '_'))
			;
		if (!params->av[i][j] || (!ft_isalnum(params->av[i][j])
				&& !ft_strchr("_=", params->av[i][j])))
			return (ft_warning_exec(ERROR_EXPORT));
		if (ft_key_setup(params, &i, &j))
			return (ERROR_INT);
	}
	return (EXEC_SUCCESS);
}
