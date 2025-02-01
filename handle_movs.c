/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:48:02 by salahian          #+#    #+#             */
/*   Updated: 2025/01/30 16:33:08 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_fram_count(t_data *win)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (i < TILES)
	{
		j = 0;
		while (j < TILES)
		{
			color = *(unsigned int *)(win->dis_mov.addr + (i
						* win->dis_mov.line_length + j
						* (win->dis_mov.bits_per_pixel / 8)));
			my_mlx_pixel_put(&win->back_round, j, i, color);
			j++;
		}
		i++;
	}
}

void	create_img_counter(t_data *win)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (win->dis_mov.full_imag)
		mlx_destroy_image(win->mlx, win->dis_mov.full_imag);
	win->dis_mov.full_imag = mlx_xpm_file_to_image(win->mlx, COUNTER, &a, &b);
	win->dis_mov.addr = mlx_get_data_addr(win->dis_mov.full_imag,
			&win->dis_mov.bits_per_pixel, &win->dis_mov.line_length,
			&win->dis_mov.endian);
}

void	format_moves(int moves, char *temp)
{
	int		i;
	int		num;
	int		start;
	char	tmp;

	i = 0;
	num = moves;
	if (num == 0)
		temp[i++] = '0';
	while (num > 0)
	{
		temp[i++] = (num % 10) + '0';
		num /= 10;
	}
	temp[i] = '\0';
	start = 0;
	i--;
	while (start < i)
	{
		tmp = temp[start];
		temp[start] = temp[i];
		temp[i] = tmp;
		start++;
		i--;
	}
}

void	display_moves(t_data *data)
{
	char	text[20];

	format_moves(data->moves_count, text);
	mlx_string_put(data->mlx, data->mlx_win, 40, 65, 0, text);
	mlx_string_put(data->mlx, data->mlx_win, 41, 65, 0, text);
	mlx_string_put(data->mlx, data->mlx_win, 42, 65, 0, text);
	create_img_counter(data);
	create_fram_count(data);
}
