/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_animations_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:21:30 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/05 19:32:31 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bonus.h"
//character_to_right_animation_1_bonus.xpm
int	setup_right_animation(t_game *game)
{
	// game->char_animations.current_frame = 0;
	game->char_animations.frames_right_animation[0] = mlx_xpm_file_to_image(game->mlx_ptr,
					"resources/characters/character_to_right_animation_1_bonus.xpm",
					&game->wall.width, &game->wall.height);
	if (!game->char_animations.frames_right_animation[0])
		printf("erro");
	game->char_animations.frames_right_animation[1] = mlx_xpm_file_to_image(game->mlx_ptr,
					"resources/characters/character_to_right_animation_2_bonus.xpm",
					&game->wall.width, &game->wall.height);
	game->char_animations.frames_right_animation[2] = mlx_xpm_file_to_image(game->mlx_ptr,
					"resources/characters/character_to_right_animation_3_bonus.xpm",
					&game->wall.width, &game->wall.height);
	game->char_animations.frames_right_animation[3] = mlx_xpm_file_to_image(game->mlx_ptr,
					"resources/characters/character_to_right_animation_4_bonus.xpm",
					&game->wall.width, &game->wall.height);
	game->char_animations.frames_right_animation[4] = mlx_xpm_file_to_image(game->mlx_ptr,
					"resources/characters/character_to_right_animation_5_bonus.xpm",
					&game->wall.width, &game->wall.height);
	game->char_animations.frames_right_animation[5] = mlx_xpm_file_to_image(game->mlx_ptr,
					"resources/characters/character_to_right_animation_6_bonus.xpm",
					&game->wall.width, &game->wall.height);
	game->char_animations.frames_right_animation[6] = mlx_xpm_file_to_image(game->mlx_ptr,
					"resources/characters/character_to_right_animation_7_bonus.xpm",
					&game->wall.width, &game->wall.height);
	game->char_animations.frames_right_animation[7] = mlx_xpm_file_to_image(game->mlx_ptr,
					"resources/characters/character_to_right_animation_8_bonus.xpm",
					&game->wall.width, &game->wall.height);
	return (0);					
}
