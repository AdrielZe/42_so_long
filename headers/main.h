/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:51:19 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/29 00:32:13 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdio.h>
# include "../libft/libft.h"

# define WINDOW_WIDTH 1800
# define WINDOW_HEIGHT 900
# define WHITE_PIXEL 0xFFFFFF
# define MLX_ERROR 1
# define WALL_SIZE 32

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
	t_collectible		collectible;
	t_door			door;
}	t_game;

int		setup_game(t_game *game);
// Renderization
void	render_character(t_game *game, int x, int y);
void	alternate_char_animation_right(t_game *game, int x, int y);
void	alternate_char_animation_left(t_game *game, int x, int y);
void	alternate_char_animation_up(t_game *game, int x, int y);
void	alternate_char_animation_down(t_game *game, int x, int y);
int    move_player_right(t_game *game, int row, int column);
int    move_player_left(t_game *game, int row, int column);
int	move_player_up(t_game *game, int row, int column);
int    move_player_down(t_game *game, int row, int column);
int		process_left_input(t_game *game);
int		process_right_input(t_game *game);
int		process_up_input(t_game *game);
int		process_down_input(t_game *game);
int	move_up_door_locked(t_game *game, int row, int column);
int	move_up_door_unlocked(t_game *game, int row, int column);
int	move_down_door_locked(t_game *game, int row, int column);
int	move_down_door_unlocked(t_game *game, int row, int column);
int	move_right_door_locked(t_game *game, int row, int column);
int	move_right_door_unlocked(t_game *game, int row, int column);
int	move_left_door_locked(t_game *game, int row, int column);
int	move_left_door_unlocked(t_game *game, int row, int column);
int	render_if_player_can_move_left_when_door_is_unlocked(t_game *game, int row, int column);

int	render_unlocked_door(t_game *game);
void	render_door(t_game *game, int x, int y);
void	render_wall_tile(t_game *game, int x, int y);
int		handle_background_up(t_game *game, int i, int j, char **map);

int		render_background_position(t_game *game, int x, int y);
int		render_background(t_game *game, char **map);
int		handle_background_down(t_game *game, int i, int j);
int		handle_background_right(t_game *game, int i, int j, char **map);
int		handle_background_left(t_game *game, int i, int j, char **map);
int		render_blocks(t_game *game);
int		render(t_game *game, char **map);


int		check_collectibles(t_game *game);
void	render_collectible(t_game *game, int x, int y);
// Hooks
int		handle_no_event(void	*game);
int		handle_keypress(int keysym, t_game *game);

// Inputs

// Map
char	**init_map();
void	free_map(char **map);

// Map utils
int	rows_of_map_exist(t_game *game, int row_number);
int	current_row_exists(t_game *game, int row_number, int column_number);
int	found_character_position(t_game *game, int row_number, int column_number);


int	found_door_position(t_game *game, int row_number, int column_number);


#endif