/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7booleans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:09:13 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/05 12:10:06 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** PURPOSE : gives wall coordinates in destination position. */
static t_vector	wall_position(t_vector element, int key)
{
	t_vector	wall;

	wall.y = element.y;
	wall.x = element.x;
	if (key == LEFT)
		wall.x = element.x - 1;
	else if (key == RIGHT)
		wall.x = element.x + 1;
	else if (key == UP)
		wall.y = element.y + 1;
	else if (key == DOWN)
		wall.y = element.y - 1;
	return (wall);
}

/** PURPOSE : checks whether there is a wall in destination position. */
t_bool	allow_movement(char **map2D, t_vector position, int key)
{
	t_vector	wall;

	wall = wall_position(position, key);
	if (map2D[wall.y][wall.x] == '1')
		return (0);
	else
		return (1);
}
