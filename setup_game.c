/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:35:40 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/19 15:05:57 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/main.h"

int	setup_screen(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (MLX_ERROR);
	game->win_ptr = mlx_new_window(game->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, "GAME!!!!!!");
	if (!game->win_ptr)
		return (MLX_ERROR);
	game->img.mlx_img = mlx_new_image(game->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->img.mlx_img)
		return (MLX_ERROR);
	return (0);
}

int	setup_game(t_game *game)
{
	setup_screen(game);
	game->background.background_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./resources/map/background_32.xpm",
			&game->wall.width, &game->wall.height);
	game->wall.wall_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./resources/map/grass_block_32.xpm",
			&game->wall.width, &game->wall.height);
	game->character.character_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./resources/characters/character_60.xpm",
			&game->wall.width, &game->wall.height);
	if (!game->background.background_ptr
		|| !game->wall.wall_ptr || !game->character.character_ptr)
		return (MLX_ERROR);
	game->img.addr = mlx_get_data_addr(game->img.mlx_img, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
	return (0);
}