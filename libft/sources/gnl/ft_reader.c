/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 06:11:54 by lhutt             #+#    #+#             */
/*   Updated: 2023/01/15 20:32:58 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_reader(int fd)
{
	char	*s;
	char	*t;

	s = 0;
	t = get_next_line(fd);
	while (t)
	{
		s = ft_strjoin_free(s, t);
		t = get_next_line(fd);
	}
	return (ft_split(s, "\n"));
}
