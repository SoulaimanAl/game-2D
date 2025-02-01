/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salahian <salahian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:15:39 by salahian          #+#    #+#             */
/*   Updated: 2025/01/31 17:56:41 by salahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>

# define PLAYER1 "textures/player_run.xpm"
# define PLAYER2 "textures/player_stand.xpm"
# define ENEMY1 "textures/enemy_stand.xpm"
# define ENEMY2 "textures/enemy_run.xpm"
# define COIN "textures/coin.xpm"
# define EXIT "textures/door.xpm"
# define WALL "textures/wall.xpm"
# define FLOOR "textures/floor.xpm"
# define COUNTER "textures/counter.xpm"
# define TILES 100
# define SPEED 20

//////////////////////   test_map    //////////////////////////

typedef struct image
{
	void		*full_imag;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			x;
	int			y;
}				t_img;

typedef struct coins
{
	void		*full_imag;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			x;
	int			y;
}				t_coin;

typedef struct s_enemy
{
	int			x;
	int			y;
	int			direction;
	int			isactive;
	int			speed;
	int			flag;
}				t_enemy;

typedef struct win
{
	int			wiht_win;
	int			hight_win;
}				t_win;

typedef struct window
{
	int			pl;
	char		**map;
	void		*mlx;
	void		*mlx_win;
	t_img		back_round;
	t_img		wall;
	t_img		floor;
	t_img		player;
	t_img		f_imgp;
	t_coin		coin1;
	t_coin		coin2;
	t_img		exit1;
	t_img		exit2;
	t_img		enemy1;
	t_img		enemy2;
	t_img		dis_mov;
	t_enemy		enemy;
	t_win		win;
	int			x;
	int			y;
	char		move;
	int			e_m;
	int			c_m;
	int			ofs;
	int			coin_collected;
	int			dellay;
	int			*ofx;
	int			*ofy;
	int			end;
	int			win_h;
	int			win_w;
	int			moving;
	int			enemy_fram;
	int			dellay_move_p;
	int			death;
	int			moves_count;
}				t_data;

typedef struct player
{
	int			collected_coin;
	int			exit;
	int			p;
	int			x;
	int			y;
}				t_play;

int				help_test_map(char *s, char c);
int				test_map(char **s, char *a, t_play *info);
int				test_adv(char **s, char **map);
void			set_struct(t_play *info);
void			free_map(char **s);
char			**check_map(char *av);
char			**check_m(char *av);
void			check_for_pce(t_play *info, char c, int i, int j);
void			ft_strlcpy(char *dst, const char *src, size_t dstsize);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

/////////////////////////////////////////////////////////////////////////

//////////////////////////	takes_places	////////////////////////////

void			find_pe(t_data *data, int y, int x);
int				get_player(char *s, t_data *data);
void			help_red(t_data *data, int x, int y, char c);
void			help_make_img(t_data *data);
void			make_img(t_data *mlx);
/////////////////////////////////////////////////////////////////////////

//////////////////////////		init_all	/////////////////////////////

void			init_str_win(t_data *sd);
void			init_imag(t_img *f);
////////////////////////////////////////////////////////////////////////

////////////////////////    handle_inputs   ////////////////////////////

int				handle_keys(int keycode, t_data *data);
int				is_valid_pos(t_data *data, int new_x, int new_y);
void			check_pos(t_data *data);
int				check_for_obstacl(t_data *data, int y, int x, int end);
int				check_name(char *av);
////////////////////////////////////////////////////////////////////////

//////////////////////  create_player   ////////////////////////////////

void			create_new_fram_player(t_data *data);
void			clear_place(t_data *data, int old_x, int old_y);
void			set_new_fram_player(t_data *data, int x, int y);
void			clear_prev_player(t_data *data, int old_x, int old_y);
void			create_player(t_data *data);
///////////////////////////////////////////////////////////////////////

////////////////////   create_full_background  ///////////////////////

void			choose_img(t_data *mlx);
void			color_img(t_data *data, int start_x, int start_y, int flag);
void			my_mlx_pixel_put(t_img *mg, int x, int y, unsigned int color);
/////////////////////////////////////////////////////////////////////

///////////////////////// create_exit //////////////////////////////

void			create_exit(t_data *win);
void			set_new_fram_exit(t_data *win, int x, int y);
void			create_new_fram_exit(t_data *win);
void			animate_exit(t_data *data);
////////////////////////////////////////////////////////////////////

/////////////////////// create_coins ///////////////////////////////

void			create_coin(t_data *win);
void			set_new_fram_coin(t_data *win, int x, int y);
void			create_new_fram_coin(t_data *win);
void			animate_coins(t_data *data);
////////////////////////////////////////////////////////////////////

//////////////////////  create_enemy ///////////////////////////////

void			main_func_enemy(t_data *data, t_enemy *enemy);
void			create_new_fram_enemy(t_data *data, int flag);
void			set_new_fram_enemy(t_data *data, int x, int y);
int				is_valid_pos_enemy(t_data *data, int new_x, int new_y);
unsigned int	get_the_color(t_data *data, int i, int j, int flag);
void			move_enemy_towards_player(t_data *data, t_enemy *enemy,
					int player_x, int player_y);
//////////////////////////////////////////////////////////////////

int				loop_game(t_data *data);
void			print_result(t_data *data);
void			update_player_position(t_data *data, int new_x, int new_y);
void			free_map(char **s);
void			clear_all(t_data *data);
int				exit_game(t_data *data);
int				init_imge_window(t_data *data);
void			destroy_images(t_data *data);
void			init_struct_enemy(t_enemy *enemy);
int				check_all_images(t_data *data);
void			ft_putstr(char *s);
void			display_moves(t_data *data);
#endif