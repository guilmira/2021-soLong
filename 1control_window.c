/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1control_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:23:27 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/13 09:11:02 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** PURPOSE : from arry dimensions, obtain window pixel size. */
t_vector	get_window_dimensions(t_vector dimensions)
{
	t_vector	window_dimensions;

	window_dimensions.x = dimensions.x * UNIT_WIDTH;
	window_dimensions.y = dimensions.y * UNIT_HEIGHT;
	return (window_dimensions);
}

/** PURPOSE : closes program with output signal. */
static int	ft_exit(t_program *game)
{
	clean_exit(game);
	exit(0);
}

/** PURPOSE : open window.
 * 1. Open window, save pointer for later use.
 * 2. Establishes closing window hook */
void	init_window(t_program *game, t_vector window_dimensions)
{
	game->window = mlx_new_window(game->mlx_pointer, \
	window_dimensions.x, window_dimensions.y, WINDOW_NAME);
	if (!game->window)
		full_shutdown(game, 3);
	mlx_hook(game->window, 17, 0, ft_exit, game);
}
