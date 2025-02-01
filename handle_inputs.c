/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:00:19 by salahian          #+#    #+#             */
/*   Updated: 2025/02/01 09:38:46 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_name(char *av)
{
	int	d;

	d = ft_strlen(av);
	if (ft_strlen(av) == 9 || ft_strlen(av) == 11)
		return (0);
	if (ft_strncmp(".ber", &av[d - 4], 4))
		return (0);
	return (1);
}

void	check_pos(t_data *data)
{
	int	map_x;
	int	map_y;

	map_x = data->x / TILES;
	map_y = data->y / TILES;
	if (data->map[map_y][map_x] == '1')
		return ;
	if (data->move == 'l' && data->dellay_move_p > 600)
		update_player_position(data, data->x - SPEED, data->y);
	else if (data->move == 'r' && data->dellay_move_p > 600)
		update_player_position(data, data->x + SPEED, data->y);
	else if (data->move == 'p' && data->dellay_move_p > 600)
		update_player_position(data, data->x, data->y - SPEED);
	else if (data->move == 'd' && data->dellay_move_p > 600)
		update_player_position(data, data->x, data->y + SPEED);
	data->pl += TILES;
	create_new_fram_player(data);
}

int	check_for_obstacl(t_data *data, int y, int x, int end)
{
	while (x <= end)
	{
		if ((data->map[y][x] == '1') || ((data->map[y][x] == 'E')
				&& (data->coin_collected != 0)))
			return (0);
		if (((data->map[y][x] == 'E') && (data->coin_collected == 0)))
		{
			data->end = 1;
			return (0);
		}
		else
			data->end = 0;
		x++;
	}
	return (1);
}

int	is_valid_pos(t_data *data, int new_x, int new_y)
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
		if (!check_for_obstacl(data, y, x, newr))
			return (0);
		y++;
	}
	return (1);
}

int	handle_keys(int keycode, t_data *data)
{
	if (keycode == 65307 || keycode == 65363 || keycode == 65361
		|| keycode == 65364 || keycode == 65362)
	{
		if (keycode == 65307)
			data->move = 'e';
		else if (keycode == 65363 && is_valid_pos(data, data->x + 20, data->y))
			data->move = 'r';
		else if (keycode == 65361 && is_valid_pos(data, data->x - 20, data->y))
			data->move = 'l';
		else if (keycode == 65364 && is_valid_pos(data, data->x, data->y + 20))
			data->move = 'd';
		else if (keycode == 65362 && is_valid_pos(data, data->x, data->y - 20))
			data->move = 'p';
		print_result(data);
	}
	return (1);
}
