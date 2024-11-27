/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:51:50 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/26 21:31:28 by asilveir         ###   ########.fr       */
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
int	render_if_player_can_move_when_door_is_locked(t_game *game, int row, int column)
{
	if (game->map.current_map[row - 1][column] != '1' && 
			game->map.current_map[row - 1][column + 1] != '1' &&
			game->map.current_map[row - 2][column] != 'E' &&
			game->map.current_map[row - 2][column + 1] != 'E' &&
			game->map.current_map[row - 2][column - 1] != 'E')
	{
		move_and_render_player_up(game, row, column);
	}
	return (0);
}

void	render_if_player_can_move_when_door_is_unlocked(t_game *game, int row, int column)
{
	if(game->map.current_map[row - 1][column] != '1' 
		&& game->map.current_map[row - 1][column + 1] != '1')
		move_and_render_player_up(game, row, column);
	if(game->map.current_map[row - 2][column] == 'E')
		exit(1);	
}

int	rows_of_map_exist(t_game *game, int row_number)
{
	if (game->map.current_map[row_number])
		return (1);
	return (0);
}

int	current_row_exists(t_game *game, int row_number, int column_number)
{
	if (game->map.current_map[row_number][column_number])
		return (1);
	return (0);
}

int	found_character_position(t_game *game, int row_number, int column_number)
{
	if (game->map.current_map[row_number][column_number] == 'P')
		return (1);
	return (0);
}

int	door_is_locked(t_game *game)
{
	return (ft_strcmp(game->door.location, "./resources/map/locked_door_48.xpm") == 0);
}
int	handle_move_left(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->map.current_map[j])
	{
		i = 0;
		while (game->map.current_map[j][i])
		{
			if (game->map.current_map[j][i] == 'P')
			{
				if (game->map.current_map[j][i - 1] != '1' && game->map.current_map[j + 1][i - 1] != '1' &&
					game->map.current_map[j][i - 2] != 'E' && game->map.current_map[j - 1][i - 2] != 'E' && 
						game->map.current_map[j + 1][i - 2] != 'E')
				{
					game->map.current_map[j][i] = '0';
					handle_background_right(game, i - 1, j, game->map.current_map);
					render_character_to_left(game, i - 1, j);
					game->map.current_map[j][i - 1] = 'P';
					if(game->map.current_map[j + 1][i - 1] == 'C')
					{
						game->map.current_map[j + 1][i - 1] = '0';	
					};
					return (0);
				}
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
	while (game->map.current_map[j])
	{
		i = 0;
		while (game->map.current_map[j][i])
		{
			if (game->map.current_map[j][i] == 'P')
			{
				if (game->map.current_map[j][i + 2] != '1' && game->map.current_map[j + 1][i + 2] != '1' &&
					game->map.current_map[j][i + 2] != 'E' && game->map.current_map[j + 1][i + 2] != 'E' &&
						game->map.current_map[j - 1][i + 2] != 'E')
				{
					game->map.current_map[j][i] = '0';
					handle_background_left(game, i + 1, j, game->map.current_map);
					render_character_to_right(game, i + 1, j);
					game->map.current_map[j][i + 1] = 'P';
					if(game->map.current_map[j + 1][i + 2] == 'C')
					{
						game->map.current_map[j + 1][i + 2] = '0';	
					};
					if(game->map.current_map[j][i + 2] == 'C')
					{
						game->map.current_map[j][i + 2] = '0';	
					};
					return (0);
				}
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
					render_if_player_can_move_when_door_is_locked(game, j, i);
				else 
					render_if_player_can_move_when_door_is_unlocked(game, j, i);
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
	while (game->map.current_map[j])
	{
		i = 0;
		while (game->map.current_map[j][i])
		{
			if (game->map.current_map[j][i] == 'P')
			{
				if (door_unlocked == 0)
				{
					if (game->map.current_map[j + 2][i] != '1' && game->map.current_map[j + 2][i + 1] != '1' &&
						game->map.current_map[j + 2][i] != 'E' && game->map.current_map[j + 2][i + 1] != 'E' 
							&& game->map.current_map[j + 2][i - 1] != 'E')
					{
						game->map.current_map[j][i] = '0';
						handle_background_up(game, i, j + 2, game->map.current_map);
						render_character_to_down(game, i, j + 1);
						game->map.current_map[j + 1][i] = 'P';
						if(game->map.current_map[j + 2][i + 1] == 'C')
						{
							game->map.current_map[j + 2][i + 1] = '0';	
						};
						if(game->map.current_map[j + 2][i] == 'C')
						{
							game->map.current_map[j + 2][i] = '0';	
						};
						return (0);
					}
				}
			}
			i++;
		}
		j++;
	}
	return (0);
}
