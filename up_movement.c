/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:08:16 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/27 22:46:55 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/main.h"

int	move_and_render_player_up(t_game *game, int row, int column)
{
	game->map.current_map[row][column] = '0';
	handle_background_down(game, column, row - 1);
	render_character_to_up(game, column, row - 1);
	game->map.current_map[row - 1][column] = 'P';
	if (game->map.current_map[row - 1][column + 1] == 'C')
		game->map.current_map[row - 1][column + 1] = '0';
	return (0);
}

int	render_if_player_can_move_up_when_door_is_locked(t_game *game, int row, int column)
{
	if (game->map.current_map[row - 1][column] != '1' && 
			game->map.current_map[row - 1][column + 1] != '1' &&
			game->map.current_map[row - 2][column] != 'E' &&
			game->map.current_map[row - 2][column + 1] != 'E' &&
			game->map.current_map[row - 2][column - 1] != 'E')
				move_and_render_player_up(game, row, column);
	return (0);
}

int	render_if_player_can_move_up_when_door_is_unlocked(t_game *game, int row, int column)
{
	if(game->map.current_map[row - 1][column] != '1' 
		&& game->map.current_map[row - 1][column + 1] != '1')
		move_and_render_player_up(game, row, column);
	if(game->map.current_map[row - 2][column] == 'E')
		exit(1);	
	return (0);
}