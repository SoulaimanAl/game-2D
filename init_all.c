/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:57:44 by salahian          #+#    #+#             */
/*   Updated: 2025/01/30 15:51:04 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_imag(t_img *f)
{
	f->full_imag = 0;
	f->addr = 0;
	f->bits_per_pixel = 0;
	f->line_length = 0;
	f->endian = 0;
	f->x = 0;
	f->y = 0;
}

void	init_coin(t_coin *f)
{
	f->full_imag = 0;
	f->addr = 0;
	f->bits_per_pixel = 0;
	f->line_length = 0;
	f->endian = 0;
	f->x = 0;
	f->y = 0;
}

void	init_win(t_win *win)
{
	win->hight_win = 0;
	win->wiht_win = 0;
}

void	init_var(t_data *sd)
{
	sd->e_m = 0;
	sd->x = 0;
	sd->y = 0;
	sd->dellay = 0;
	sd->coin_collected = 0;
	sd->c_m = 0;
	sd->ofs = 0;
	sd->moving = 0;
	sd->end = 0;
	sd->win_h = 0;
	sd->win_w = 0;
	sd->enemy_fram = 0;
	sd->dellay_move_p = 0;
	sd->death = 0;
	sd->moves_count = 0;
}

void	init_str_win(t_data *sd)
{
	sd->pl = 0;
	sd->map = 0;
	sd->mlx = 0;
	sd->mlx_win = 0;
	sd->move = 0;
	init_imag(&sd->back_round);
	init_imag(&sd->wall);
	init_imag(&sd->f_imgp);
	init_imag(&sd->floor);
	init_imag(&sd->player);
	init_coin(&sd->coin1);
	init_coin(&sd->coin2);
	init_imag(&sd->exit1);
	init_imag(&sd->exit2);
	init_imag(&sd->enemy1);
	init_imag(&sd->enemy2);
	init_imag(&sd->dis_mov);
	init_win(&sd->win);
	init_struct_enemy(&sd->enemy);
	init_var(sd);
}
