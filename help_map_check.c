/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_map_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:08:49 by salahian          #+#    #+#             */
/*   Updated: 2025/01/31 17:52:36 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	help_test_map(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

// 1111111
// 1FFFFF1
// 10111F1  3C - 1 - 1 - 1
// 1FFFEF1 info->exit = 1;
// 1F11101
// 1111111
int	flood_fill(char **s, int x, int y, t_play *info)
{
	if (s[y][x] == '\0' || s[y][x] == '1' || s[y][x] == 'F')
		return (0);
	if (s[y][x] == 'E')
	{
		info->exit = 1;
		return (0);
	}
	if (s[y][x] == 'C')
		info->collected_coin--;
	s[y][x] = 'F';
	flood_fill(s, x + 1, y, info);
	flood_fill(s, x - 1, y, info);
	flood_fill(s, x, y + 1, info);
	flood_fill(s, x, y - 1, info);
	return (info->exit == 1 && info->collected_coin == 0);
}

int	test_map(char **s, char *a, t_play *info)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (help_test_map(a, s[i][j]) == 0)
				return (0);
			check_for_pce(info, s[i][j], i, j);
			j++;
		}
		i++;
	}
	if (info->p != 1 || info->collected_coin < 1 || info->exit != 1)
		return (0);
	return (1);
}

int	test_adv(char **s, char **map)
{
	int		d;
	t_play	info;

	d = 1;
	set_struct(&info);
	d = test_map(map, "10PCEN", &info);
	if (d == 0)
		return (0);
	info.exit = 0;
	d = flood_fill(s, info.x, info.y, &info);
	if (d == 0 || info.collected_coin > 0)
		return (0);
	free_map(s);
	return (1);
}
