#include <stdlib.h>
#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdio.h>

// VALGRIND TEST:

// gcc -g -o p test.c
// valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./p

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 400

# define MLX_ERROR 1

# define GREEN_PIXEL 0x00FF00

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

int	render_rect(t_data *data, t_rect rect)
{
	int	i;
	int	j;

	if (data->win_ptr == NULL)
		return (1);
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, rect.color);
		++i;
	}
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{ 
	static	int times_c_was_pressed;
	
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	printf("Keypress: %d\n", keysym);
	return (0);
}

int	render(t_data *data)
{
	render_rect(data, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, GREEN_PIXEL});
	render_rect(data, (t_rect){0 ,0, 100, 100, GREEN_PIXEL});
	
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