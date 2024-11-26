/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:20:56 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/26 17:25:49 by asilveir         ###   ########.fr       */
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
		handle_move_left(game);
	}
	if (keysym == XK_Right)
	{
		handle_move_right(game);
	}
	if (keysym == XK_Up)
	{
		handle_move_up(game);
	}
	if (keysym == XK_Down)
	{
		handle_move_down(game);
	}
	return (0);
}
