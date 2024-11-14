#include <stdlib.h>
#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>


# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 400
# define WHITE_PIXEL 0xFFFFFF
# define MLX_ERROR 1

typedef struct s_xpm_img
{
	void	*mlx_xpm_img;
	char	*addr;
	int	bpp;
	int	line_len;
	int	endian;
	int	width;
	int	height;
}	t_xpm_img;

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
	t_xpm_img	xpm_img;
}	t_data;

int	handle_no_event(void	*data)
{
	return(0);
}

void	img_pix_put(t_img *img, int x, int y, int color) //Coloca um pixel em um ponto específico dentro de uma imagem
{
    char    *pixel;
    int		i;

    i = img->bpp - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
    while (i >= 0)
    {
        /* big endian, MSB is the leftmost bit */
        if (img->endian != 0)
            *pixel++ = (color >> i) & 0xFF;
        /* little endian, LSB is the leftmost bit */
        else
            *pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
        i -= 8;
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
        {
            img_pix_put(img, j++, i, color);
        }
        ++i;
    }
}

int	render(t_data *data)
{
    if (data->win_ptr == NULL)
        return (1);

    render_background(&data->img, WHITE_PIXEL);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
 mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->xpm_img.mlx_xpm_img, 1, 1);

    return (0);
}

int	handle_keypress(int keysym, t_data *data) // keysym == key released
{
	// If the key released was ESC,  we close (destroy) the window.
	if (keysym == XK_Escape) 
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int	main(void)
{
	t_data data;

	data.mlx_ptr = mlx_init(); // Get resources form minilibx
	if (!data.mlx_ptr)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "GAME!!!!!!"); 
	if (!data.win_ptr)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	
	//Set up image
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.xpm_img.mlx_xpm_img = mlx_xpm_file_to_image(data.mlx_ptr, "grass_block_32.xpm", &data.xpm_img.width, &data.xpm_img.height);
	//data.xpm_img.addr = mlx_get_data_addr(data.xpm_img.mlx_xpm_img, &data.xpm_img.bpp, &data.xpm_img.line_len, &data.xpm_img.endian);


	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	// Hooks
	//mlx_loop_hook(data.mlx_ptr, &render, &data); // This hook is triggered when there's no event processed. We use it to end the loop when we close our window
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data); //It is similar to a key hook, but we have two more parameters, the first and the second, where we have the name and the mask of the X event we want to use
	//mlx_key_hook(data.win_ptr, &handle_input, &data); //mlx_key_hook executes the 'handle_input' function, each time a key is released. The parameters are the win_ptr, a function we want to execute and the address of the t_data object that contains the attributes we need to access in handle_input(our function)
	render(&data);
	mlx_loop(data.mlx_ptr); // Responsável por iniciar o loop de eventos do programa, permitindo que ele responda a eventos como entradas de teclado, movimentação do mouse, cliques, etc.
	// Once finished the program, free resources allocated
	//render(&data);

	// Destroy displays to avoid memory leaks ( the display is the connexion identifier used  to connect with the X server)
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr); 

	// Free pointers
	free(data.mlx_ptr);
}