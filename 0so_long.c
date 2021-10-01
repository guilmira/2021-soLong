/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0so_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:20:33 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/01 15:09:03 by guilmira         ###   ########.fr       */
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

t_vector	get_dimensions(t_vector dimensions)
{
	t_vector	window_dimensions;
	//De los argumentos sacas DIMENSIONS.
	//char	map[unit_hight][unit_width];
	window_dimensions.x = dimensions.x * UNIT_WIDTH;
	window_dimensions.y = dimensions.y * UNIT_HEIGHT;
	return (window_dimensions);
}

/* int	next_frame(t_program *game)
{
	put_background(game, dimensions, path_backround);
} */




/** PURPOSE : init 42minilibx, open window, and load an image.
 * 1. Define structure game (contains the lib and the window) and image.
 * 2. Define structure image (contains address of the image and parameters).
 * 3. Initialize both structures */
int main(void)
{
	t_program	*game;

	t_data	*sprite_witch;
	t_data	*sprite_script;
	char	*path = "./0images/witch.xpm";
	char	*path2 = "./0images/red_potion.xpm";
	char	*path_backround = "./0images/forest_floor.xpm";

	t_vector	dimensions;
	t_vector	window_dimensions;
	dimensions.x = 30;
	dimensions.y = 20;

	game = ft_calloc(1,sizeof(*game));
	if (!game)
		ft_shutdown();
	window_dimensions = get_dimensions(dimensions);
	initalize(game, window_dimensions);
	put_background(game, dimensions, path_backround);

	sprite_witch = ft_newsprite(game, path);
	push_image_towindow(game, sprite_witch, sprite_witch->coords);

	sprite_script = ft_newsprite(game, path2);

	//mlx_loop_hook(game->mlx_pointer, next_frame, game);
	mlx_loop(game->mlx_pointer);
	//finish();
	return (0);
}

/* void	finish()
{
	¿ Se puede hace un if (game)
	free(game)?
	free(game);
	free(los t_data, sprites, floor)
} */

