/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_enemy_code.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:36:26 by salahian          #+#    #+#             */
/*   Updated: 2025/01/30 09:20:44 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_new_fram_enemy(t_data *data, int flag)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (i < TILES)
	{
		j = data->enemy_fram;
		while (j < data->enemy_fram + TILES)
		{
			color = *(unsigned int *)(data->enemy1.addr + (i
						* data->enemy1.line_length + j
						* (data->enemy1.bits_per_pixel / 8)));
			my_mlx_pixel_put(&data->enemy2, j, i, color);
			j++;
		}
		i++;
	}
	if (flag && j >= 800)
		data->enemy_fram = 0;
	else if (!flag && j >= 600)
		data->enemy_fram = 0;
}

void	set_new_fram_enemy(t_data *data, int x, int y)
{
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	while (i < TILES)
	{
		j = 0;
		while (j < TILES)
		{
			color = get_the_color(data, i, j, 1);
			if (color != 0xFF000000)
			{
				if (color == 0)
					color = get_the_color(data, i, j, 0);
				my_mlx_pixel_put(&data->back_round, x + j, y + i, color);
			}
			else
				clear_place(data, data->x + j, data->y + i);
			j++;
		}
		i++;
	}
}

int	is_valid_pos_enemy(t_data *data, int new_x, int new_y)
{
	int	newr;
	int	newl;
	int	newd;
	int	x;
	int	y;

	newr = (new_x + TILES - 1) / TILES;
	newl = new_x / TILES;
	newd = (new_y + TILES - 1) / TILES;
	y = new_y / TILES;
	while (y <= newd)
	{
		x = newl;
		while (x <= newr)
		{
			if ((data->map[y][x] == '1') || (data->map[y][x] == 'E'))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	help_move_enemy(t_data *data, t_enemy *enemy, int step_x, int step_y)
{
	int	delta_x;
	int	delta_y;

	delta_x = data->x - enemy->x;
	delta_y = data->y - enemy->y;
	if (is_valid_pos_enemy(data, enemy->x + step_x, enemy->y + step_y))
	{
		enemy->x += step_x;
		enemy->y += step_y;
		enemy->flag = 0;
	}
	else if (abs(delta_x) > abs(delta_y) && is_valid_pos_enemy(data, enemy->x
			+ step_x, enemy->y))
		enemy->x += step_x;
	else if (is_valid_pos_enemy(data, enemy->x, enemy->y + step_y))
		enemy->y += step_y;
	else if (is_valid_pos_enemy(data, enemy->x + step_x, enemy->y))
		enemy->x += step_x;
	else if (is_valid_pos_enemy(data, enemy->x, enemy->y + step_y))
		enemy->y += step_y;
}

void	move_enemy_towards_player(t_data *data, t_enemy *enemy, int player_x,
		int player_y)
{
	int	delta_x;
	int	delta_y;
	int	step_x;
	int	step_y;

	delta_x = player_x - enemy->x;
	delta_y = player_y - enemy->y;
	step_x = 0;
	step_y = 0;
	if (delta_x > 0)
		step_x = enemy->speed;
	else if (delta_x < 0)
		step_x = -enemy->speed;
	if (delta_y > 0)
		step_y = enemy->speed;
	else if (delta_y < 0)
		step_y = -enemy->speed;
	help_move_enemy(data, enemy, step_x, step_y);
}
