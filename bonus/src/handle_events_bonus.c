/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:41:34 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/05 01:58:25 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bonus.h"

int	handle_no_event_bonus(void	*game)
{
	if (!game)
		return (0);
	return (0);
}

void	alternate_char_animation_right_test(t_game *game, int test)
{
	int	i;
	int	j;

	j = 0;
	while (rows_of_map_exist(game, j))
	{
		i = 0;
		while (current_row_exists(game, j, i))
		{
			if (found_character_position(game, j, i) == 1)
			{
				static void	*frames[2] = {NULL, NULL};
				static int	current_frame = 0;

				if (!frames[0])
				{
					frames[0] = mlx_xpm_file_to_image(game->mlx_ptr,
					"resources/characters/character_to_right_32.xpm",
					&game->wall.width, &game->wall.height);
					frames[1] = mlx_xpm_file_to_image(game->mlx_ptr,
					"resources/characters/character_to_right_movement_32.xpm",
					&game->wall.width, &game->wall.height);
					if (!frames[0] || !frames[1])
					{
						write(1, "Error\n: failed to load character images\n", 40);
						exit(EXIT_FAILURE);
					}
				}
				if(test == 100)
				{
					current_frame = (current_frame + 1) % 2;
					test = 0;
				}
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, frames[current_frame],
					i * WALL_SIZE, j * WALL_SIZE);
				free_character_frames(frames, game->mlx_ptr);
			}
			i++;
		}
		j++;
	}
	test++;
	
}
int	check_collectibles_bonus(t_game *game)
{
	int	i;
	int	j;
	static int	test = 0;

	j = 0;
	alternate_char_animation_right_test(game, test);
	test++;
	if (test == 200)
		test = 0;
	while (game->map.current_map[j])
	{
		i = 0;
		while (game->map.current_map[j][i])
		{
			if (game->map.current_map[j][i] == 'C')
			{
				return (1);
			}
			i++;
		}
		j++;
	}
	render_unlocked_door(game);
	return (0);
}
