/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4background.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 12:53:33 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/08 12:17:20 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** PURPOSE : Lay background layer by iterating through loop. */
static void	put_background(t_program *game, t_vector dimensions, t_data *floor)
{
	int			y;
	int			x;
	t_vector	coords;

	coords.y = 0;
	coords.x = 0;
	y = -1;
	x = -1;
	while (++y <= dimensions.y)
	{
		while (++x < dimensions.x)
		{
			coords.x = x * UNIT_WIDTH;
			push_image_towindow(game, floor, coords);
		}
		x = -1;
		coords.x = 0;
		coords.y = y * UNIT_HEIGHT;
	}
}

/** PURPOSE : Lay item layer by iterating through loop. */
static void	put_item(t_program *game, char **map, \
			char item, t_data *wall)
{
	int			i;
	int			j;
	t_vector	dimensions;

	dimensions = game->array_dimensions;
	i = -1;
	j = -1;
	while (++i < dimensions.y)
	{
		while (++j < dimensions.x)
		{
			if ((char) map[i][j] == item)
			{
				wall->coords.x = j * UNIT_HEIGHT;
				wall->coords.y = i * UNIT_WIDTH;
				push_image_towindow(game, wall, wall->coords);
			}
		}
		j = -1;
	}
}

/** PURPOSE : Lay 2 layers, the background and the walls. */
void	put_layers(t_program *game)
{
	t_data	*image;

	image = game->static_images[0];
	put_background(game, game->array_dimensions, image);
	image = game->static_images[1];
	put_item(game, game->map2D, WALL, image);
	image = game->static_images[2];
	put_item(game, game->map2D, COLLECTABLE, image);
}
