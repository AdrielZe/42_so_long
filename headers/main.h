/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:51:19 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/03 01:55:59 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define WINDOW_WIDTH 1800
# define WINDOW_HEIGHT 900
# define WHITE_PIXEL 0xFFFFFF
# define MLX_ERROR 1
# define WALL_SIZE 32

extern int number_of_movements;

typedef struct s_map
{
	char	**current_map;
}	t_map;	

typedef struct s_door
{
	void	*door_ptr;
	char	*addr;
	char	*location;
}	t_door;

typedef struct s_collectible
{
	void	*collectible_ptr;
	char	*addr;
}	t_collectible;

typedef struct s_background
{
	void	*background_ptr;
	char	*addr;
}	t_background;	

typedef struct s_character
{
	void	*character_ptr;
	char	*addr;
}	t_character;

typedef struct s_wall
{
	void	*wall_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_wall;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_background	background;
	t_img			img;
	t_wall			wall;
	t_character		character;
	t_map			map;
	t_collectible	collectible;
	t_door			door;
}	t_game;

char	**parse_map(char **map, int argc, char **argv);
int		setup_game(t_game *game);
int		handle_no_event(void	*game);
int		handle_keypress(int keysym, t_game *game);
int		rows_of_map_exist(t_game *game, int row);
int		current_row_exists(t_game *game, int row, int column);
int		found_character_position(t_game *game, int row, int column);
int		found_door_position(t_game *game, int row_number, int column_number);
int		check_collectibles(t_game *game);
int		move_player_right(t_game *game, int row, int column);
int		move_player_left(t_game *game, int row, int column);
int		move_player_up(t_game *game, int row, int column);
int		move_player_down(t_game *game, int row, int column);
int		process_left_input(t_game *game);
int		process_up_input(t_game *game);
int		process_right_input(t_game *game);
int		process_down_input(t_game *game);
int		try_move_up(t_game *game, int row, int column);
int		try_move_down(t_game *game, int row, int column);
int		try_move_right(t_game *game, int row, int column);
int		try_move_left(t_game *game, int row, int column);
int		render(t_game *game, char **map);
int		render_unlocked_door(t_game *game);
int		render_blocks(t_game *game);
int		put_background_up(t_game *game, int i, int j, char **map);
int		put_background_down(t_game *game, int i, int j);
int		put_background_right(t_game *game, int i, int j, char **map);
int		put_background_left(t_game *game, int i, int j, char **map);
int		background_specific_position_put(t_game *game, int x, int y);
int		background_entire_screen_put(t_game *game, char **map);
void	free_map(char **map);
void	render_character(t_game *game, int x, int y);
void	alternate_char_animation_right(t_game *game, int x, int y);
void	alternate_char_animation_left(t_game *game, int x, int y);
void	alternate_char_animation_up(t_game *game, int x, int y);
void	alternate_char_animation_down(t_game *game, int x, int y);
void	render_door(t_game *game, int x, int y);
void	render_wall_tile(t_game *game, int x, int y);
void	render_collectible(t_game *game, int x, int y);
void	print_number_of_movements();
char	**init_map(char **map);
char	**read_map(char *argv);

// map_validation_utils
int	check_if_map_is_rectangular(char **map);
int	count_rows(char **map);
int	search_walls_horizontally(char **map);
int	search_walls_vertically(char **map);
int	map_is_surrounded_by_walls(char **map);
int	search_exit(char **map);
int	search_collectible(char **map);
int	search_player(char **map);
int	search_forbidden_character(char **map);
int	only_one_player(char **map);
int	only_one_exit(char **map);
#endif