/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_character.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:48:48 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/21 19:30:10 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/main.h"

void	render_character(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, game->character.character_ptr,
		x * WALL_SIZE, y * WALL_SIZE);
}

void	render_character_to_left(t_game *game, int x, int y)
{
	if (game->character.character_ptr)
		mlx_destroy_image(game->mlx_ptr, game->character.character_ptr);
	game->character.character_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./resources/characters/character_to_left_60.xpm",
			&game->wall.width, &game->wall.height);
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, game->character.character_ptr,
		x * WALL_SIZE, y * WALL_SIZE);
}

void	render_character_to_right(t_game *game, int x, int y)
{
	if (game->character.character_ptr)
		mlx_destroy_image(game->mlx_ptr, game->character.character_ptr);
	game->character.character_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./resources/characters/character_to_right_movement_1.xpm",
			&game->wall.width, &game->wall.height);
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, game->character.character_ptr,
		x * WALL_SIZE, y * WALL_SIZE);
}

void	render_character_to_up(t_game *game, int x, int y)
{
	if (game->character.character_ptr)
		mlx_destroy_image(game->mlx_ptr, game->character.character_ptr);
	game->character.character_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./resources/characters/character_to_right_60.xpm",
			&game->wall.width, &game->wall.height);
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, game->character.character_ptr,
		x * WALL_SIZE, y * WALL_SIZE);
}
void	render_character_to_down(t_game *game, int x, int y)
{
	if (game->character.character_ptr)
		mlx_destroy_image(game->mlx_ptr, game->character.character_ptr);
	game->character.character_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./resources/characters/character_to_right_60.xpm",
			&game->wall.width, &game->wall.height);
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, game->character.character_ptr,
		x * WALL_SIZE, y * WALL_SIZE);
}
