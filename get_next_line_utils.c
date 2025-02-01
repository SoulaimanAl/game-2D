/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulaimane <soulaimane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:32:07 by salahian          #+#    #+#             */
/*   Updated: 2024/11/26 15:35:44 by soulaimane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	size_t	i;
	size_t	l1;
	size_t	l2;
	size_t	j;

	l1 = 0;
	l2 = 0;
	if (s1)
		l1 = ft_strlen(s1);
	if (s2)
		l2 = ft_strlen(s2);
	s = malloc(1 + l1 + l2);
	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < l1)
		s[j++] = s1[i++];
	i = 0;
	while (i < l2)
		s[j++] = s2[i++];
	s[j] = '\0';
	return (s);
}

char	*take_line_from_res(char **res, size_t len, int n)
{
	char	*line;
	char	*new_res;
	size_t	res_len;
	size_t	i;

	line = malloc(len + 1 + n);
	if (!line)
		return (free(*res), *res = NULL, NULL);
	i = 0;
	while (i < len + n)
	{
		line[i] = (*res)[i];
		i++;
	}
	line[i] = '\0';
	res_len = ft_strlen(*res);
	if (len + n < res_len)
		new_res = ft_strjoin(NULL, *res + len + n);
	else
		new_res = NULL;
	if (*res)
		free(*res);
	*res = new_res;
	return (line);
}
