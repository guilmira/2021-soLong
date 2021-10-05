/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7hook_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:07:03 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/05 12:24:37 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** PURPOSE : Give movement to the sprite. */
static void	put_sprite_dir(t_program *game, t_vector coords)
{
	t_vector	position;

	//position.x = UNIT_WIDTH * coords.x;
	position.x = UNIT_WIDTH * coords.x + (UNIT_WIDTH * FACTOR_SPRITE);
	position.y = UNIT_HEIGHT * coords.y;
	push_image_towindow(game, game->db->sprite4, position);
}

/** PURPOSE : execute sprite movement by washing previous background
 * and drawing the spite in new tile. */
static void	execute_movement(t_program *game, t_vector position, int key)
{
	t_vector	offset;

	offset.x = 0;
	offset.y = 0;
	wash_floor(game, position);
	if (key == LEFT)
		offset.x--;
	else if (key == RIGHT)
		offset.x++;
	else if (key == UP)
		offset.y++;
	else if (key == DOWN)
		offset.y--;
	game->character_coords.y = position.y + offset.y;
	game->character_coords.x = position.x + offset.x;
	put_sprite_dir(game, game->character_coords);
}


/** PURPOSE : Separate movements.
 * 123 <<			124 >>
 * 125 vv			126 ^^ */
int	movement_character(int key, t_program *game)
{
	t_vector	position;

	position = game->character_coords;
	if (key == LEFT && allow_movement(game->map2D, position, LEFT))
		execute_movement(game, position, LEFT);
	else if (key == RIGHT && allow_movement(game->map2D, position, RIGHT))
		execute_movement(game, position, RIGHT);
	else if (key == UP && allow_movement(game->map2D, position, UP))
		execute_movement(game, position, UP);
	else if (key == DOWN && allow_movement(game->map2D, position, DOWN))
		execute_movement(game, position, DOWN);
	return (0);
}
