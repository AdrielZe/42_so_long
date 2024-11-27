/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:49:18 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/26 20:43:02 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/main.h"

int	render_background(t_game *game, char **map)
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
			mlx_put_image_to_window(game->mlx_ptr,
				game->win_ptr, game->background.background_ptr,
				i * WALL_SIZE, j * WALL_SIZE);
			i++;
		}
		j++;
	}
	return (0);
}

int	render_background_position(t_game *game, int row, int column)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->background.background_ptr,
		row * WALL_SIZE, column * WALL_SIZE);
	return (0);
}
