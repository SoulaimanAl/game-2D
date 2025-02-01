/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:45:00 by salahian          #+#    #+#             */
/*   Updated: 2025/02/01 16:23:53 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	loop_game(t_data *data)
{
	if (data->death)
	{
		clear_all(data);
		return (0);
	}
	data->moving = 1;
	data->dellay_move_p++;
	check_pos(data);
	if (data->dellay == 1000)
	{
		animate_coins(data);
		animate_exit(data);
		if (data->enemy.isactive)
			main_func_enemy(data, &data->enemy);
		set_new_fram_player(data, data->x, data->y);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->back_round.full_imag, 0, 0);
		display_moves(data);
		data->dellay = 0;
	}
	data->dellay++;
	return (1);
}

void	update_player_position(t_data *data, int new_x, int new_y)
{
	data->move = 0;
	clear_prev_player(data, data->x, data->y);
	data->x = new_x;
	data->y = new_y;
	set_new_fram_player(data, data->x, data->y);
	data->dellay_move_p = 0;
	data->moving = 0;
	data->moves_count++;
	display_moves(data);
}

void	print_result(t_data *data)
{
	if (data->move == 'e')
		clear_all(data);
	loop_game(data);
	create_player(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->back_round.full_imag, 0, 0);
}

int	init_imge_window(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx, data->win.wiht_win,
			data->win.hight_win, "GAME");
	data->back_round.full_imag = mlx_new_image(data->mlx, data->win.wiht_win,
			data->win.hight_win);
	data->back_round.addr = mlx_get_data_addr(data->back_round.full_imag,
			&data->back_round.bits_per_pixel, &data->back_round.line_length,
			&data->back_round.endian);
	data->f_imgp.full_imag = mlx_new_image(data->mlx, TILES, TILES);
	data->exit1.full_imag = mlx_new_image(data->mlx, TILES, TILES);
	data->coin1.full_imag = mlx_new_image(data->mlx, TILES, TILES);
	data->enemy2.full_imag = mlx_new_image(data->mlx, TILES, TILES);
	if (!data->mlx_win || !data->back_round.full_imag || !data->f_imgp.full_imag
		|| !data->exit1.full_imag || !data->f_imgp.full_imag
		|| !data->exit1.full_imag)
	{
		clear_all(data);
		return (0);
	}
	return (1);
}
