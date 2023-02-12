/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 03:05:01 by lucas             #+#    #+#             */
/*   Updated: 2023/01/29 03:37:21 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It creates a new dictionary entry, adds it to the list,
 * and returns a pointer to the new entry
 * 
 * @param list a pointer to a t_list pointer.
 * This is the list that the new t_dict will be added to.
 * @param key the key of the dictionary
 * @param content The content of the dictionary.
 * @param flags 
 * 
 * @return A pointer to a t_dict struct.
 */
t_dict	*ft_dict_new(t_list **list, char *key, char *content, int flags)
{
	t_dict	*dict;
	t_list	*l;

	if (!key || !content || !list)
		return (0);
	dict = (t_dict *) ft_calloc(1, sizeof(t_dict));
	if (!dict)
		return (0);
	dict->key = ft_strdup(key);
	if (!dict->key)
		return (free(dict), (void *) 0);
	dict->content = ft_strdup(content);
	if (!dict->key)
		return (free(dict), free(content), (void *) 0);
	dict->flags = flags;
	l = ft_lstnew((void *) dict);
	if (!l)
		return (ft_dict_free(dict), (void *) 0);
	ft_lstadd_front(list, l);
	return (dict);
}
