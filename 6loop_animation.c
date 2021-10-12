/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6loop_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:59:31 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/12 12:58:18 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wash_floor(t_program *game, t_vector coords)
{
	t_vector	position_floor;

	position_floor.x = UNIT_WIDTH * coords.x;
	position_floor.y = UNIT_HEIGHT * coords.y;
	push_image_towindow(game, game->static_images[0], position_floor);
}

/** PURPOSE : Give moevement to the sprite. */
void	put_sprite(t_program *game, t_vector coords, t_data **animations)
{
	static int	frame;
	t_vector	position;

	position.x = UNIT_WIDTH * coords.x + (UNIT_WIDTH * FACTOR_SPRITE);
	position.y = UNIT_HEIGHT * coords.y;
	if (frame == ANIMATION_FRAME || frame == ANIMATION_FRAME * 2 \
	|| frame == ANIMATION_FRAME * 3 || frame >= ANIMATION_FRAME * 4)
		wash_floor(game, coords);
	if (frame == ANIMATION_FRAME)
		push_image_towindow(game, animations[0], position);
	else if (frame == ANIMATION_FRAME * 2)
		push_image_towindow(game, animations[1], position);
	else if (frame == ANIMATION_FRAME * 3)
		push_image_towindow(game, animations[2], position);
	else if (frame >= ANIMATION_FRAME * 4 || !frame)
	{
		push_image_towindow(game, animations[3], position);
		frame = 0;
	}
	frame++;
}

/** PURPOSE : Give moevement to the sprite. */
static void	put_sprite2(t_program *game, t_vector coords, t_data **animations)
{
	static int	frame;
	t_vector	position;

	position.x = UNIT_WIDTH * coords.x;
	position.y = UNIT_HEIGHT * coords.y + (FACTOR_CAULDRON * 0.1);
	if (frame == ANIMATION_FRAME2 || frame == ANIMATION_FRAME2 * 2 \
	|| frame == ANIMATION_FRAME2 * 3 || frame >= ANIMATION_FRAME2 * 4)
		wash_floor(game, coords);
	if (frame == ANIMATION_FRAME2)
		push_image_towindow(game, animations[0], position);
	else if (frame == ANIMATION_FRAME2 * 2)
		push_image_towindow(game, animations[1], position);
	else if (frame == ANIMATION_FRAME2 * 3)
		push_image_towindow(game, animations[2], position);
	else if (frame >= ANIMATION_FRAME2 * 4 || !frame)
	{
		push_image_towindow(game, animations[3], position);
		frame = 0;
	}
	frame++;
}

/** PURPOSE : Hook loop function. */
int	next_frame(t_program *game)
{
	put_sprite(game, game->character_coords, game->animations);
	put_sprite2(game, game->exit_coords, game->animations_exit);
	return (0);
}

/** PURPOSE : Obtain array-map coordinates of given element "z";
 * 1. Search array for argument character 'z'. */
t_vector	element_position(char **map, t_vector array_dimensions, char z)
{
	int			i;
	int			j;
	t_vector	element;

	i = -1;
	j = -1;
	element.y = i;
	element.x = j;
	while (++i < array_dimensions.y)
	{
		while (++j < array_dimensions.x)
		{
			if (map[i][j] == z)
			{
				element.y = i;
				element.x = j;
				return (element);
			}
		}
		j = -1;
	}
	return (element);
}
