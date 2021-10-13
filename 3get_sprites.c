/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3get_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:30:47 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/13 09:14:25 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** PURPOSE : load image form xpm file. Then get specs.
 * IMPORTANT!: Every variable passed by reference is an OUTPUT. */
static void	load_image_n_getdata(t_program *game, t_data *new_image, char *path)
{
	new_image->img = mlx_xpm_file_to_image(game->mlx_pointer, \
	path, &new_image->coords.x, &new_image->coords.y);
	new_image->addr = mlx_get_data_addr(new_image->img, \
	&new_image->bits_per_pixel, \
	&new_image->line_length, &new_image->endian);
}

/** PURPOSE : Handles creation of sprite.
 * All variables are handled with t_data pointer. */
static t_data	*ft_newsprite(t_program *game, char *path)
{
	t_data	*new_image;

	new_image = ft_calloc(1, sizeof(*new_image));
	if (!new_image)
		full_shutdown(game, 11);
	load_image_n_getdata(game, new_image, path);
	return (new_image);
}

/** PURPOSE : Load static images by searching path. */
t_data	**load_images(t_program *game)
{
	t_data	**static_images;
	int		i;

	i = -1;
	static_images = ft_calloc(NUMBER_IMAGES + 1, sizeof(t_data **));
	if (!static_images)
		return (NULL);
	static_images[0] = ft_newsprite(game, PATH_BACKGROUND);
	static_images[1] = ft_newsprite(game, PATH_WALL);
	static_images[2] = ft_newsprite(game, PATH_COLLECTABLE);
	static_images[3] = NULL;
	return (static_images);
}

/** PURPOSE : Load animations by searching path. */
t_data	**load_animations(t_program *game)
{
	t_data	**animations;
	int		i;

	i = -1;
	animations = ft_calloc(NUMBER_ANIMATIONS + 1, sizeof(t_data **));
	if (!animations)
		return (NULL);
	animations[0] = ft_newsprite(game, PATH_CHARACTER1);
	animations[1] = ft_newsprite(game, PATH_CHARACTER2);
	animations[2] = ft_newsprite(game, PATH_CHARACTER3);
	animations[3] = ft_newsprite(game, PATH_CHARACTER4);
	animations[4] = NULL;
	return (animations);
}

/** PURPOSE : Load animations by searching path. */
t_data	**load_animations2(t_program *game)
{
	t_data	**animations;
	int		i;

	i = -1;
	animations = ft_calloc(NUMBER_ANIMATIONS1 + 1, sizeof(t_data **));
	if (!animations)
		return (NULL);
	animations[0] = ft_newsprite(game, PATH_C1);
	animations[1] = ft_newsprite(game, PATH_C2);
	animations[2] = ft_newsprite(game, PATH_C3);
	animations[3] = ft_newsprite(game, PATH_C4);
	animations[4] = NULL;
	return (animations);
}
