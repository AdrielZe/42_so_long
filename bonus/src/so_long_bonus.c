/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:28:06 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/05 01:04:09 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bonus.h"
#include "../headers/main.h"



int	main(int argc, char *argv[])
{
	t_game	game;
	char	**map;

	map = NULL;
	map = parse_map(map, argc, argv);
	game.map.current_map = map;
	search_flood_fill(&game);
	setup_game(&game);
	render(&game, map);
	mlx_loop_hook(game.mlx_ptr, check_collectibles_bonus, &game);
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &game);
	mlx_hook(game.win_ptr, 17, 0, close_game_when_x_is_clicked, &game);
	mlx_loop(game.mlx_ptr);
	close_game(&game);
	free(map);
	return (0);
}