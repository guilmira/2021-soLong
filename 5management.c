/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5management.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:40:52 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/12 11:31:31 by guilmira         ###   ########.fr       */
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
	if (game->static_images)
		free(game->static_images);
	if (game->animations)
		free(game->animations);
	if (game->animations_exit)
		free(game->animations_exit);
	free(game);
}

/** PURPOSE : Destroy and free memory allocated for imgs. */
static void	clear_images(t_program *game)
{
	t_data		*image;
	int			i;

	i = -1;
	while (++i < NUMBER_IMAGES)
	{
		image = game->static_images[i];
		if (image)
		{
			mlx_destroy_image(game->mlx_pointer, image->img);
			free(image);
		}
	}
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

/** PURPOSE : print appropriate error message to guide user. */
static void	print_error_message(int signal)
{
	if (signal == 1)
		ft_putstr_fd(EX1, 1);
	if (signal == 11)
		ft_putstr_fd(EX11, 1);
	if (signal == 2)
		ft_putstr_fd(EX2, 1);
	if (signal == 3)
		ft_putstr_fd(EX3, 1);
	if (signal == 4)
		ft_putstr_fd(EX4, 1);
	if (signal == 5)
		ft_putstr_fd(EX5, 1);
	if (signal == 6)
		ft_putstr_fd(EX6, 1);
	if (signal == 7)
		ft_putstr_fd(EX7, 1);
}

/** PURPOSE : shutdown program meanwhile freeing heap allocated memory.
 * 1. Close window if exists.
 * 2. Clean memory for all structs allocated.
 * 3. Print error message and exit program. */
void	full_shutdown(t_program *game, int signal)
{
	if (game->static_images && game->animations)
		clear_images(game);
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
	if (game->window)
		mlx_destroy_window(game->mlx_pointer, game->window);
	clean_memory(game);
	exit(0);
}
