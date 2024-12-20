/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imel-haj <imel-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:43:01 by imel-haj          #+#    #+#             */
/*   Updated: 2024/12/20 22:22:30 by imel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	int			read_by;
	char		*read_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buffer)
		return (NULL);
	while (1)
	{
		read_by = read(fd, read_buffer, BUFFER_SIZE);
		if (read_by < 0)
			return (free(read_buffer), NULL);
		read_buffer[read_by] = '\0';
		buffer = ft_strjoin(buffer, read_buffer); // leaks
		printf("%s\n-", buffer);
		//read_buffer[0] = '\0';
		if (buffer[0] == '\0')
		{
			free(buffer);
			return (NULL);
		}
		if (ft_strchr(read_buffer, '\n'))
			break ;
	}
	// free(read_buffer);
	line = get_line(buffer);
	buffer = get_rest_line(buffer);
	return (line);
}

char	*get_line(char *buffer)
{
	int		len;
	int		i;
	char	*line;

	len = 0;
	if (!buffer || !*buffer)
		return (NULL);
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_rest_line(char *buffer)
{
	int		i;
	int		j;
	char	*res_line;

	i = 0;
	j = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	if (buffer[i] == '\0')
		free(buffer);
	return (NULL);
	res_line = malloc(ft_strlen(buffer) - i + 1);
	if (!res_line)
		return (NULL);
	while (buffer[i])
	{
		res_line[j++] = buffer[i++];
	}
	res_line[j] = '\0';
	free(buffer);
	return (res_line);
}
int	main(void)
{
	int fd = open("file.txt", O_RDONLY);
	char *str = get_next_line(fd);
	// printf("%s", str);
	// while (str)
	// {
	// 	printf("%s", str);
	// 	free(str);
	// 	str = get_next_line(fd);
	// }
	// printf("%s", get_next_line(fd));
	close(fd);
}