/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:14:47 by lucas             #+#    #+#             */
/*   Updated: 2023/01/15 19:09:46 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "libft.h"

// A struct that contains the key and value of the environment variables.
typedef struct s_venv
{
	char	*key;
	char	*value;
}	t_venv;

// init.c
void	init_venv(char **envp);

// dict.c
void	key_add(char *key, char *value, t_list **lst);
t_venv	*key_get(char *key, t_list **lst);
char	**key_toarray(t_list **lst);
void	free_lst_venv(t_list **_lst);

// env.c
t_list	*key_exist(t_list **lst, char *keyname);
void	key_unset(t_list **lst, t_venv *venv);
int		key_double(t_list **lst, t_venv *venv);
char	*venv_line(char *line);

#endif
