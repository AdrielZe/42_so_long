/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:11:45 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/29 00:22:15 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/main.h"

int	move_player_down(t_game *game, int row, int column)
{
	game->map.current_map[row][column] = '0';
	handle_background_up(game, column, row + 2, game->map.current_map);
	alternate_char_animation_down(game, column, row + 1);
	game->map.current_map[row + 1][column] = 'P';
	if (game->map.current_map[row + 2][column + 1] == 'C')
		game->map.current_map[row + 2][column + 1] = '0';
	if (game->map.current_map[row + 2][column] == 'C')
		game->map.current_map[row + 2][column] = '0';
	return (0);
}

int	move_down_door_locked(t_game *game, int row, int column)
{
	if (game->map.current_map[row + 2][column] != '1'
		&& game->map.current_map[row + 2][column + 1] != '1'
		&& game->map.current_map[row + 2][column] != 'E'
		&& game->map.current_map[row + 2][column + 1] != 'E'
		&& game->map.current_map[row + 2][column - 1] != 'E')
		move_player_down(game, row, column);
	return (0);
}

int	move_down_door_unlocked(t_game *game, int row, int column)
{
	if (game->map.current_map[row + 2][column] != '1'
		&& game->map.current_map[row + 2][column + 1] != '1')
		move_player_down(game, row, column);
	if (game->map.current_map[row + 2][column] == 'E')
		exit(1);
	else if (game->map.current_map[row + 2][column - 1] == 'E')
		exit(1);
	else if (game->map.current_map[row + 2][column + 1] == 'E')
		exit(1);
	return (0);
}
