/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narhakob <narhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:21:17 by narhakob          #+#    #+#             */
/*   Updated: 2026/04/03 16:40:15 by narhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int find_n(char *a)
// {
//     int i = 0;
//     while(a[i])
//     {
//         if(a[i] == '\n')
//             return (1);
//         i++;
//     }
//     return (0);
// }
// char *trim_smth(char *s)
// {
//     char *new;
//     int i;
//     int j;

//     i = 0;
//     j = 0;
//     while(s[i] && s[i] != '\n')
//         i++;
//     if(!s[i])
//         return (free(s), NULL);
  
//     i++;
//     new = malloc(ft_strlen(s + i) + 1);
//     if(!new)
//         return (NULL);
//     while(s[i])
//     {
//         new[j] = s[i];
//         i++;
//         j++;
//     }
//     new[j] = '\0';
//     free(s);
//     return (new);
// }

// char *get_next_line(int fd)
// {
//     int buffer;
//     static char *smth;
//     char *a = malloc(BUFFER_SIZE + 1);
//     if (!a)
//         return NULL;
//     char *tmp;
//     char *line;
    
//     if(fd < 0 || (BUFFER_SIZE < 0))
//     {   
//         free(a);
//         if(smth)
//             free(smth);
//         return (NULL);
//     }
//     buffer = read(fd, a, BUFFER_SIZE);
//     if(buffer == -1)
//         return (free(a),NULL);
//     if(!smth)
//     {
//         smth = malloc(1);
//         if(!smth)
//             return (free(a),NULL);
//         smth[0] = '\0';
//     }
//     while((buffer > 0) && !find_n(smth))
//     {
//         a[buffer] = '\0';
//         tmp = smth;
//         smth = ft_strjoin(tmp, a);
//         free(tmp);
//         buffer = read(fd,a,BUFFER_SIZE);  
//     }
//     free(a);
//     if(buffer < 0)
//         return (NULL);
//     if(!smth || smth[0] == '\0')
//         return (NULL);
//     line = ft_strdup(smth);
//     if(!line)
//         return (NULL);
//     smth = trim_smth(smth);
//     if(!smth)
//         return(NULL);
//     return (line);
// }

int find_n(char *a)
{
    int i = 0;
    while (a && a[i])
    {
        if (a[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

char *extract_line(char *s)
{
    int j;
    
    int i = 0;
    char *line;

    if (!s || !s[0])
        return (NULL);

    while (s[i] && s[i] != '\n')
        i++;
    if (s[i] == '\n')
        i++;

    line = malloc(i + 1);
    if (!line)
        return (NULL);

    j = 0;
    while(j < i)
    {
        line[j] = s[j];
        j++;
    }
    line[i] = '\0';

    return (line);
}

char *trim_smth(char *s)
{
    int i = 0, j = 0;
    char *new;

    while (s[i] && s[i] != '\n')
        i++;
    if (!s[i])
    {
        free(s);
        return (NULL);
    }
    i++;

    new = malloc(ft_strlen(s + i) + 1);
    if (!new)
        return (NULL);

    while (s[i])
        new[j++] = s[i++];
    new[j] = '\0';

    free(s);
    return (new);
}

char *get_next_line(int fd)
{
    static char *smth;
    char *buffer;
    char *tmp;
    char *line;
    int bytes;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);

    if (!smth)
        smth = ft_strdup("");

    bytes = 1;
    while (bytes > 0 && !find_n(smth))
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        if (bytes < 0)
        {
            free(buffer);
            return (NULL);
        }
        buffer[bytes] = '\0';
        tmp = smth;
        smth = ft_strjoin(tmp, buffer);
        free(tmp);
    }
    free(buffer);

    if (!smth || smth[0] == '\0')
        return (NULL);

    line = extract_line(smth);
    smth = trim_smth(smth);

    return (line);
}
// int main()
// {
//     int fd;
//     char *esim;
    
//     fd = open("multiple_line_no_nl",O_RDONLY);
//     esim = get_next_line(fd);

//     printf("%s",esim);
//     free(esim);

//     esim = get_next_line(fd);

//     printf("%s",esim);
//     free(esim);
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
    
// }
