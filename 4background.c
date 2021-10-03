/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4background.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 12:53:33 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/03 14:29:57 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_background(t_program *game, t_vector dimensions, t_data *floor)
{
	//t_data		*floor;
	t_vector	coords;
	int			y;
	int			x;

	coords.x = 0;
	coords.y = 0;
	//floor = ft_newsprite(game, PATH_BACKGROUND);
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

void	put_walls(t_program *game, char **map, t_vector dimensions, t_data *wall)
{
	//t_data		*wall;

	//wall = ft_newsprite(game, PATH_WALL);

	int i = -1;
	int j = -1;
	while (++i < dimensions.y)
	{

		while (++j < dimensions.x)
		{
			if ((char) map[i][j] == '1')
			{

				wall->coords.x = j * UNIT_HEIGHT;
				wall->coords.y = i * UNIT_WIDTH;
				push_image_towindow(game, wall, wall->coords);
			}
		}
		j = -1;
	}

}
