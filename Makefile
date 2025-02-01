SRC =	coins_code.c	exit_code.c	functions_help.c	handle_inputs.c	help_map_check.c	map_code.c	player_code.c	animate_end.c	enemy_code.c	functions_enemy_code.c	get_next_line.c	get_next_line_utils.c	handle_map_img.c	map_check.c	init_all.c	takes_places.c	game_core.c	handle_movs.c
OBJ = $(SRC:.c=.o)
CFLAG = -Wall -Wextra -Werror
MLXF = -lmlx -lXext -lX11 -lm
RM = rm -f
NAME = so_long

all: $(NAME)

$(NAME): $(OBJ)
	cc $(OBJ) $(MLXF) -o $(NAME)

%.o: %.c
	cc -I. $(CFLAG) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all