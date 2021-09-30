/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_keycode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 08:13:43 by guilmira          #+#    #+#             */
/*   Updated: 2021/09/30 08:39:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** PURPOSE : get keycodes by pressing key. */
int print_key(int keycode, int i)
{
	printf("%i\n", keycode);
	return(i);
}

/** PURPOSE : get mouse-info by pressing mouse. */
int print_mouse(int button, int x_position, int y_position, int i)
{
	printf("%i\n", button);
	printf("%i\n", x_position);
	printf("%i\n", y_position);
	return(i);
}

/** PURPOSE : closes window by pressing any key. */
/* int	ft_close(int keycode, t_program *game)
{
	mlx_destroy_window(game->mlx_pointer, game->window);
	return (keycode);
}
mlx_hook(game->window, 2, 1L<<0, ft_close, game); */

/** PURPOSE : init 42minilibx and open window.
 * 1. mlx_returns a pointer (void *). A lot of the library functions
 * need it in order to work.
 * 2. Open window, save pointer for later use.
 * 3. Establishes closing window hook */
static void	initalize(t_program *game)
{
	game->mlx_pointer = mlx_init();
	//game->window = mlx_new_window(game->mlx_pointer, HEIGHT, WIDTH, "ventana");
	game->window = mlx_new_window(game->mlx_pointer, 100, 100, "auxiliar");
	mlx_key_hook(game->window, print_key, 0);
	mlx_hook(game->window, 4, 0, print_mouse, 0);
}

/** PURPOSE : auxiliar main to get keycodes. */
int main(void)
{
	t_program	*game;

	game = ft_calloc(1, sizeof(*game));
	if (!game)
		ft_shutdown();
	initalize(game);
	mlx_loop(game->mlx_pointer);
	free(game); //vigilar los frees cuando exiteas antes de lo previsto.
	return (0);
}
