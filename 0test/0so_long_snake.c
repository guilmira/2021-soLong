/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0so_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:20:33 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/01 10:37:33 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int	ft_frame_right(t_program *game)
{
	static int i;

	i++;
	ft_draw(game, i, 500, 0x0000FF00);
	return (i);
}

int	ft_frame_up(t_program *game)
{
	static int j;

	j++;
	int t = 500;
	ft_draw_up(game, 500, t - j, 0x0000FF00);
	return (0);
}

int	move(int key, t_program	*game)
{
	static int	i;

	if (key == 124)
		i = mlx_loop_hook(game->mlx_pointer, ft_frame_right, game);
	else if (key == 126)
		mlx_loop_hook(game->mlx_pointer, ft_frame_up, game);
	return(0);
}

/** PURPOSE : init 42minilibx, open window, and load an image.
 * 1. Define structure game (contains the lib and the window) and image.
 * 2. Define structure image (contains address of the image and parameters).
 * 3. Initialize both structures */
int main(void)
{
	t_program	*game;
	t_data	*sprite_witch;
	char	*path = "./0images/witch.xpm";


	game = ft_calloc(1,sizeof(*game));
	if (!game)
		ft_shutdown();
	initalize(game);
	sprite_witch = ft_newsprite(game, path);
	mlx_key_hook(game->window, move, game);
	mlx_loop(game->mlx_pointer);
	return (0);
}




//for admin ONLY window
/* int ft_close ()
{
	exit(0);
}

t_window	ft_new_window(void *mlx, int widht, int height, char *name)
{
	t_window	window;


	window.reference = mlx_new_window(mlx, widht, height, name);
	window.size.x = widht;
	window.size.y = height;

	// Now we 'hook' the function ft_close() to the closing window event
	mlx_hook(window.reference, 17, 0, ft_close, 0);

	return (window);
} */
