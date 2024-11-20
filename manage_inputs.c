/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:20:56 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/20 18:02:52 by asilveir         ###   ########.fr       */
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
	if (keysym == XK_Right)
	{
		handle_move_right(game, game->map.current_map);
	}
	if (keysym == XK_Up)
	{
		handle_move_up(game, game->map.current_map);
	}
	if (keysym == XK_Down)
	{
		handle_move_down(game, game->map.current_map);
	}
	return (0);
}


