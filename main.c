#include <stdlib.h>
#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdio.h>

// VALGRIND TEST:
// valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./p

// COMPILE: 
// clang main.c -lX11 -lXext -lmlx

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 400

# define MLX_ERROR 1

# define GREEN_PIXEL 0x00FF00
# define WHITE_PIXEL 0xFFFFFF
# define RED_PIXEL 0xFF0000
# define ORANGE_PIXEL 0xFFA500
# define YELLOW_PIXEL 0xFFFF00
# define BLUE_PIXEL 0x00FFFF
# define DARK_BLUE_PIXEL 0x008B8B
# define PURPLE_PIXEL 0xA020F0


// Print squares, circles, triangles and hexagons on the screen by writing the pixels accordingly.
// Try adding gradients, making rainbows, and get comfortable with using the rgb colors.
// Try making textures by generating the image in loops.

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int	height;
	int	width;
	int	bpp;
	int	line_len;
	int	endian;
}	t_img;

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_data;


void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int	i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		// Big endian, MSB is the leftmost bit
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		// Little endian, LSB is the leftmost bit
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i-= 8;
	}
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			img_pix_put(img, j++, i, color);
		++i;
	}
	return ;
}


int	handle_keypress(int keysym, t_data *data)
{ 
	static	int times_c_was_pressed;
	
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	//printf("Keypress: %d\n", keysym);
	return (0);
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	// render_background(&data->img, WHITE_PIXEL);
	// render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, GREEN_PIXEL});

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	printf("Keyrelease: %d\n", keysym);
	return (0);
}

int	handle_no_event(void *data)
{
	// This function needs to exist, but will do nothing for now.
	return (0);
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}
int	main(void)
{
	t_data	data;
	int	x;
	int	y;


	data.mlx_ptr = mlx_init();  // Mlx init creates a structure (struct) that contains all the components minilibx needs in order to run properly
	if (!data.mlx_ptr)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Opening!"); //Creates a window (pointer where the window will be allocated, width, heigth, and title)
	if (!data.win_ptr)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}

	data.img.mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, "New-Piskel.xpm", &data.img.width, &data.img.height);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);

	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);

	render(&data);

	printf("%d", mlx_mouse_get_pos(data.mlx_ptr, data.win_ptr, &x, &y));

	mlx_loop(data.mlx_ptr);


	// mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}