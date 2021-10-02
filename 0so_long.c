/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0so_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:20:33 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/02 14:24:01 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_background(t_program *game, t_vector dimensions,char *path_backround)
{
	t_data		*floor;
	t_vector	coords;
	int			y;
	int			x;

	coords.x = 0;
	coords.y = 0;
	floor = ft_newsprite(game, path_backround);
	y = -1;
	x = -1;
	while (++y <= dimensions.y)
	{

		while (++x < dimensions.x)
		{
			coords.x = x * UNIT_WIDTH;
			push_image_towindow(game, floor, coords);
		}
		x = -1;
		coords.x = 0;
		coords.y = y * UNIT_HEIGHT;
	}
}

/* int	next_frame(t_program *game)
{
	put_background(game, dimensions, path_backround);
} */

void	put_walls(t_program *game, char **map, t_vector dimensions)
{
	t_data		*wall;

	wall = ft_newsprite(game, PATH_WALL);

	int i = -1;
	int j = -1;
	while (++i < dimensions.y)
	{

		while (++j < dimensions.x)
		{
			if ((char) map[i][j] == '1')
			{

				wall->coords.x = j * UNIT_HEIGHT;
				wall->coords.y = i * UNIT_WIDTH;
				push_image_towindow(game, wall, wall->coords);
			}
		}
		j = -1;
	}

}

/** PURPOSE : init 42minilibx, open window, and load an image.
 * 1. Define structure game (contains the lib and the window) and image.
 * 2. Define structure image (contains address of the image and parameters).
 * 3. Initialize both structures */
int main(void)
{
	t_program	*game;
	t_list		*list_map;
	t_data		*sprite_witch;

	t_vector	dimensions;
	t_vector	window_dimensions;


	char **map = NULL;

	list_map = read_map();
	dimensions = get_dimensions(list_map);
	printf("%i y %i \n", dimensions.y, dimensions.x);
	map = fix_map(list_map, dimensions);
	window_dimensions = get_window_dimensions(dimensions);
	game = ft_calloc(1, sizeof(*game));
	if (!game)
		ft_shutdown();
	initalize(game, window_dimensions);

	put_background(game, dimensions, PATH_BACKGROUND);
	put_walls(game, map, dimensions);

	sprite_witch = ft_newsprite(game, PATH_CHARACTER);
	//push_image_towindow(game, sprite_witch, sprite_witch->coords);




	//mlx_loop_hook(game->mlx_pointer, next_frame, game);
	mlx_loop(game->mlx_pointer);
	//finish();
	return (0);
}

/* void	finish()
{
	libera tambien memoria en los ft -shutdown
	¿ Se puede hace un if (game)
	free(game)?
	free(game);
	free(los t_data, sprites, floor)
} */

