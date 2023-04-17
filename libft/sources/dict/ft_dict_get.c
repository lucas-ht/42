/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 03:21:31 by lucas             #+#    #+#             */
/*   Updated: 2023/01/29 03:47:36 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It returns the dictionary
 * entry with the given key, or 0 if no such entry exists
 * 
 * @param list The list to search through.
 * @param key The key to search for.
 * 
 * @return A pointer to a t_dict struct.
 */
t_dict	*ft_dict_get(t_list *list, char *key)
{
	t_dict	*dict;

	if (!key || !list)
		return (0);
	while (list)
	{
		dict = (t_dict *) list->content;
		if (ft_strlen(dict->key) == ft_strlen(key)
			&& !ft_strncmp(dict->key, key, ft_strlen(dict->key)))
			return (dict);
		list = list->next;
	}
	return (0);
}
