#include "./headers/main.h"

char	*mapt[] = 
{
	"11111111111111111111111111111111111111111111111111111111",
	"10000000000000000000000000000000000000000000000000000001",
	"10000000000000000000000000000000000000000000000000000001",
	"10000000000000000000000000000000000000000000000000000001",
	"10000000000000000000000000000000000000000000000000000001",
	"10000000000000000000000000000000000000000000000000000001",
	"10000000000000000000000000000000000000000000000000000001",
	"10000000000000000000000000000000000000000000000000000001",
	"10000000000000000000000000000001001000000000000000000001",
	"10000000000000000000000000000001001000000000000000000001",
	"10000000000000000000000000111110001000000000000000000001",
	"10000000000000000000000011000000001000000000000000000001",
	"10000000000000000000000010001111011000000000000000000001",
	"10000000000000000000000010010000000000000000000000000001",
	"10000000000000000000000010010000000000000000000000000001",
	"10000000000000000000000010010000000000000000000000000001",
	"10000000000000000000000010010000000000000000000000000001",
	"10000000000000000000000010010000000000000000000000000001",
	"10000000000000000000000000000000000000000000000000000001",
	"10000000000000000000000000000000000000000000000000000001",
	"10000000000000000000000000000000000000000000000000000001",
	"10000000000000000000000000000000000000000000000000000001",
	"10000000000000000000000000000000000000000900000000000001",
	"10000000000000000000000000000000000000000000000000000001",
	"10000000000000000000000000000000000000000000000000000001",
	"10000000000000000000000000000000000000000000000000000001",
	"10000000000000000000000000000000000000000000000000000001",
	"11111111111111111111111111111111111111111111111111111111",
	NULL
};

int	handle_keypress(int keysym, t_game *game) // keysym == key pressed
{
	// If the key released was ESC,  we close (destroy) the window.
	if (keysym == XK_Escape) 
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	}
	if (keysym == XK_Left)
	{
		handle_move_left(game, mapt);
	}
	return (0);
}

int	handle_move_left(t_game *game, char **map) // keysym == key pressed
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{	
		i = 0;
		while(map[j][i])
		{
			if (map[j][i] == '9')
			{
				if ((char)map[i--] != '1')
				{
					// map[j][i] = '0';
					render_background_position(game, i + 1, j + 1);
					render_background_position(game, i + 1, j + 2);
					render_background_position(game, i + 1, j);
					render_background_position(game, i + 2, j);
					render_background_position(game, i + 2, j + 1);
					render_character(game, i - 1, j);
					// map[j][i] = '9';
					return (0);
				}
			} 
			i++;
		}
		j++;
	}
	return (0);
}
