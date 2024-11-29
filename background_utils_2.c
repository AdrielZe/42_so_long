/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_background.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:26:25 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/29 01:20:28 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/main.h"

int	put_background_right(t_game *game, int i, int j, char **map)
{
	if (map[j][i + 1] != '1' || map[j + 1][i + 1] != '1' )
	{
		background_specific_position_put(game, i + 1, j + 1);
		background_specific_position_put(game, i + 1, j);
		background_specific_position_put(game, i + 2, j);
		background_specific_position_put(game, i + 2, j + 1);
	}
	return (1);
}

int	put_background_left(t_game *game, int i, int j, char **map)
{
	if (map[j][i] != '1' || map[j - 1][i] != '1')
	{
		background_specific_position_put(game, i - 1, j + 1);
		background_specific_position_put(game, i - 1, j);
	}
	return (1);
}

int	put_background_down(t_game *game, int row, int column)
{
	background_specific_position_put(game, row, column + 1);
	background_specific_position_put(game, row, column + 2);
	background_specific_position_put(game, row + 1, column + 2);
	return (0);
}

int	put_background_up(t_game *game, int i, int j, char **map)
{
	if (map[j - 1][i] != '1')
	{
		background_specific_position_put(game, i, j - 1);
		background_specific_position_put(game, i, j - 2);
		background_specific_position_put(game, i + 1, j - 2);
	}
	return (1);
}
