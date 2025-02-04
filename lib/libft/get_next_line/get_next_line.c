/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:26:02 by phhofman          #+#    #+#             */
/*   Updated: 2024/11/04 10:50:45 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_extract_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i ++;
	if (buffer[i] == '\n')
	{
		line = (char *)malloc(sizeof(char) * (i + 2));
		if (!line)
			return (NULL);
		ft_strlcpy(line, buffer, i + 2);
		return (line);
	}
	return (NULL);
}

char	*ft_update_buffer(char *buffer, char *line)
{
	char	*remaining;

	remaining = ft_strdup(buffer + ft_strlen(line));
	free_buf(&buffer);
	if (!remaining)
		return (NULL);
	return (remaining);
}

ssize_t	read_buffer(int fd, char *buffer, ssize_t *bytes_read)
{
	*bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (*bytes_read == -1)
		return (-1);
	buffer[*bytes_read] = '\0';
	return (*bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*r_buffer[1024 + 1];
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!r_buffer[fd])
		r_buffer[fd] = ft_strdup("");
	if (!r_buffer[fd])
		return (NULL);
	line = ft_extract_line(r_buffer[fd]);
	while (!line && read_buffer(fd, buffer, &bytes_read) > 0)
	{
		r_buffer[fd] = ft_strjoin_free(r_buffer[fd], buffer);
		if (!r_buffer[fd])
			return (NULL);
		line = ft_extract_line(r_buffer[fd]);
	}
	if (line)
		return (r_buffer[fd] = ft_update_buffer(r_buffer[fd], line), line);
	if (bytes_read != -1 && r_buffer[fd][0] != '\0')
		return (line = ft_strdup(r_buffer[fd]), free_buf(&r_buffer[fd]), line);
	return (free_buf(&r_buffer[fd]), NULL);
}
