/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:18:41 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/22 03:55:21 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/main.h"

void	render_door(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, game->door.door_ptr,
		x * WALL_SIZE, y * WALL_SIZE);
}