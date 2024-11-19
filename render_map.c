/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:42:31 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/19 19:02:33 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/main.h"


void	render_wall_tile(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, game->wall.wall_ptr,
		x * WALL_SIZE, y * WALL_SIZE);
}

int	render_map(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
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

int	render(t_game *game, char **map)
{
	if (game->win_ptr == NULL)
		return (1);
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, game->img.mlx_img, 0, 0);
	render_background(game, map);
	render_map(game, map);
	return (0);
}
