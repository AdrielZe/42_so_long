# ifndef MAIN_H
# define MAIN_H

#include <stdlib.h>
#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdio.h>


# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 400
# define WHITE_PIXEL 0xFFFFFF
# define MLX_ERROR 1
# define WALL_SIZE 32


typedef struct s_charater
{
	void	*character_ptr;
	char	*addr;
	int	bpp;
	int	endian;
	int	width;
	int	height;
}	t_character;

typedef struct s_wall
{
	void	*wall_ptr;
	char	*addr;
	int	bpp;
	int	line_len;
	int	endian;
	int	width;
	int	height;
}	t_wall;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int	bpp;
	int	line_len;
	int	endian;
}	t_img;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_wall	wall;
	t_character character;
}	t_game;

int	render_blocks(t_game *game);
int	handle_no_event(void	*game);
void	img_pix_put(t_img *img, int x, int y, int color);
void	render_character(t_game *game, int x, int y);
int	render(t_game *game);
int	handle_keypress(int keysym, t_game *game);
int	handle_no_event(void	*game);
void	render_wall_tile(t_game *game, int x, int y);
void	render_background(t_img *img, int color);




#endif