/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0init_structs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 09:19:00 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/13 15:20:53 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** PURPOSE : init 42minilibx and set pointers to NULL.
 * 1. mlx_returns a pointer (void *). A lot of the library functions
 * need it in order to work.
 * 2. Inits the rest of the variables within the struct.
 * 3. Allocates memory for both mlx_pointer and sprite image database. */
void	init_game(t_program *game)
{


	game->mlx_pointer = mlx_init();
	if (!game->mlx_pointer)
		full_shutdown(game, 1);
	game->window = NULL;
	game->array_dimensions.x = 0;
	game->array_dimensions.y = 0;
	game->character_coords.x = 0;
	game->character_coords.y = 0;
	game->exit_coords.x = 0;
	game->exit_coords.y = 0;
	game->map2D = NULL;
	game->static_images = NULL;
	game->animations = NULL;
	game->animations_exit = NULL;
	game->total_collectables = 0;
}
