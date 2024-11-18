#include "./headers/main.h"

int	handle_keypress(int keysym, t_game *game) // keysym == key pressed
{
	// If the key released was ESC,  we close (destroy) the window.
	if (keysym == XK_Escape) 
	{
		printf("pressed");
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	}
	return (0);
}

