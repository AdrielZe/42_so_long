/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:41:34 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/05 19:44:21 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bonus.h"

int	handle_no_event_bonus(void	*game)
{
	if (!game)
		return (0);
	return (0);
}

void	alternate_char_animation_right_bonus(t_game *game, int test)
{
	int	i;
	int	j;
 // Chama apenas se ainda não tiver sido carregado.

	j = 0;
	while (rows_of_map_exist(game, j))
	{
		i = 0;
		while (current_row_exists(game, j, i))
		{
			if (found_character_position(game, j, i) == 1)
			{
				if (test % 10 == 0)
					game->char_animations.current_frame = (game->char_animations.current_frame + 1) % 8;
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->char_animations.frames_right_animation[game->char_animations.current_frame],
					i * WALL_SIZE, j * WALL_SIZE);
			}
			i++;
		}
		j++;
	}
	test++;
}

// Função para liberar as imagens da animação no final
void	free_character_framess(t_game *game)
{
	int i;

	for (i = 0; i < 8; i++) // Número de quadros na animação
	{
		if (game->char_animations.frames_right_animation[i] != NULL)
		{
			mlx_destroy_image(game->mlx_ptr, game->char_animations.frames_right_animation[i]);
			game->char_animations.frames_right_animation[i] = NULL;
		}
	}
}


int	check_collectibles_bonus(t_game *game)
{
	int	i;
	int	j;
	static int	test = 0;

	j = 0;
	//alternate_char_animation_right_bonus(game, test);
	test++;
	if (test == 200)
		test = 0;
	while (game->map.current_map[j])
	{
		i = 0;
		while (game->map.current_map[j][i])
		{
			if (game->map.current_map[j][i] == 'C')
				return (1);
			i++;
		}
		j++;
	}
	render_unlocked_door(game);
	return (0);
}
