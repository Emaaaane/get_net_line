/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imel-haj <imel-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:43:01 by imel-haj          #+#    #+#             */
/*   Updated: 2024/12/10 19:15:26 by imel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*get_next_line(int fd)
{
    static char bufer = NULL;
    int read_by;
    char *buff;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buff = malloc(sizeof (char) * (BUFFER_SIZE + 1));
    if(!buff)
        return(NULL);
    while(1)
    {
        read_by = read(fd, buff, BUFFER_SIZE);
        if(read_by < 0)
            return (NULL);
        
        buff[read_by] == '\0';

        buffer = ft_strjoin(buffer, buff);
    }

    
}
char *get_line(char *buffer)
{
    int len;
    int i;
    char *line;

    len = 0;
    if(!buffer || !*buffer)
        return(NULL);
    while(buffer[len] && buffer[len] != '\n')
        len++;
    if(buffer[len] == '\n')
        len++;
    line = malloc(len + 1);
    if(!line)
        return(NULL);
    i = 0;
    while(i < len)
    {
        line[i] = buffer[i];
        i++;
    }
    line[i] = '\0';
    return(line);
}

int main()
{
    int fd = open ("file.txt", O_RDONLY);
    char *str = get_next_line(fd);
    while (str)
    {
        printf("%s", str);
        str = get_next_line(fd);
    }
}