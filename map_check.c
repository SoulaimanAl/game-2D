/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:00:53 by salahian          #+#    #+#             */
/*   Updated: 2025/02/01 15:58:46 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(char **s, int y)
{
	int	i;

	i = 0;
	while (s[y][i])
	{
		if (s[y][i] == '\n' || s[y][i + 1] == '\0')
			break ;
		if (s[y][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	test_basic(char **s)
{
	int	x;
	int	y;
	int	count;

	count = ft_strlen(s[0]) - 1;
	y = 0;
	x = check_walls(s, y);
	if (x == 0)
		return (0);
	while (s[y])
	{
		x = 0;
		while (s[y][x])
		{
			if (s[y][x + 1] == '\0' || s[y][x + 1] == '\n')
				break ;
			x++;
		}
		if (count != x || s[y][x] != '1')
			return (0);
		y++;
	}
	if (!check_walls(s, y - 1))
		return (0);
	return (1);
}

int	creat_map(char **map, char *av, char *s, int fd)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	fd = open(av, O_RDONLY);
	s = get_next_line(fd);
	while (s != NULL)
	{
		if (s[ft_strlen(s) - 1] == '1')
		{
			map[i] = malloc(ft_strlen(s) + 1);
			flag = 0;
		}
		else
			map[i] = malloc(ft_strlen(s));
		if (!map[i])
			return (free(s), free_map(map), 0);
		ft_strlcpy(map[i], s, ft_strlen(s) - flag);
		free(s);
		s = get_next_line(fd);
		i++;
	}
	return (free(s), close(fd), map[i] = NULL, 1);
}

char	**check_map(char *av)
{
	int		fd;
	int		i;
	char	*s;
	char	**map;

	fd = open(av, O_RDONLY);
	s = get_next_line(fd);
	if (fd < 0 || !s)
		return (NULL);
	i = 0;
	while (s != NULL)
	{
		free(s);
		s = get_next_line(fd);
		i++;
	}
	free(s);
	map = malloc(sizeof(char *) * (i + 1));
	if (map == NULL)
		return (NULL);
	i = 0;
	close(fd);
	if (!creat_map(map, av, s, fd))
		return (NULL);
	return (map);
}

char	**check_m(char *av)
{
	char	**map;
	char	**copy;

	if (!check_name(av))
		return (NULL);
	map = check_map(av);
	if (map == NULL)
		return (NULL);
	copy = check_map(av);
	if (copy == NULL)
		return (free_map(map), NULL);
	if (test_basic(map) == 0 || test_adv(copy, map) == 0)
	{
		free_map(copy);
		free_map(map);
		return (NULL);
	}
	return (map);
}
