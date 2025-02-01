/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_code.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:42:01 by salahian          #+#    #+#             */
/*   Updated: 2025/01/29 17:48:41 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_prev_player(t_data *data, int old_x, int old_y)
{
	int	y;
	int	x;
	int	color;

	y = old_y;
	while (y < old_y + TILES)
	{
		x = old_x;
		while (x < old_x + TILES)
		{
			color = *(unsigned int *)(data->floor.addr + (y % TILES)
					* data->floor.line_length + (x % TILES)
					* (data->floor.bits_per_pixel / 8));
			my_mlx_pixel_put(&data->back_round, x, y, color);
			x++;
		}
		y++;
	}
}

void	clear_place(t_data *data, int old_x, int old_y)
{
	int	y;
	int	x;
	int	color;

	y = old_y;
	while (y <= old_y)
	{
		x = old_x;
		while (x <= old_x)
		{
			color = *(unsigned int *)(data->floor.addr + (y % TILES)
					* data->floor.line_length + (x % TILES)
					* (data->floor.bits_per_pixel / 8));
			my_mlx_pixel_put(&data->back_round, x, y, color);
			x++;
		}
		y++;
	}
}

void	create_new_fram_player(t_data *data)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (i < TILES)
	{
		j = data->pl;
		while (j < data->pl + TILES)
		{
			color = *(unsigned int *)(data->player.addr + (i
						* data->player.line_length + j
						* (data->player.bits_per_pixel / 8)));
			my_mlx_pixel_put(&data->f_imgp, j, i, color);
			j++;
		}
		i++;
	}
	if (j == 800)
		data->pl = 0;
}

void	set_new_fram_player(t_data *data, int x, int y)
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
			color = *(unsigned int *)(data->f_imgp.addr + (i
						* data->f_imgp.line_length + j
						* (data->f_imgp.bits_per_pixel / 8)));
			if (color != 0xFF000000)
				my_mlx_pixel_put(&data->back_round, x + j, y + i, color);
			else
				clear_place(data, data->x + j, data->y + i);
			j++;
		}
		i++;
	}
}

void	create_player(t_data *data)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (data->moving)
	{
		if (data->player.full_imag)
			mlx_destroy_image(data->mlx, data->player.full_imag);
		data->player.full_imag = mlx_xpm_file_to_image(data->mlx, PLAYER1, &a,
				&b);
	}
	else
	{
		if (data->player.full_imag)
			mlx_destroy_image(data->mlx, data->player.full_imag);
		data->player.full_imag = mlx_xpm_file_to_image(data->mlx, PLAYER2, &a,
				&b);
	}
	data->f_imgp.addr = mlx_get_data_addr(data->f_imgp.full_imag,
			&data->f_imgp.bits_per_pixel, &data->f_imgp.line_length,
			&data->f_imgp.endian);
	data->player.addr = mlx_get_data_addr(data->player.full_imag,
			&data->player.bits_per_pixel, &data->player.line_length,
			&data->player.endian);
}
