/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:51:19 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/20 21:06:35 by asilveir         ###   ########.fr       */
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

typedef struct s_background
{
	void	*background_ptr;
	char	*addr;
	int		bpp;
	int		endian;
	int		width;
	int		heigth;
}	t_background;	

typedef struct s_character
{
	void	*character_ptr;
	char	*addr;
	int		bpp;
	int		endian;
	int		width;
	int		height;
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
}	t_game;

// Renderization
int		setup_game(t_game *game);
void	img_pix_put(t_img *img, int x, int y, int color);
void	render_character(t_game *game, int x, int y);
void	render_wall_tile(t_game *game, int x, int y);
int		render_background(t_game *game, char **map);
int		render_background_position(t_game *game, int x, int y);
int		render_blocks(t_game *game);
int		render(t_game *game, char **map);

// Hooks
int		handle_no_event(void	*game);
int		handle_keypress(int keysym, t_game *game);

// Inputs
int		handle_move_left(t_game *game, char **map);
int		handle_move_right(t_game *game, char **map);
int		handle_move_up(t_game *game, char **map);
int		handle_move_down(t_game *game, char **map);
int		handle_background_right(t_game *game, int i, int j, char **map);
int		handle_background_left(t_game *game, int i, int j, char **map);
int		handle_background_down(t_game *game, int i, int j);
int		handle_background_up(t_game *game, int i, int j, char **map);

// Map
char		**init_map();
void free_map(char **map);

#endif