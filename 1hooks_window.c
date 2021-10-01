/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1hooks_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:03:52 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/01 14:39:13 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** PURPOSE : closes program with output signal. */
static int	ft_exit(int	output)
{
	exit(output);
}

/** PURPOSE : closes window when ESC. */
static int	ft_esc_exit(int	keycode, int i)
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

/** PURPOSE : init 42minilibx and open window.
 * 1. mlx_returns a pointer (void *). A lot of the library functions
 * need it in order to work.
 * 2. Open window, save pointer for later use.
 * 3. Establishes closing window hook */
void	initalize(t_program *game, t_vector window_dimensions)
{
	game->mlx_pointer = mlx_init();
	game->window = mlx_new_window(game->mlx_pointer, \
	window_dimensions.x, window_dimensions.y, "Aquelarre");
	if (!game->window || !game->mlx_pointer)
		ft_shutdown();
	mlx_key_hook(game->window, ft_esc_exit, 0);
	mlx_hook(game->window, 17, 0, ft_exit, 0);
	mlx_hook(game->window, 25, 0, ft_resize, 0);
}
