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
#include <fcntl.h>
char	*get_next_line(int fd)
{
    char *buff;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buff = malloc(sizeof (char) * (BUFFER_SIZE + 1));
    
    
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