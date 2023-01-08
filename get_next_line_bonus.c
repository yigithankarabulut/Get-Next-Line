/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarabul <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:45:20 by ykarabul          #+#    #+#             */
/*   Updated: 2023/01/05 03:37:43 by ykarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_creat_buffer(int fd, char *buffer)
{
	char	*temp;
	int		buff_size;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	buff_size = 1;
	while (!ft_strchr(buffer) && buff_size != 0)
	{
		buff_size = read(fd, temp, BUFFER_SIZE);
		if (buff_size == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[buff_size] = '\0';
		buffer = ft_strjoin(buffer, temp);
	}
	free(temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer[fd] = ft_creat_buffer(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_get_line(buffer[fd]);
	buffer[fd] = ft_new_left_str(buffer[fd]);
	return (line);
}
