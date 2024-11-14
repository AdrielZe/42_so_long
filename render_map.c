#include "./headers/main.h"

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