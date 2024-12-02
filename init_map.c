/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:02:51 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/02 15:20:54 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/main.h"

char	**parse_map(char **map, int argc, char **argv)
{	
	if (argc < 2)
	{
		write(1, "Map file name is missing!\n", 26);
		return (NULL);
	}
	map = read_map(argv[1]);
	if (!map)
	{
		write(1, "Failure reading the map, file name is invalid!\n", 47);
		return (NULL);
	}
	return (map);
}
