/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2map_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:16:10 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/12 13:43:09 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** PURPOSE : Check whether character or exit is duplicate. */
static int	check_duplicates(char **map, t_vector dimensions, char z)
{
	int	i;
	int	j;
	int	counter;

	i = -1;
	j = -1;
	counter = 0;
	while (++i < dimensions.y)
	{
		while (++j < dimensions.x)
		{
			if (map[i][j] == z)
				counter++;
		}
		j = -1;
	}
	if (counter == 1)
		return (0);
	else
		return (1);
}

/** PURPOSE : check if chat is equal to one of game items. */
static int	ft_is_item(char z)
{
	if (z == CHARACTER || z == EXIT || z == COLLECTABLE || \
	z == '1' || z == '0')
		return (1);
	else
		return (0);
}

/** PURPOSE : check if map is surrounded by walls. */
static int	ft_borders(char z, int i, int j, t_vector dimensions)
{
	if (i == 0 || i == dimensions.y - 1)
		if (z != '1')
			return (0);
	if (j == 0 || j == dimensions.x - 1)
		if (z != '1')
			return (0);
	return (1);
}

/** PURPOSE : Checks dimensions of map in the following order:
 * 1. Map is not bigger than given size.
 * 2. Map is not empty.
 * 3. Map has indeed the size of a rectangle. */
static int	parser_dimensions(t_vector dimensions, char *string)
{
	if (dimensions.y > MAX_HEIGHT || dimensions.x > MAX_WIDTH)
		return (1);
	if (dimensions.y == 0 || dimensions.x == 0)
		return (1);
	if ((int) ft_strlen(string) != dimensions.x)
		return (1);
	return (0);
}

/** PURPOSE : main parser. Checks the following
 * 1. Dimensions are not bigger than given size.
 * 2. Dimensions are not 0.
 * 3. Map is indeed a rectangle. No file has an altered size.
 * 4. Maps are surrounded by walls, i.e. '1'.
 * 5. At least one exit, character and collectible are present. */
int	parser_map(char **map, t_vector dimensions)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < dimensions.y)
	{
		if (parser_dimensions(dimensions, map[i]))
			return (4);
		while (++j < dimensions.x)
		{
			if (!ft_is_item(map[i][j]))
				return (5);
			if (!ft_borders(map[i][j], i, j, dimensions))
				return (6);
		}
		j = -1;
	}
	if (check_items(map, dimensions, CHARACTER) || check_items(map, \
	dimensions, EXIT) || check_items(map, dimensions, COLLECTABLE))
		return (6);
	if (check_duplicates(map, dimensions, CHARACTER) || \
	check_duplicates(map, dimensions, EXIT))
		return (7);
	return (0);
}
