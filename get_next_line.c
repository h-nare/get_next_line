/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narhakob <narhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:21:17 by narhakob          #+#    #+#             */
/*   Updated: 2026/03/31 18:30:37 by narhakob         ###   ########.fr       */
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
char *trim_smth(char *s)
{
    char *new;
    int i;
    int j;

    i = 0;
    j = 0;
    
    while(s[i] && s[i] != '\n')
        i++;
    if(!s[i])
    {
        free(s);
        return (NULL);
    }
    i++;
    new = malloc(ft_strlen(s) - i + 1);
    if(!new)
        return (new);
    while(s[i])
    {
        new[j] = s[i];
        i++;
        j++;
    }
    new[j] = '\0';
    free(s);
    return (new);
}

char *get_next_line(int fd)
{
    int buffer;
    static char *smth;
    char a[BUFFER_SIZE + 1];
    char *tmp;
    char *line;

    if(fd < 0 || (BUFFER_SIZE < 0))
        return (free(smth),NULL);
    buffer = read(fd,a,BUFFER_SIZE);
    if(buffer == -1)
        return (NULL);
    if(!smth)
    {
        smth = malloc(1);
        if(!smth)
            return (NULL);
        smth[0] = '\0';
    }
    while((buffer > 0) && !find_n(smth))
    {
        a[buffer] = '\0';
        tmp = smth;
        smth = ft_strjoin(tmp, a);
        free(tmp);
        buffer = read(fd,a,BUFFER_SIZE);  
    }
    if(buffer < 0)
        return (NULL);
    if(!smth || smth[0] == '\0')
        return (NULL);
    line = ft_strdup(smth);
    smth = trim_smth(smth);
    return (line);
     
}
// int main()
// {
//     int fd;
//     fd = open("file.txt",O_RDONLY);
//     char *esim = get_next_line(fd);
//     printf("%s",esim);
//     free(esim);
//     esim = get_next_line(fd);
//     printf("%s",esim);
//     free(esim);
//     // printf("%s",get_next_line(fd));
//     // printf("%s",get_next_line(fd));
    
// }




