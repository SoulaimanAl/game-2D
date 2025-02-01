/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:46:42 by salahian          #+#    #+#             */
/*   Updated: 2025/01/28 16:15:13 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s && s[i])
		i++;
	return (i);
}

char	*help_get_next(char **res, char *buf, int fd)
{
	char	*d;
	int		n;
	int		i;

	n = 1;
	while (n > 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n <= 0)
			break ;
		buf[n] = '\0';
		d = *res;
		*res = ft_strjoin(*res, buf);
		free(d);
		if (!*res)
			return (free(buf), NULL);
		i = 0;
		while ((*res)[i] && (*res)[i] != '\n')
			i++;
		if ((*res)[i] == '\n')
			return (free(buf), take_line_from_res(res, i, 1));
	}
	if (n == -1 || (n == 0 && (!*res || **res == '\0')))
		return (free(buf), free(*res), *res = NULL, NULL);
	return (free(buf), take_line_from_res(res, ft_strlen(*res), 0));
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*buf;
	char		*line;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc((BUFFER_SIZE * sizeof(char)) + 1);
	if (buf == NULL)
		return (free(res), res = NULL, NULL);
	if (res)
	{
		i = 0;
		while (res[i] && res[i] != '\n')
			i++;
		if (res[i] == '\n')
		{
			line = take_line_from_res(&res, i, 1);
			return (free(buf), line);
		}
	}
	return (help_get_next(&res, buf, fd));
}
