/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 03:34:29 by lucas             #+#    #+#             */
/*   Updated: 2023/03/26 20:44:40 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It frees the memory allocated for the key and content of a dictionary entry,
 * and then frees the
 * memory allocated for the dictionary entry itself
 * 
 * @param dict the dictionary to free
 */
void	ft_dict_free(void *dict)
{
	t_dict	*d;

	d = (t_dict *) dict;
	free(d->key);
	free(d->content);
	free(d);
}
