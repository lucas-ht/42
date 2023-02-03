/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:48:28 by lhutt             #+#    #+#             */
/*   Updated: 2023/01/30 02:05:49 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell	g_shell;

int	ft_unset(t_cmd *params)
{
	t_venv		*venv;
	int			i;

	i = -1;
	while (++i < params->ac)
	{
		venv = (t_venv *) ft_calloc(1, sizeof(t_venv));
		if (!venv)
			return (ft_warning_exec(ERROR_BUILTIN));
		venv->key = params->av[i];
		key_unset(&(g_shell.lst_env), venv);
		free(venv);
	}
	return (EXEC_SUCCESS);
}
