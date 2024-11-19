/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:20:56 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/19 19:34:21 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/main.h"


int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	}
	if (keysym == XK_Left)
	{
		handle_move_left(game, game->map.current_map);
	}
	return (0);
}
int	handle_background_position(t_game *game, int i, int j)
{
	render_background_position(game, i + 1, j + 1);
	render_background_position(game, i + 1, j + 2);
	render_background_position(game, i + 1, j);
	render_background_position(game, i + 2, j);
	render_background_position(game, i + 2, j + 1);
	return (1);
}

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
			if (map[j][i] == '9')
			{
				if (map[j][i - 1] != '1')
				{
					map[j][i] = '0';
					handle_background_position(game, i - 1, j);
					render_character(game, i - 1, j);
					map[j][i - 1] = '9';
					return (0);
				}
			}
			i++;
		}
		j++;
	}
	return (0);
}

// int	handle_move_right(t_game *game, char **map)
// {
// 	int	i;
// 	int	j;

// 	j = 0;
// 	while (map[j])
// 	{
// 		i = 0;
// 		while (map[j][i])
// 		{
// 			if (map[j][i] == '9')
// 			{
// 				if (map[j][i + 1] != '1')
// 				{
// 					map[j][i] = '0';
// 					handle_background_position(game, i + 1, j);
// 					render_character(game, i - 1, j);
// 					map[j][i + 1] = '9';
// 					return (0);
// 				}
// 			}
// 			i++;
// 		}
// 		j++;
// 	}
// 	return (0);
// }
