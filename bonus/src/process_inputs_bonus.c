/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_inputs_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:45:29 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/05 19:51:21 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bonus.h"

int	handle_keypress_bonus(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		close_game(game);
		free_character_framess(game);
		exit(EXIT_FAILURE);
	}
	if (keysym == XK_a)
	{
		process_left_input(game);
	}
	if (keysym == XK_d)
	{
		process_right_input(game);
	}
	if (keysym == XK_w)
	{
		process_up_input(game);
	}
	if (keysym == XK_s)
	{
		process_down_input(game);
	}
	return (0);
}