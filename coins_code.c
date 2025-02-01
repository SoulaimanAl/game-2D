/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:32:39 by salahian          #+#    #+#             */
/*   Updated: 2025/02/01 16:39:53 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put2(t_coin *mg, int x, int y, unsigned int color)
{
	char	*dst;

	dst = mg->addr + (y * mg->line_length + x * (mg->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	animate_coins(t_data *data)
{
	int	i;
	int	player_x;
	int	player_y;

	i = 0;
	player_x = data->x / TILES;
	player_y = data->y / TILES;
	data->c_m += TILES;
	create_new_fram_coin(data);
	while (i < data->ofs)
	{
		if (data->ofx[i] / TILES == player_x && data->ofy[i]
			/ TILES == player_y)
		{
			data->ofx[i] = -1;
			data->ofy[i] = -1;
			data->coin_collected--;
			clear_prev_player(data, player_x * TILES, player_y * TILES);
		}
		else if (data->ofx[i] != -1 && data->ofy[i] != -1)
			set_new_fram_coin(data, data->ofx[i], data->ofy[i]);
		i++;
	}
}

void	create_new_fram_coin(t_data *win)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (i < TILES)
	{
		j = win->c_m;
		while (j < win->c_m + TILES)
		{
			color = *(unsigned int *)(win->coin2.addr + (i
						* win->coin2.line_length + j
						* (win->coin2.bits_per_pixel / 8)));
			my_mlx_pixel_put2(&win->coin1, j, i, color);
			j++;
		}
		i++;
	}
	if (j == 700)
		win->c_m = 0;
}

void	set_new_fram_coin(t_data *win, int x, int y)
{
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	win->dellay++;
	while (i < TILES)
	{
		j = 0;
		while (j < TILES)
		{
			color = *(unsigned int *)(win->coin1.addr + (i
						* win->coin1.line_length + j
						* (win->coin1.bits_per_pixel / 8)));
			if (color != 0xFF000000)
				my_mlx_pixel_put(&win->back_round, x + j, y + i, color);
			else
				color = *(unsigned int *)(win->floor.addr + (i
							* win->floor.line_length + j
							* (win->floor.bits_per_pixel / 8)));
			my_mlx_pixel_put(&win->back_round, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	create_coin(t_data *win)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (win->coin2.full_imag)
		mlx_destroy_image(win->mlx, win->coin2.full_imag);
	win->coin2.full_imag = mlx_xpm_file_to_image(win->mlx, COIN, &a, &b);
	win->coin1.addr = mlx_get_data_addr(win->coin1.full_imag,
			&win->coin1.bits_per_pixel, &win->coin1.line_length,
			&win->coin1.endian);
	win->coin2.addr = mlx_get_data_addr(win->coin2.full_imag,
			&win->coin2.bits_per_pixel, &win->coin2.line_length,
			&win->coin2.endian);
}
