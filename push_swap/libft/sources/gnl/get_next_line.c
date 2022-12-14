/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 02:51:16 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/05 03:25:22 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_copy_str(char *str)
{
	char	*s;
	int		i;

	if (!*str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	s = (char *) malloc(++i * sizeof(char));
	if (!s)
		return (0);
	i = 0;
	while (*str && *str != '\n')
		s[i++] = *str++;
	if (*str == '\n')
		s[i++] = '\n';
	s[i] = 0;
	return (s);
}

char	*ft_next_line(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	s = (char *) malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!s)
		return (0);
	j = 0;
	while (str[++i])
		s[j++] = str[i];
	s[j] = 0;
	free(str);
	return (s);
}

char	*ft_read_line(int fd, char *str)
{
	char	*buffer;
	int		b;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	b = 1;
	while (!ft_strchr(str, '\n') && b)
	{
		b = read(fd, buffer, BUFFER_SIZE);
		if (b == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[b] = 0;
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[MAX_FILE_DESCRIPTOR];

	if (fd < 0 || fd >= MAX_FILE_DESCRIPTOR || BUFFER_SIZE <= 0)
		return (0);
	str[fd] = ft_read_line(fd, str[fd]);
	if (!str[fd])
		return (0);
	line = ft_copy_str(str[fd]);
	str[fd] = ft_next_line(str[fd]);
	return (line);
}
