/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 06:11:54 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/15 07:03:53 by lhutt            ###   ########.fr       */
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
		s = ft_strjoin(s, t);
		t = get_next_line(fd);
	}
	return (ft_split(s, '\n'));
}
