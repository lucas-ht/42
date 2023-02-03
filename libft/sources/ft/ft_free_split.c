/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 02:43:59 by lhutt             #+#    #+#             */
/*   Updated: 2023/01/06 19:45:14 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
