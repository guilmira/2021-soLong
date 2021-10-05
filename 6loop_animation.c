/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6loop_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:59:31 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/05 12:22:02 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wash_floor(t_program *game, t_vector coords)
{
	t_vector	position_floor;

	position_floor.x = UNIT_WIDTH * coords.x;
	position_floor.y = UNIT_HEIGHT * coords.y;
	push_image_towindow(game, game->floor, position_floor);
}

/** PURPOSE : Give moevement to the sprite. */
void	put_sprite(t_program *game, t_vector coords)
{
	static int	frame;
	t_vector	position;

	position.x = UNIT_WIDTH * coords.x + (UNIT_WIDTH * FACTOR_SPRITE);
	//position.x = UNIT_WIDTH * coords.x;
	position.y = UNIT_HEIGHT * coords.y;
	if (frame == ANIMATION_FRAME || frame == ANIMATION_FRAME * 2 \
	|| frame == ANIMATION_FRAME * 3 || frame >= ANIMATION_FRAME * 4)
		wash_floor(game, coords);
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
	put_sprite(game, game->character_coords);
	return (0);
}
