/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   takes_places.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:49:13 by salahian          #+#    #+#             */
/*   Updated: 2025/01/30 18:06:45 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_pe(t_data *data, int y, int x)
{
	while (data->map[y][x])
	{
		if (data->map[y][x] == 'P')
		{
			data->map[y][x] = '0';
			data->x = x * TILES;
			data->y = y * TILES;
		}
		if (data->map[y][x] == 'N')
		{
			data->map[y][x] = '0';
			data->enemy.x = x * TILES;
			data->enemy.y = y * TILES;
		}
		x++;
	}
}

int	get_player(char *s, t_data *data)
{
	int	x;
	int	y;

	y = 0;
	data->map = check_m(s);
	if (data->map == NULL)
		return (0);
	data->win.wiht_win = ft_strlen(data->map[y]) * TILES;
	while (data->map[y])
	{
		x = 0;
		find_pe(data, y, x);
		y++;
	}
	if (data->enemy.x != 0 && data->enemy.y != 0)
		data->enemy.isactive = 1;
	data->win.hight_win = y * TILES;
	return (1);
}

void	help_red(t_data *data, int x, int y, char c)
{
	if (c == '1')
		color_img(data, x * TILES, y * TILES, 1);
	else if (c == 'C')
	{
		data->coin_collected++;
		data->ofx[data->ofs] = x * TILES;
		data->ofy[data->ofs] = y * TILES;
		create_coin(data);
		color_img(data, x * TILES, y * TILES, 0);
		data->ofs++;
	}
	else if (c == 'E')
	{
		data->exit1.x = x * TILES;
		data->exit1.y = y * TILES;
		color_img(data, x * TILES, y * TILES, 0);
	}
	else
		color_img(data, x * TILES, y * TILES, 0);
}

void	help_make_img(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	choose_img(data);
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			help_red(data, x, y, data->map[y][x]);
			x++;
		}
		y++;
	}
	data->win.hight_win = (y - 1) * TILES;
}

void	make_img(t_data *mlx)
{
	help_make_img(mlx);
	create_player(mlx);
	create_exit(mlx);
	if (mlx->enemy.isactive)
		main_func_enemy(mlx, &mlx->enemy);
}
