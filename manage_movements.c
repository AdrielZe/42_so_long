/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:51:50 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/26 18:57:44 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/main.h"

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
	while (game->map.current_map[j])
	{
		i = 0;
		while (game->map.current_map[j][i])
		{
			if (game->map.current_map[j][i] == 'P')
			{
				if (game->map.current_map[j - 1][i] != '1' && game->map.current_map[j - 1][i + 1] != '1' &&
				 	game->map.current_map[j - 2][i] != 'E' && game->map.current_map[j - 2][i + 1] != 'E' &&
						game->map.current_map[j - 2][i - 1] != 'E')
				{
					game->map.current_map[j][i] = '0';
					handle_background_down(game, i, j - 1);
					render_character_to_up(game, i, j - 1);
					game->map.current_map[j - 1][i] = 'P';
					if(game->map.current_map[j - 1][i + 1] == 'C')
					{
						game->map.current_map[j - 1][i + 1] = '0';	
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
			i++;
		}
		j++;
	}
	return (0);
}

