/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 08:57:34 by salahian          #+#    #+#             */
/*   Updated: 2025/01/30 11:56:46 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct_enemy(t_enemy *enemy)
{
	enemy->x = 0;
	enemy->y = 0;
	enemy->direction = 1;
	enemy->isactive = 0;
	enemy->speed = SPEED;
	enemy->flag = 0;
}

void	make_img_enemy(t_data *data, t_enemy *enemy, int flag)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (data->enemy1.full_imag)
		mlx_destroy_image(data->mlx, data->enemy1.full_imag);
	if (flag)
		data->enemy1.full_imag = mlx_xpm_file_to_image(data->mlx, ENEMY1, &a,
				&b);
	else
		data->enemy1.full_imag = mlx_xpm_file_to_image(data->mlx, ENEMY2, &a,
				&b);
	data->enemy2.addr = mlx_get_data_addr(data->enemy2.full_imag,
			&data->enemy2.bits_per_pixel, &data->enemy2.line_length,
			&data->enemy2.endian);
	data->enemy1.addr = mlx_get_data_addr(data->enemy1.full_imag,
			&data->enemy1.bits_per_pixel, &data->enemy1.line_length,
			&data->enemy1.endian);
	create_new_fram_enemy(data, enemy->flag);
	set_new_fram_enemy(data, enemy->x, enemy->y);
}

int	check_collision(t_data *data, int player_x, int player_y, t_enemy *enemy)
{
	if (player_x / TILES == enemy->x / TILES && player_y / TILES == enemy->y
		/ TILES)
	{
		data->death = 1;
		ft_putstr("You lose!\n");
		print_result(data);
		return (1);
	}
	return (0);
}

void	render_enemy(t_data *data, t_enemy *enemy)
{
	if (data->x == enemy->x)
	{
		enemy->flag = 1;
		make_img_enemy(data, enemy, enemy->flag);
		data->enemy_fram += TILES;
		create_new_fram_enemy(data, enemy->flag);
		set_new_fram_enemy(data, enemy->x, enemy->y);
		enemy->flag = 0;
	}
	else
	{
		data->enemy_fram += TILES;
		create_new_fram_enemy(data, enemy->flag);
		set_new_fram_enemy(data, enemy->x, enemy->y);
	}
	check_collision(data, data->x, data->y, enemy);
}

void	main_func_enemy(t_data *data, t_enemy *enemy)
{
	make_img_enemy(data, enemy, enemy->flag);
	clear_prev_player(data, enemy->x, enemy->y);
	move_enemy_towards_player(data, enemy, data->x, data->y);
	render_enemy(data, enemy);
	check_collision(data, data->x, data->y, enemy);
}
