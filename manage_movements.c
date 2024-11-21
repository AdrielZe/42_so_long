/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:51:50 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/21 18:59:23 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/main.h"

int	handle_move_left(t_game *game, char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
			{
				if (map[j][i - 1] != '1' && map[j + 1][i - 1] != '1')
				{
					map[j][i] = '0';
					handle_background_right(game, i - 1, j, map);
					render_character_to_left(game, i - 1, j);
					map[j][i - 1] = 'P';
					return (0);
				}
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	handle_move_right(t_game *game, char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
			{
				if (map[j][i + 2] != '1' && map[j + 1][i + 2] != '1')
				{
					map[j][i] = '0';
					handle_background_left(game, i + 1, j, map);
					render_character_to_right(game, i + 1, j);
					map[j][i + 1] = 'P';
					return (0);
				}
			}
			i++;
		}
		j++;
	}
	return (0);
}
int	handle_move_up(t_game *game, char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
			{
				if (map[j - 1][i] != '1' && map[j - 1][i + 1] != '1')
				{
					map[j][i] = '0';
					handle_background_down(game, i, j - 1);
					render_character_to_up(game, i, j - 1);
					map[j - 1][i] = 'P';
					return (0);
				}
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	handle_move_down(t_game *game, char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
			{
				if (map[j + 2][i] != '1' && map[j + 2][i + 1] != '1')
				{
					map[j][i] = '0';
					handle_background_up(game, i, j + 2, map);
					render_character_to_down(game, i, j + 1);
					map[j + 1][i] = 'P';
					return (0);
				}
			}
			i++;
		}
		j++;
	}
	return (0);
}