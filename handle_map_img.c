/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:57:47 by salahian          #+#    #+#             */
/*   Updated: 2025/02/01 16:32:03 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr(char *s)
{
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	help_check_images(t_data *data)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	data->exit2.full_imag = mlx_xpm_file_to_image(data->mlx, EXIT, &a, &b);
	data->floor.full_imag = mlx_xpm_file_to_image(data->mlx, FLOOR, &a, &b);
	data->wall.full_imag = mlx_xpm_file_to_image(data->mlx, WALL, &a, &b);
	data->dis_mov.full_imag = mlx_xpm_file_to_image(data->mlx, COUNTER, &a, &b);
	if (!data->player.full_imag || !data->coin2.full_imag
		|| !data->enemy1.full_imag || !data->exit2.full_imag
		|| !data->wall.full_imag || !data->floor.full_imag
		|| !data->dis_mov.full_imag)
	{
		ft_putstr("ERROR\nThe images not valid!");
		clear_all(data);
		return (0);
	}
	return (1);
}

int	check_all_images(t_data *data)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	data->player.full_imag = mlx_xpm_file_to_image(data->mlx, PLAYER1, &a, &b);
	if (data->player.full_imag)
	{
		mlx_destroy_image(data->mlx, data->player.full_imag);
		data->player.full_imag = mlx_xpm_file_to_image(data->mlx, PLAYER2, &a,
				&b);
	}
	data->coin2.full_imag = mlx_xpm_file_to_image(data->mlx, COIN, &a, &b);
	data->enemy1.full_imag = mlx_xpm_file_to_image(data->mlx, ENEMY1, &a, &b);
	if (data->enemy1.full_imag)
	{
		mlx_destroy_image(data->mlx, data->enemy1.full_imag);
		data->enemy1.full_imag = mlx_xpm_file_to_image(data->mlx, ENEMY2, &a,
				&b);
	}
	if (!help_check_images(data))
		return (0);
	destroy_images(data);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	img;

	if (ac != 2)
		return (1);
	init_str_win(&img);
	img.mlx = mlx_init();
	img.ofx = calloc(1000, sizeof(char));
	if (img.ofx == NULL)
		return (clear_all(&img), 1);
	img.ofy = calloc(1000, sizeof(char));
	if (img.ofy == NULL)
		return (clear_all(&img), 1);
	if (!get_player(av[1], &img) || !check_all_images(&img))
	{
		ft_putstr("ERROR\nThe map not valid!");
		clear_all(&img);
		return (1);
	}
	if (!init_imge_window(&img))
		return (1);
	mlx_hook(img.mlx_win, 02, (1L << 0), handle_keys, &img);
	mlx_hook(img.mlx_win, 17, 0, exit_game, &img);
	make_img(&img);
	mlx_loop_hook(img.mlx, loop_game, &img);
	mlx_loop(img.mlx);
}
