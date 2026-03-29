/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narehakobyan <narehakobyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:21:17 by narhakob          #+#    #+#             */
/*   Updated: 2026/03/29 17:10:33 by narehakobya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int find_n(char *a)
{
    int i = 0;
    while(a[i])
    {
        if(a[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}
char *get_next_line(int fd)
{
    int buffer;
    static char *smth;
    char a[BUFFER_SIZE + 1];
    char *tmp;

    buffer = read(fd,a,BUFFER_SIZE);
    if(buffer == -1)
        return (NULL);
    if(!smth)
        return (NULL);
    smth = malloc(1);
    smth = "\0";
    while((buffer > 0) && !find_n(smth))
    {
        smth = ft_strjoin(smth,a);
        buffer = read(fd,a,BUFFER_SIZE);
        if(buffer == -1)
            return (NULL);     
    }
}

int main()
{
    int fd;

    fd = open("file.txt",O_RDONLY);
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    
}



