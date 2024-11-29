/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:17:01 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/29 02:45:06 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/main.h"

int	move_player_right(t_game *game, int row, int column)
{
	game->map.current_map[row][column] = '0';
	put_background_left(game, column + 1, row, game->map.current_map);
	alternate_char_animation_right(game, column + 1, row);
	game->map.current_map[row][column + 1] = 'P';
	if (game->map.current_map[row + 1][column + 2] == 'C')
		game->map.current_map[row + 1][column + 2] = '0';
	if (game->map.current_map[row][column + 2] == 'C')
		game->map.current_map[row][column + 2] = '0';
	return (0);
}

int	try_move_right(t_game *game, int row, int column)
{
	if (ft_strcmp(game->door.location,
			"./resources/map/locked_door_48.xpm") == 0)
	{
		if (game->map.current_map[row][column + 2] != '1'
			&& game->map.current_map[row + 1][column + 2] != '1'
			&& game->map.current_map[row][column + 2] != 'E'
			&& game->map.current_map[row + 1][column + 2] != 'E'
			&& game->map.current_map[row - 1][column + 2] != 'E')
			move_player_right(game, row, column);
		return (0);
	}
	if (game->map.current_map[row][column + 2] != '1'
		&& game->map.current_map[row + 1][column + 2] != '1' )
		move_player_right(game, row, column);
	if (game->map.current_map[row][column + 2] == 'E')
		exit (1);
	else if (game->map.current_map[row - 1][column + 2] == 'E')
		exit (1);
	else if (game->map.current_map[row + 1][column + 2] == 'E')
		exit (1);
	return (0);
}