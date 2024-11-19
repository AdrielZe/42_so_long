/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_character.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:48:48 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/19 15:48:57 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/main.h"

void	render_character(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, game->character.character_ptr,
		x * WALL_SIZE, y * WALL_SIZE);
}
