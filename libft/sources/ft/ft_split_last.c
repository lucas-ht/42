/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 04:05:32 by lhutt             #+#    #+#             */
/*   Updated: 2023/01/08 18:10:58 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_split_last(char **str)
{
	if (!str || !*str)
		return (0);
	return (str[ft_split_len(str) - 1]);
}