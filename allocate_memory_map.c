/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_memory_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:37:44 by asilveir          #+#    #+#             */
/*   Updated: 2024/11/19 19:02:58 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/main.h"

int	count_rows(char **map)
{
	int	i;

	i = 0;
	while(map[i])
		i++;
	return (i);
}

char	**init_map(char **original_map)
{
	int rows;
	int	i;
	char **map_copy;

	i = 0;
	rows = count_rows(original_map);
	map_copy = malloc(sizeof(char *) * (rows + 1));
	if (!map_copy)
		return (NULL);
	while (i < rows)
	{
		map_copy[i] = ft_strdup(original_map[i]);
		if (!map_copy[i])
		{
			while(i--)
				free(map_copy[i]);
			return (NULL);
		}
		i++;
	}
	map_copy[rows] = NULL;
	return (map_copy);
}

void free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}