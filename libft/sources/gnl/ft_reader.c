/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 06:11:54 by lhutt             #+#    #+#             */
/*   Updated: 2023/04/13 03:58:20 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It reads a file and returns an array of strings,
 * each string being a line of the file
 * 
 * @param fd file descriptor
 * 
 * @return An array of strings.
 */
char	**ft_reader(int fd)
{
	char	**s;
	char	*t;

	s = ft_calloc(1, sizeof(char *));
	if (!s)
		return (0);
	*s = 0;
	t = get_next_line(fd);
	while (t)
	{
		s = ft_split_insert(s, t, ft_split_len(s));
		free(t);
		if (!s)
			return (0);
		t = get_next_line(fd);
	}
	return (s);
}
