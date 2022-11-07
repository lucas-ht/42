/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:36:18 by lhutt             #+#    #+#             */
/*   Updated: 2022/11/07 02:44:44 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*cur_line;
	static char	*next = NULL;
	int			b;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	b = 1;
	while (!ft_strchr(next, '\n') && b)
	{
		b = read(fd, buffer, BUFFER_SIZE);
		if (b <= 0)
			break ;
		buffer[b] = 0;
		next = ft_strjoin(next, buffer);
	}
	free(buffer);

	cur_line = get_cur_line(next);
	next = get_to_next(next);
	return (cur_line);
}


char	*get_cur_line(char *str)
{
	char	*result;
	int		i;

	if (str == NULL)
		return (NULL);
	result = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
		if (str[i - 1] == '\n')
			break ;
	}
	result[i] = '\0';
	return (result);
}

char	*get_to_next(char	*str)
{
	char	*result;
	int		i;
	int		j;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || !str[i + 1])
		return (free(str), NULL);
	if (str[i])
		i++;
	result = malloc(sizeof(char) * ft_strlen(str + i) + 1);
	if (result == NULL)
		return (free(str), NULL);
	j = 0;
	while (str[i])
		result[j++] = str[i++];
	result[j] = '\0';
	free(str);
	return (result);
}
