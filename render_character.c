#include "./headers/main.h"

void	render_character(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->character.character_ptr, x * WALL_SIZE, y * WALL_SIZE);
}