#include "./headers/main.h"

char	*map[] = 
{
	"1111111111111111111111111",
	"1000000000000000000000001",
	"1000000000000000000000001",
	"1000001110000011100000001",
	"1000001110000011100000001",
	"1000000000000000000000001",
	"1000000000000000000009001",
	"1000001110000011100000001",
	"1000001110000011100000001",
	"1000000000000000000000001",
	"1000000000000000000000001",
	"1111111111111111111111111",
	NULL
};



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

void	render_wall_tile(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall.wall_ptr, x * WALL_SIZE, y * WALL_SIZE);
}


int	render_map(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(map[j]) 
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == '1')
			{
				render_wall_tile(game, i, j);
			} 
			else if (map[j][i] == '9')
			{
				render_character(game, i, j);
			} 
			i++;
		}
		j++;
	}

	return (0);
}
int	render(t_game *game)
{
    if (game->win_ptr == NULL)
        return (1);

   render_background(&game->img, WHITE_PIXEL);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.mlx_img, 0, 0);
    render_map(game, map);       

    return (0);
}