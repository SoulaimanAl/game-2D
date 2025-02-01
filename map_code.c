/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_code.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:49:51 by salahian          #+#    #+#             */
/*   Updated: 2025/01/30 11:24:33 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned int	get_the_color(t_data *data, int i, int j, int flag)
{
	unsigned int	color;

	if (flag)
		color = *(unsigned int *)(data->enemy2.addr + (i
					* data->enemy2.line_length + j
					* (data->enemy2.bits_per_pixel / 8)));
	else
		color = *(unsigned int *)(data->floor.addr + (i
					* data->floor.line_length + j * (data->floor.bits_per_pixel
						/ 8)));
	return (color);
}

void	my_mlx_pixel_put(t_img *mg, int x, int y, unsigned int color)
{
	char	*dst;

	dst = mg->addr + (y * mg->line_length + x * (mg->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	color_img(t_data *data, int start_x, int start_y, int flag)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	color = 0;
	while (y < TILES)
	{
		x = 0;
		while (x < TILES)
		{
			if (flag == 1)
				color = *(unsigned int *)(data->wall.addr + (y
							* data->wall.line_length + x
							* (data->wall.bits_per_pixel / 8)));
			else
				color = *(unsigned int *)(data->floor.addr + (y
							* data->floor.line_length + x
							* (data->floor.bits_per_pixel / 8)));
			my_mlx_pixel_put(&data->back_round, start_x + x, start_y + y,
				color);
			x++;
		}
		y++;
	}
}

void	choose_img(t_data *mlx)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	mlx->wall.full_imag = mlx_xpm_file_to_image(mlx->mlx, WALL, &a, &b);
	mlx->wall.addr = mlx_get_data_addr(mlx->wall.full_imag,
			&mlx->wall.bits_per_pixel, &mlx->wall.line_length,
			&mlx->wall.endian);
	a = 0;
	b = 0;
	mlx->floor.full_imag = mlx_xpm_file_to_image(mlx->mlx, FLOOR, &a, &b);
	mlx->floor.addr = mlx_get_data_addr(mlx->floor.full_imag,
			&mlx->floor.bits_per_pixel, &mlx->floor.line_length,
			&mlx->floor.endian);
}
