/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:18:41 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/26 19:48:02 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/main.h"

void	render_door(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, game->door.door_ptr,
		x * WALL_SIZE, y * WALL_SIZE);
}

int	render_unlocked_door(t_game *game)
{
	int	i;
	int	j;
	
	j = 0;
	while (game->map.current_map[j])
	{
		i = 0;
		while (game->map.current_map[j][i])
		{
			if (game->map.current_map[j][i] == 'E')
			{
				if (door_unlocked == 0)
				{
					mlx_destroy_image(game->mlx_ptr, game->door.door_ptr);
					game->door.door_ptr = NULL; 
					game->door.door_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
						"./resources/map/unlocked_door_48.xpm",
						&game->wall.width, &game->wall.height);
					game->door.location = "./resources/map/unlocked_door_48.xpm";
					render_door(game, i, j);
					door_unlocked = 1;
					printf("-- %d --", door_unlocked);
					return (1);
				}
			}
			i++;
		}
		j++;
	}
	return (0);
}
