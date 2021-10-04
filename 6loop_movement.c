/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6loop_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:59:31 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/04 16:08:16 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** PURPOSE : Give moevement to the sprite. */
void	put_sprite(t_program *game, t_vector coords)
{
	static int	frame;
	t_vector	position;
	t_vector	position_floor;

	position.x = UNIT_WIDTH * FACTOR_SPRITE * coords.x;
	position.y = UNIT_HEIGHT * coords.y;
	position_floor.x = UNIT_WIDTH * coords.x;
	position_floor.y = UNIT_HEIGHT * coords.y;
	if (frame == ANIMATION_FRAME || frame == ANIMATION_FRAME * 2 \
	|| frame == ANIMATION_FRAME * 3 || frame >= ANIMATION_FRAME * 4)
		push_image_towindow(game, game->floor, position_floor);
	if (frame == ANIMATION_FRAME)
		push_image_towindow(game, game->db->sprite1, position);
	else if (frame == ANIMATION_FRAME * 2)
		push_image_towindow(game, game->db->sprite2, position);
	else if (frame == ANIMATION_FRAME * 3)
		push_image_towindow(game, game->db->sprite3, position);
	else if (frame >= ANIMATION_FRAME * 4 || !frame)
	{
		push_image_towindow(game, game->db->sprite4, position);
		frame = 0;
	}
	frame++;
}

/** PURPOSE : Hook loop function. */
int	next_frame(t_program *game)
{
	t_vector	coords;
	coords.x = 1;
	coords.y = 1;

	put_sprite(game, coords);
	return (0);
}
