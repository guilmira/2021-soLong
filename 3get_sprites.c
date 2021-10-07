/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3get_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:30:47 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/07 13:28:58 by guilmira         ###   ########.fr       */
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
t_data	*ft_newsprite(t_program *game, char *path)
{
	t_data	*new_image;

	new_image = ft_calloc(1, sizeof(*new_image));
	if (!new_image)
		full_shutdown(game, EX11);
	load_image_n_getdata(game, new_image, path);
	return (new_image);
}

/** PURPOSE : Obtain array-map coordinates of given element "z";
 * 1. Search array for argument character 'z'. */
t_vector	element_position(char **map, t_vector array_dimensions, char z)
{
	int			i;
	int			j;
	t_vector	element;

	i = -1;
	j = -1;
	element.y = i;
	element.x = j;
	while (++i < array_dimensions.y)
	{
		while (++j < array_dimensions.x)
		{
			if (map[i][j] == z)
			{
				element.y = i;
				element.x = j;
				return (element);
			}
		}
		j = -1;
	}
	return (element);
}

/** PURPOSE : Loads every animation of main sprite. */
/* void	animation_init(t_program *game)
{
	game->character_coords = element_position(game->map2D, game->array_dimensions, CHARACTER);
	game->db->sprite1 = ft_newsprite(game, PATH_CHARACTER);
	game->db->sprite2 = ft_newsprite(game, PATH_CHARACTER2);
	game->db->sprite3 = ft_newsprite(game, PATH_CHARACTER3);
	game->db->sprite4 = ft_newsprite(game, PATH_CHARACTER4);
} */
