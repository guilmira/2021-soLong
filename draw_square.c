/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:15:42 by guilmira          #+#    #+#             */
/*   Updated: 2021/09/30 10:12:46 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** PURPOSE : init 42minilibx and open window.
 * 1. mlx_returns a pointer (void *). A lot of the library functions
 * need it in order to work.
 * 2. Open window, save pointer for later use. */
static void	initalize(t_program *game)
{
	game->mlx_pointer = mlx_init();
	game->window = mlx_new_window(game->mlx_pointer,  HEIGHT, WIDTH, "ventana");
}

/** PURPOSE : init 42minilibx, open window, and load an image.
 * 1. Define structure game (contains the lib and the window) and image.
 * 2. Define structure image (contains address of the image and parameters).
 * 3. Initialize both structures */
int main(void)
{
	t_program	*game;
	t_data		*image;
	int			x;
	int			y;

	game = ft_calloc(1,sizeof(*game));
	if (!game)
		ft_shutdown();
	image = ft_calloc(1,sizeof(*image));
	if (!image)
		ft_shutdown();
	initalize(game);
	initalize_image(game, image);
	create_mold(image);

	x = 100;
	y = 100;
	while (x < 1000 && y < 1000)
	{
		put_pixel(image, x, y, 0x00FF0000);
		x++;
	}
	x = 100;
	y = 100;
	while (x < 1000 && y < 1000)
	{
		put_pixel(image, x, y, 0x00FF0000);
		y++;
	}
	x = 100;
	while (x < 1000)
	{
		put_pixel(image, x, y, 0x00FF0000);
		x++;
	}
	y = 100;
	while (y < 1000)
	{
		put_pixel(image, x, y, 0x00FF0000);
		put_pixel(image, x+1, y+1, 0x0000FF00);
		put_pixel(image, x+2, y+2, 0x000000FF);
		y++;
	}
	push_image_towindow(game, image);
	mlx_loop(game->mlx_pointer);
	return (0);
}
