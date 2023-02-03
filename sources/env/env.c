/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 06:31:08 by matfranc          #+#    #+#             */
/*   Updated: 2023/01/29 01:37:14 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell	g_shell;

/*
	Vérifie si dans la liste une variable existe déjà
*/
t_list	*key_exist(t_list **lst, char *keyname)
{
	t_list	*tmp;
	t_venv	*env;

	tmp = (*lst);
	while (tmp)
	{
		env = tmp->content;
		if (ft_strncmp(env->key, keyname, ft_strlen(env->key) + 1) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

/*
	Permets de supprimer une variable de la liste
*/
void	key_unset(t_list **lst, t_venv *venv)
{
	t_list	*tmp;
	t_venv	*env;

	tmp = key_exist(lst, venv->key);
	if (tmp)
	{
		env = tmp->content;
		if (env->key)
			free(env->key);
		if (env->value)
			free(env->value);
		ft_lstdelete(lst, tmp, 0);
		free(env);
		free(tmp);
	}
}

/*
	Vérifie si dans la liste une variable existe déjà et si oui met à jour sa valeur
*/
int	key_double(t_list **lst, t_venv *venv)
{
	t_list	*tmp;
	t_venv	*env;

	tmp = (*lst);
	while (tmp)
	{
		if (!tmp->content)
		{
			tmp = tmp->next;
			continue ;
		}
		env = (t_venv *)tmp->content;
		if (ft_strncmp(env->key, venv->key, ft_strlen(env->key) + 1) == 0)
		{
			if (env->value)
				free(env->value);
			env->value = ft_strdup(venv->value);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
