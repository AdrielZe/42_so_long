/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:30:42 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/02 15:27:06 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/main.h"

int	main(int argc, char *argv[])
{
	t_game	game;
	char	**map;

	map = NULL;
	map = parse_map(map, argc, argv);

	game.map.current_map = map;
	setup_game(&game);
	render(&game, map);
	mlx_loop_hook(game.mlx_ptr, check_collectibles, &game);
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &game);
	mlx_loop(game.mlx_ptr);
	free(map);
	free_map(map);
	mlx_destroy_image(game.mlx_ptr, game.door.door_ptr);
	mlx_destroy_image(game.mlx_ptr, game.collectible.collectible_ptr);
	mlx_destroy_image(game.mlx_ptr, game.background.background_ptr);
	mlx_destroy_image(game.mlx_ptr, game.character.character_ptr);
	mlx_destroy_image(game.mlx_ptr, game.wall.wall_ptr);
	mlx_destroy_image(game.mlx_ptr, game.img.mlx_img);
	mlx_destroy_display(game.mlx_ptr);
	free(game.mlx_ptr);
	return (0);
}
