/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1hooks_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:03:52 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/07 09:39:09 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//meter los free en los exit. tambien los close window y destryo images.

/** PURPOSE : closes program with output signal. */
static int	ft_exit(t_program *game)
{
	clean_memory(game);
	exit(0);
}

/** PURPOSE : closes window when ESC. */
static int	ft_esc_exit(int keycode, t_program *game)
{
	if (keycode == 53)
	{
		clean_memory(game);
		exit(0);
	}
	return (0);
}

/** PURPOSE : open window.
 * 1. Open window, save pointer for later use.
 * 2. Establishes closing window hook */
void	init_window(t_program *game, t_vector window_dimensions)
{
	game->window = mlx_new_window(game->mlx_pointer, \
	window_dimensions.x, window_dimensions.y, WINDOW_NAME);
	if (!game->window) //might need to free window later on. check manual..
		full_shutdown(game, EX3);
	mlx_key_hook(game->window, ft_esc_exit, game);
	mlx_hook(game->window, 17, 0, ft_exit, game);
}


