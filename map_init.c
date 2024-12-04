/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:02:51 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/04 00:54:07 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/main.h"
#include "string.h"

char	**read_map(char *argv)
{
	char	**map;
	char	*line;
	int		fd;
	int		i;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = (char **)malloc(sizeof(char *) * 1024);
	if (!map)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

char	*join_strings(char const *s1, char const *s2)
{
	char	*arr;
	int		len_s1;
	int		len_s2;
	int		i;

	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	arr = (char *)malloc(len_s1 + len_s2 + 1);
	if (!arr)
		return (NULL);
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		arr[len_s1] = s2[i];
		len_s1++;
		i++;
	}
	arr[len_s1] = '\0';
	return (arr);
}

char	**parse_map(char **map, int argc, char **argv)
{	
	char	*path;

	if (argc < 2)
	{
		write(1, "Error\nMap file name is missing!\n", 32);
		exit(EXIT_FAILURE);
	}
	path = join_strings("maps/", argv[1]);
	map = read_map(path);
	free(path);
	if (!map)
	{
		write(1, "Error\nFailure reading the map, file name is invalid!\n", 52);
		exit(EXIT_FAILURE);
	}
	check_if_map_is_rectangular(map);
	map_is_surrounded_by_walls(map);
	search_exit(map);
	search_collectible(map);
	search_player(map);
	search_forbidden_character(map);
	only_one_player(map);
	only_one_exit(map);
	return (map);
}
