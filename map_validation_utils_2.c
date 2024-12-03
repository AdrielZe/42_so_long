/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:22:00 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/02 23:35:26 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/main.h"

//  The map has to be constructed with 3 components: walls, collectibles, and free
//  space.

//  • The map can be composed of only these 5 characters:
//  0 for an empty space,
//  1 for a wall,
//  C for a collectible,
//  E for a map exit,
//  P for the player’s starting position


// The map must contain 1 exit, at least 1 collectible, and 1 starting position to
// be valid

//Functions

// search_exit
// search collectible
// search player
// search_forbidden_character
// only_one_player
// only_one_exit

int	search_exit(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'E')
				return (1);
			i++;
		}
		j++;
	}
	write(1, "Error\nThere are no exits in the map.\n", 37);
	exit(EXIT_FAILURE);
	return (0);
}

int	search_collectible(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				return (1);
			i++;
		}
		j++;
	}
	write(1, "Error\nThere are no collectibles in the map.\n", 44);
	exit(EXIT_FAILURE);
	return (0);
}

int	search_player(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
				return (1);
			i++;
		}
		j++;
	}
	write(1, "Error\nPlayer is not in the map.\n", 32);
	exit(EXIT_FAILURE);
	return (0);
}

int	search_forbidden_character(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] != '0' && map[j][i] != '1' &&
				map[j][i] != 'C' && map[j][i] != 'E' &&
				map[j][i] != 'P' && map[j][i] != '\n')
			{
				write(1, "Error\nForbidden character found!", 32);
				exit(EXIT_FAILURE);
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	only_one_player(char **map)
{
	int	i;
	int	j;
	int	number_of_players;

	j = 0;
	number_of_players = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
				number_of_players++;
			i++;
		}
		j++;
	}
	if (number_of_players > 1)
	{
		write(1, "Error\nMore than one player found in the map", 43);
		exit(EXIT_FAILURE);
	}
	return (0);
}