/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 02:43:59 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:45:13 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It frees a split string
 * 
 * @param s The string to be split.
 * 
 * @return 0.
 */
int	ft_free_split(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		free(s[i++]);
	free(s);
	return (0);
}
