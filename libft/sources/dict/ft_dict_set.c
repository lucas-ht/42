/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 03:26:27 by lucas             #+#    #+#             */
/*   Updated: 2023/01/29 03:48:01 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It creates a new dictionary entry if it doesn't exist,
 * or updates the content of an existing entry
 * 
 * @param list the list of dictionaries
 * @param key The key of the dictionary.
 * @param content The content of the dictionary.
 * 
 * @return A pointer to a t_dict struct.
 */
t_dict	*ft_dict_set(t_list **list, char *key, char *content, int flags)
{
	t_dict	*dict;

	dict = ft_dict_get(*list, key);
	if (!dict)
		return (ft_dict_new(list, key, content, flags));
	dict->content = ft_strdup(content);
	dict->flags = flags;
	return (dict);
}
