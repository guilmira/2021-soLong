/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:06:45 by guilmira          #+#    #+#             */
/*   Updated: 2021/09/30 10:22:36 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** PURPOSE : Initialize the image with size 1920×1080 as follows: */
void	initalize_image(t_program *game, t_data *image)
{
	image->img = mlx_new_image(game->mlx_pointer,  HEIGHT, WIDTH);
}

/** PURPOSE : Creates a sort of mold of an image (or a pixel)
 * a memory adress is needed. Not only that, but also the data
 * related to the image, which will all be store in a struct.
 * --All arguments must be ponters.
 * 1. Img is the pointer of the previous initialized image.
 * 2. Bits per pixel, bpp. Color depth, is the number of bits used
 * to indicate the color of a single pixel
 * bits_per_pixel, line_length and endian variables passed by reference.
 * These will be set accordingly by MiniLibX */
void	create_mold(t_data *image)
{
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, &image->line_length,
								&image->endian);
}

/** PURPOSE : Creates single pixel with specs of DATA
 * at x - y, of a given colour.
 * The function will mimic the behaviour
 * of mlx_pixel_put but will simply be many times faster.
 * Offset calculation:
 * int offset = (y * img.line_length + x * (img.bits_per_pixel / 8)) */
void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/** PURPOSE : Pushes the full image, with all the bytes at once
 * to the window. Connects the full image with the window. */
void	push_image_towindow(t_program *game, t_data *image)
{
	mlx_put_image_to_window(game->mlx_pointer, game->window, image->img, 0, 0);
}
