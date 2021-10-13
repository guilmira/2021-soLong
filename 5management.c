/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5management.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:40:52 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/13 15:29:28 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** PURPOSE : free 2D array located within in game structure. */
static void	free_map(t_program *game)
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

/** PURPOSE : Destroy and free memory allocated for animations. */
static void	clear_animations(t_program *game)
{
	t_data		*image;
	int			i;

	i = -1;
	while (++i < (NUMBER_ANIMATIONS + NUMBER_ANIMATIONS1))
	{
		if (i < NUMBER_ANIMATIONS)
			image = game->animations[i];
		else
			image = game->animations_exit[i - NUMBER_ANIMATIONS];
		if (image)
		{
			mlx_destroy_image(game->mlx_pointer, image->img);
			free(image);
		}
	}
}

/** PURPOSE : freeing structs used in the program.
 * For the function to properly work, all pointers have been initialized to NULL
 * at the beginning of the program.
 * 1. Free map 2D.
 * 2. Free database if it was allocated.
 * 3. Free game struct if previously allocated. */
static void	clean_memory(t_program *game)
{
	if (game->map_path)
		free(game->map_path);
	if (game->map2D)
		free_map(game);
	if (game->static_images)
		free(game->static_images);
	if (game->animations)
		free(game->animations);
	if (game->animations_exit)
		free(game->animations_exit);
	free(game);
}

/** PURPOSE : shutdown program meanwhile freeing heap allocated memory.
 * 1. Close window if exists.
 * 2. Clean memory for all structs allocated.
 * 3. Print error message and exit program. */
void	full_shutdown(t_program *game, int signal)
{
	if (!game)
	{
		print_error_message(signal);
		ft_shutdown();
	}
	if (game->static_images)
		clear_images(game);
	if (game->animations)
		clear_animations(game);
	if (game->window)
		mlx_destroy_window(game->mlx_pointer, game->window);
	clean_memory(game);
	ft_putstr_fd(EX, 1);
	print_error_message(signal);
	ft_shutdown();
}

/** PURPOSE : Neat program exit.
 * 1. Close window if exists.
 * 2. Clean memory for all structs allocated.
 * 3. Exit program without output message. */
void	clean_exit(t_program *game)
{
	clear_images(game);
	clear_animations(game);
	if (game->window)
		mlx_destroy_window(game->mlx_pointer, game->window);
	clean_memory(game);
	exit(0);
}
