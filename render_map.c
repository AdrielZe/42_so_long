#include "./headers/main.h"

char	*map[] = 
{
	"1111111111111111111111111",
	"1000000000000000000000001",
	"1000000000000000000000001",
	"1000000000000000000000001",
	"1000000000100010000000001",
	"1000000000000000000000001",
	"1000000000000000000000001",
	"1000000000000100000000001",
	"1000000000000100000000001",
	"1000000000000000000000001",
	"1000000000000000000000001",
	"1111111111111111111111111",
	NULL
};

void	render_blocks(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	// Left column
	while (j < WINDOW_HEIGHT)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall.wall_ptr, 0, j);
		j += 32;
	}
	j = 0;
	// Right column
	while (j < WINDOW_HEIGHT)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall.wall_ptr, 768, j);
		j += 32;
	}
	// Upper row
	while (i < WINDOW_WIDTH)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall.wall_ptr, i, 0);
		i += 32;
	}
	i = 0;
	// Lower row
	while (i < WINDOW_WIDTH)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall.wall_ptr, i, 368);
		i += 32;
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

void render_wall_tile(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall.wall_ptr, x * WALL_SIZE, y * WALL_SIZE);
}

void	render_map(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(map[i])
	{
		j = 0;
		while(map[j])
		{
			if (map[i][j] == '1')
			{
				printf("achou   -- ");
				render_wall_tile(data, i, j);
			} 
			j++;
		}
		i++;
	}
}

int	render(t_data *data)
{
    if (data->win_ptr == NULL)
        return (1);

    render_background(&data->img, WHITE_PIXEL);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
    render_map(data, map);
       
    render_blocks(data);

    return (0);
}