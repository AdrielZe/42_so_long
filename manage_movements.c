#include "./headers/main.h"

int	handle_keypress(int keysym, t_data *data) // keysym == key released
{
	// If the key released was ESC,  we close (destroy) the window.
	if (keysym == XK_Escape) 
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

