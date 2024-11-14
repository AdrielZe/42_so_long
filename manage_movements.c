#include "./headers/main.h"

int	handle_keypress(int keysym, t_data *data) // keysym == key released
{
	// If the key released was ESC,  we close (destroy) the window.
	if (keysym == XK_Escape) 
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int	render(t_data *data)
{
    if (data->win_ptr == NULL)
        return (1);

    render_background(&data->img, WHITE_PIXEL);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
       
    render_blocks(data);

    return (0);
}