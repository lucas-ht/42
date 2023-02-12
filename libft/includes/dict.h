/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 02:58:29 by lucas             #+#    #+#             */
/*   Updated: 2023/01/29 03:45:06 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

# include "list.h"

typedef struct s_dict
{
	char	*key;
	char	*content;
	int		flags;
}	t_dict;

t_dict	*ft_dict_new(t_list **list, char *key, char *content, int flags);
t_dict	*ft_dict_get(t_list *list, char *key);
t_dict	*ft_dict_set(t_list **list, char *key, char *content, int flags);
void	ft_dict_free(void *dict);
void	ft_dict_remove(t_list **list, char *key);

#endif
