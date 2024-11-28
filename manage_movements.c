/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:51:50 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/27 23:50:49 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/main.h"

int	door_is_locked(t_game *game)
{
	return (ft_strcmp(game->door.location, "./resources/map/locked_door_48.xpm") == 0);
}
int	handle_move_left(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (rows_of_map_exist(game, j))
	{
		i = 0;
		while (current_row_exists(game, j, i))
		{
			if (found_character_position(game, j, i))
			{
				if (door_is_locked(game))
					return (move_left_door_locked(game, j, i));
				return (move_left_door_unlocked(game, j, i));
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	handle_move_right(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (rows_of_map_exist(game, j))
	{
		i = 0;
		while (current_row_exists(game, j, i))
		{
			if (found_character_position(game, j, i))
			{
				if (door_is_locked(game))
 					return (render_if_player_can_move_right_when_door_is_locked(game, j, i));
				return render_if_player_can_move_right_when_door_is_unlocked(game, j, i);
			}
			i++;
		}
		j++;
	}
	return (0);
}
int	handle_move_up(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (rows_of_map_exist(game, j))
	{
		i = 0;
		while (current_row_exists(game, j, i))
		{
			if (found_character_position(game, j, i))
			{
				if (door_is_locked(game)) 
					return (render_if_player_can_move_up_when_door_is_locked(game, j, i));
				return (render_if_player_can_move_up_when_door_is_unlocked(game, j, i));
			}
			i++;
		}
		j++;
	}
	return (0);
}


int	handle_move_down(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (rows_of_map_exist(game, j))
	{
		i = 0;
		while (current_row_exists(game, j, i))
		{
			if (found_character_position(game, j, i))
			{
				if (door_is_locked(game))
					return (move_down_door_locked(game, j, i));
				return (move_down_door_unlocked(game, j, i));			
			}
			i++;
		}
		j++;
	}
	return (0);
}
