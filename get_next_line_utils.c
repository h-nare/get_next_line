/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narhakob <narhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 19:17:55 by narhakob          #+#    #+#             */
/*   Updated: 2026/03/31 17:44:06 by narhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		length;
	int		i;

	i = 0;
	length = ft_strlen(s);
	dup = (char *)malloc((length + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (s[i] && s[i] != '\n')
	{
		dup[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
    	dup[i] = '\n';
    	i++;
	}
	dup[i] = '\0';
	return (dup);
}

