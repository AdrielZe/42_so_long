/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_inputs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:20:56 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/02 18:11:35 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/main.h"

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		exit(EXIT_FAILURE);
	}
	if (keysym == XK_Left)
	{
		process_left_input(game);
	}
	if (keysym == XK_Right)
	{
		process_right_input(game);
	}
	if (keysym == XK_Up)
	{
		process_up_input(game);
	}
	if (keysym == XK_Down)
	{
		process_down_input(game);
	}
	return (0);
}
