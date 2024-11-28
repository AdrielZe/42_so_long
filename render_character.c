/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_character.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:48:48 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/27 22:54:01 by asilveir         ###   ########.fr       */
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
	static void	*frames[2] = {NULL, NULL};
	static int	current_frame = 0;

	// Inicializa frames apenas na primeira execução
	if (!frames[0])
	{
		frames[0] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./resources/characters/character_to_left_60.xpm",
			&game->wall.width, &game->wall.height);
		frames[1] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./resources/characters/character_to_left_movement_1.xpm",
			&game->wall.width, &game->wall.height);
		if (!frames[0] || !frames[1])
		{
			ft_putstr_fd("Error: failed to load character images\n", 2);
			exit(EXIT_FAILURE);
		}
	}
	current_frame = (current_frame + 1) % 2;
			
		mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, frames[current_frame],
		x * WALL_SIZE, y * WALL_SIZE);
}

void	render_character_to_right(t_game *game, int x, int y)
{
	static void	*frames[2] = {NULL, NULL};
	static int	current_frame = 0;

	if (!frames[0])
	{
		frames[0] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./resources/characters/character_to_right_60.xpm",
			&game->wall.width, &game->wall.height);
		frames[1] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./resources/characters/character_to_right_movement_1.xpm",
			&game->wall.width, &game->wall.height);
		if (!frames[0] || !frames[1])
		{
			ft_putstr_fd("Error: failed to load character images\n", 2);
			exit(EXIT_FAILURE);
		}
	}
	current_frame = (current_frame + 1) % 2;
			
		mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, frames[current_frame],
		x * WALL_SIZE, y * WALL_SIZE);
}

void	render_character_to_up(t_game *game, int x, int y)
{
	static void	*frames[2] = {NULL, NULL};
	static int	current_frame = 0;

	// Inicializa frames apenas na primeira execução
	if (!frames[0])
	{
		frames[0] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./resources/characters/character_to_up_60.xpm",
			&game->wall.width, &game->wall.height);
		frames[1] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./resources/characters/character_to_up_movement_1.xpm",
			&game->wall.width, &game->wall.height);
		if (!frames[0] || !frames[1])
		{
			ft_putstr_fd("Error: failed to load character images\n", 2);
			exit(EXIT_FAILURE);
		}
	}
	current_frame = (current_frame + 1) % 2;
			
		mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, frames[current_frame],
		x * WALL_SIZE, y * WALL_SIZE);
}
void	render_character_to_down(t_game *game, int x, int y)
{
	static void	*frames[2] = {NULL, NULL};
	static int	current_frame = 0;

	// Inicializa frames apenas na primeira execução
	if (!frames[0])
	{
		frames[0] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./resources/characters/character_to_down_60.xpm",
			&game->wall.width, &game->wall.height);
		frames[1] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./resources/characters/character_to_down_movement_1.xpm",
			&game->wall.width, &game->wall.height);
		if (!frames[0] || !frames[1])
		{
			ft_putstr_fd("Error: failed to load character images\n", 2);
			exit(EXIT_FAILURE);
		}
	}
	current_frame = (current_frame + 1) % 2;
			
		mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, frames[current_frame],
		x * WALL_SIZE, y * WALL_SIZE);
}
