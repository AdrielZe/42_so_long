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

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_wall	wall;
}	t_data;

void	render_blocks(t_data *data);
void	render_background(t_img *img, int color);
int	handle_no_event(void	*data);
void	img_pix_put(t_img *img, int x, int y, int color);
int	render(t_data *data);
int	handle_keypress(int keysym, t_data *data);
int	handle_no_event(void	*data);




#endif