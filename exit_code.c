/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:09:21 by salahian          #+#    #+#             */
/*   Updated: 2025/01/30 11:57:06 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animate_exit(t_data *data)
{
	set_new_fram_exit(data, data->exit1.x, data->exit1.y);
	if (data->coin_collected == 0)
	{
		if (data->e_m < 400)
		{
			create_new_fram_exit(data);
			data->e_m += TILES;
		}
		else if (data->end == 1)
		{
			ft_putstr("You won!\n");
			clear_all(data);
		}
	}
}

void	create_new_fram_exit(t_data *win)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (i < TILES)
	{
		j = win->e_m;
		while (j < win->e_m + TILES)
		{
			color = *(unsigned int *)(win->exit2.addr + (i
						* win->exit2.line_length + j
						* (win->exit2.bits_per_pixel / 8)));
			my_mlx_pixel_put(&win->exit1, j, i, color);
			j++;
		}
		i++;
	}
}

void	set_new_fram_exit(t_data *win, int x, int y)
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
			color = *(unsigned int *)(win->exit1.addr + (i
						* win->exit1.line_length + j
						* (win->exit1.bits_per_pixel / 8)));
			if (color != 0xFF000000)
				my_mlx_pixel_put(&win->back_round, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	create_exit(t_data *win)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	win->exit2.full_imag = mlx_xpm_file_to_image(win->mlx, EXIT, &a, &b);
	win->exit1.addr = mlx_get_data_addr(win->exit1.full_imag,
			&win->exit1.bits_per_pixel, &win->exit1.line_length,
			&win->exit1.endian);
	win->exit2.addr = mlx_get_data_addr(win->exit2.full_imag,
			&win->exit2.bits_per_pixel, &win->exit2.line_length,
			&win->exit2.endian);
	create_new_fram_exit(win);
}
