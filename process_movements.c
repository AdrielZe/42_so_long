/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:51:50 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/29 00:27:46 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/main.h"

int	door_is_locked(t_game *game)
{
	return (ft_strcmp(game->door.location,
			"./resources/map/locked_door_48.xpm") == 0);
}

int	process_left_input(t_game *game)
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

int	process_right_input(t_game *game)
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
					return (move_right_door_locked(game, j, i));
				return (move_right_door_unlocked(game, j, i));
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	process_up_input(t_game *game)
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
					return (move_up_door_locked(game, j, i));
				return (move_up_door_unlocked(game, j, i));
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	process_down_input(t_game *game)
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
