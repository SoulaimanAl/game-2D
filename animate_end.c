/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:26:49 by salahian          #+#    #+#             */
/*   Updated: 2025/01/30 15:52:14 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_data *data)
{
	clear_all(data);
	return (1);
}

void	destroy_images(t_data *data)
{
	if (data->player.full_imag)
		mlx_destroy_image(data->mlx, data->player.full_imag);
	if (data->wall.full_imag)
		mlx_destroy_image(data->mlx, data->wall.full_imag);
	if (data->floor.full_imag)
		mlx_destroy_image(data->mlx, data->floor.full_imag);
	if (data->coin2.full_imag)
		mlx_destroy_image(data->mlx, data->coin2.full_imag);
	if (data->exit2.full_imag)
		mlx_destroy_image(data->mlx, data->exit2.full_imag);
	if (data->enemy1.full_imag)
		mlx_destroy_image(data->mlx, data->enemy1.full_imag);
	if (data->dis_mov.full_imag)
		mlx_destroy_image(data->mlx, data->dis_mov.full_imag);
	data->player.full_imag = 0;
	data->wall.full_imag = 0;
	data->floor.full_imag = 0;
	data->enemy1.full_imag = 0;
	data->exit2.full_imag = 0;
	data->coin2.full_imag = 0;
	data->dis_mov.full_imag = 0;
}

void	free_rest(t_data *data)
{
	if (data->dis_mov.full_imag)
		mlx_destroy_image(data->mlx, data->dis_mov.full_imag);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->map)
		free_map(data->map);
	if (data->ofx)
		free(data->ofx);
	if (data->ofy)
		free(data->ofy);
}

void	clear_all(t_data *data)
{
	if (data->player.full_imag)
		mlx_destroy_image(data->mlx, data->player.full_imag);
	if (data->f_imgp.full_imag)
		mlx_destroy_image(data->mlx, data->f_imgp.full_imag);
	if (data->back_round.full_imag)
		mlx_destroy_image(data->mlx, data->back_round.full_imag);
	if (data->wall.full_imag)
		mlx_destroy_image(data->mlx, data->wall.full_imag);
	if (data->floor.full_imag)
		mlx_destroy_image(data->mlx, data->floor.full_imag);
	if (data->coin1.full_imag)
		mlx_destroy_image(data->mlx, data->coin1.full_imag);
	if (data->coin2.full_imag)
		mlx_destroy_image(data->mlx, data->coin2.full_imag);
	if (data->exit1.full_imag)
		mlx_destroy_image(data->mlx, data->exit1.full_imag);
	if (data->exit2.full_imag)
		mlx_destroy_image(data->mlx, data->exit2.full_imag);
	if (data->enemy1.full_imag)
		mlx_destroy_image(data->mlx, data->enemy1.full_imag);
	if (data->enemy2.full_imag)
		mlx_destroy_image(data->mlx, data->enemy2.full_imag);
	free_rest(data);
	exit(0);
}
