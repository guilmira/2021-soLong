/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0init_structs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 09:19:00 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/07 13:30:48 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** PURPOSE : init image database and set pointers to NULL. */
/* static void	init_database(t_program *game)
{
	game->db->sprite1 = NULL;
	game->db->sprite2 = NULL;
	game->db->sprite3 = NULL;
	game->db->sprite4 = NULL;
} */

/** PURPOSE : init 42minilibx and set pointers to NULL.
 * 1. mlx_returns a pointer (void *). A lot of the library functions
 * need it in order to work.
 * 2. Inits the rest of the variables within the struct.
 * 3. Allocates memory for both mlx_pointer and sprite image database. */
void	init_game(t_program *game)
{
	game->mlx_pointer = mlx_init();
	if (!game->mlx_pointer)
		full_shutdown(game, EX1);
	game->window = NULL;
	game->array_dimensions.x = 0;
	game->array_dimensions.y = 0;
	game->character_coords.x = 0;
	game->character_coords.y = 0;
	game->map2D = NULL;


	game->static_images = NULL;
	game->animations = NULL;
	//game->db = NULL;
	/* game->db = ft_calloc(1, sizeof(t_imagedb));
	if(!game->db)
		full_shutdown(game, EX1); */
	//init_database(game);
}
