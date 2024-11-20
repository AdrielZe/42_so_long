#include "./headers/main.h"

int	handle_background_right(t_game *game, int i, int j, char **map)
{
	if (map[j][i + 1] != '1')
	{
		render_background_position(game, i + 1, j + 1);
		render_background_position(game, i + 1, j);
		render_background_position(game, i + 2, j);
		render_background_position(game, i + 2, j + 1);
	}
	return (1);
}

int	handle_background_left(t_game *game, int i, int j)
{
	render_background_position(game, i - 1, j + 1);
	render_background_position(game, i - 1, j);
	return (1);
}

int	handle_background_down(t_game *game, int i, int j)
{
	render_background_position(game, i, j + 1);
	render_background_position(game, i, j + 2);
	render_background_position(game, i + 1, j + 2);
	return (1);
}

int	handle_background_up(t_game *game, int i, int j)
{
	render_background_position(game, i, j - 1);
	render_background_position(game, i, j - 2);
	render_background_position(game, i + 1, j - 1);
	return (1);
}