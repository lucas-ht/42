/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:18:25 by matfranc          #+#    #+#             */
/*   Updated: 2023/01/29 01:37:59 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Permet d'ajouter un noeud à notre liste
*/
void	key_add(char *key, char *value, t_list **lst)
{
	t_venv	*venv;

	venv = (t_venv *)malloc(sizeof(t_venv));
	if (!venv)
		return ;
	venv->key = ft_strdup(key);
	venv->value = ft_strdup(value);
	if (key_double(lst, venv) == 0)
		ft_lstadd_back(lst, ft_lstnew(venv));
	else
		(free(venv->key), free(venv->value), free(venv));
}

/*
	Permet de récupérer un noeud à notre liste
	Et je viens de me rendre compte que j'ai recodé key_exist(), mince
*/
t_venv	*key_get(char *key, t_list **lst)
{
	t_list	*tmp;
	t_venv	*env;

	tmp = (*lst);
	while (tmp)
	{
		env = tmp->content;
		if (ft_strncmp(env->key, key, ft_strlen(env->key) + 1) == 0)
		{
			return (env);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

char	**key_toarray(t_list **lst)
{
	char	**keyarray;
	int		key_len;
	t_list	*temp;
	t_venv	*env;
	int		i;

	temp = *lst;
	key_len = ft_lstsize(temp);
	temp = *lst;
	keyarray = (char **)malloc(sizeof(char *) * key_len);
	keyarray[key_len - 1] = NULL;
	env = NULL;
	i = 0;
	while (temp)
	{
		env = (t_venv *)temp->content;
		if (ft_strncmp(env->key, "?", ft_strlen(env->key)))
		{
			keyarray[i] = ft_strjoin3(env->key, "=", env->value);
			i++;
		}
		temp = temp->next;
	}
	return (keyarray);
}

void	free_lst_venv(t_list **_lst)
{
	t_venv	*venv;
	t_list	*lst;
	t_list	*lst_del;

	lst = *_lst;
	while (lst)
	{
		venv = lst->content;
		free(venv->key);
		free(venv->value);
		free(venv);
		lst_del = lst;
		lst = lst->next;
		if (lst_del)
			free(lst_del);
	}
}
