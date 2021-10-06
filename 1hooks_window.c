/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1hooks_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:03:52 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/06 10:47:06 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//meter los free en los exit

/** PURPOSE : closes program with output signal. */
static int	ft_exit(int output)
{
	exit(output);
}

/** PURPOSE : closes window when ESC. */
static int	ft_esc_exit(int keycode, int i)
{
	if (keycode == 53)
		exit(i);
	return (i);
}

/** PURPOSE : Send message when resizeing */
static int	ft_resize(int i)
{
	printf("resizing...\n");
	return (i);
}

/** PURPOSE : open window.
 * 1. Open window, save pointer for later use.
 * 2. Establishes closing window hook */
void	init_window(t_program *game, t_vector window_dimensions)
{
	game->window = mlx_new_window(game->mlx_pointer, \
	window_dimensions.x, window_dimensions.y, WINDOW_NAME);
	/* if (!game->window) //might need to free MAP as well. Use return an int of -1 and ther full shutodwon.
		full_shutdown(game, EX3); */
	mlx_key_hook(game->window, ft_esc_exit, 0);
	mlx_hook(game->window, 17, 0, ft_exit, 0);
	mlx_hook(game->window, 25, 0, ft_resize, 0);
}


