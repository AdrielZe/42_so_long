/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:50:32 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/25 18:33:48 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/main.h"

int	handle_no_event(void	*game)
{
	if (!game)
		return (0);
	return (0);
}

int	check_collectibles(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->map.current_map[j])
	{
		i = 0;
		while (game->map.current_map[j][i])
		{
			if (game->map.current_map[j][i] == 'C')
			{
				// printf("entrou");
				return (1);
			}
			i++;
		}
		j++;
	}
	game->door.door_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
		"./resources/map/unlocked_door_96.xpm",
		&game->wall.width, &game->wall.height);
	render_door(game, 10, 10);
	return (0);
}
