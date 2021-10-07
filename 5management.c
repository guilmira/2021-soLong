/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5management.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:40:52 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/07 10:12:47 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** PURPOSE : free 2D array located within in game structure. */
static void free_map(t_program *game)
{
	int	i;

	i = -1;
	while (++i < game->array_dimensions.y)
	{
		if (game->map2D[i])
			free(game->map2D[i]);
	}
	free(game->map2D);
}

/** PURPOSE : freeing structs used in the program.
 * For the function to properly work, all pointers have been initialized to NULL
 * at the beginning of the program.
 * 1. Free map 2D.
 * 2. Free database if it was allocated.
 * 3. Free game struct if previously allocated. */
static void	clean_memory(t_program *game)
{
	if (game->map2D)
		free_map(game);
	if (game->db)
		free(game->db);
	free(game);
}

/** PURPOSE : shutdown program meanwhile freeing heap allocated memory.
 * 1. Close window if exists.
 * 2. Clean memory for all structs allocated.
 * 3. Print error message and exit program. */
void	full_shutdown(t_program *game, char *string)
{
	if (game->window)
		mlx_destroy_window(game->mlx_pointer, game->window);
	clean_memory(game);
	ft_putstr_fd(EX, 1);
	ft_putstr_fd(string, 1);
	ft_shutdown();
}

/** PURPOSE : Neat program exit.
 * 1. Clean memory for all structs allocated.
 * 2. Exit program without output message. */
void	clean_exit(t_program *game)
{
	mlx_destroy_window(game->mlx_pointer, game->window);
	clean_memory(game);
	exit(0);
}
