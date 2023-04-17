/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 03:39:25 by lucas             #+#    #+#             */
/*   Updated: 2023/01/29 03:48:44 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It removes a dictionary
 * entry from a list of dictionaries
 * 
 * @param list the list to remove the element from
 * @param key the key to search for
 * 
 * @return Nothing.
 */
void	ft_dict_remove(t_list **list, char *key)
{
	t_dict	*dict;
	t_list	*l;

	if (!key || !list)
		return ;
	l = *list;
	while (l)
	{
		dict = (t_dict *) l->content;
		if (ft_strlen(dict->key) == ft_strlen(key)
			&& !ft_strncmp(dict->key, key, ft_strlen(dict->key)))
			return (ft_lstdelete(list, l, ft_dict_free), (void) 0);
		l = l->next;
	}
}
