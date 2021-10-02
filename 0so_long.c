/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0so_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:20:33 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/02 11:59:10 by guilmira         ###   ########.fr       */
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


void	put_walls(t_program *game, int **map, char *path_backround)
{
	t_data		*wall;

	wall = ft_newsprite(game, path_backround);


	int i = -1;
	int j = -1;
	while (++i < 10)
	{
		while (++j < 10)
		{
			if (map[i][j] == 1)
			{
				wall->coords.x = j * UNIT_HEIGHT;
				wall->coords.y = i * UNIT_WIDTH;
				push_image_towindow(game, wall, wall->coords);
			}
		}
		j = -1;
	}

}

int	**fix_map(t_vector dimensions)
{
	int	**map;

	map = ft_calloc(dimensions.y, sizeof(int *));
	if (!map)
		ft_shutdown();
	int j = -1;
	while (++j < dimensions.x)
	{
		map[j] = ft_calloc(dimensions.x, sizeof(int));
		if (!map[j])
			ft_shutdown();
	}

	int i = -1;
	j = -1;
	while (++i < dimensions.y)
	{
		while (++j < dimensions.x)
		{;
			map[i][j] = 0;
		}
		j = -1;
	}
 	map[1][7] = 1;
	map[1][4] = 1;
	map[1][5] = 1;
	map[1][6] = 1;
	map[5][9] = 1;
	return (map);
}

/* t_list	*read_map(void)
{
	int		fd;
	t_list	*list_map;
	char	*path_map = "./0images/map.ber";
	char	*line;

	fd = open(path_map, O_RDONLY);
	if (fd == -1)
		ft_shutdown();
	while (get_next_line(fd, &line))//si falla rl gnl poner condicion y hay que liberar
	{
		ft_lstadd_back(&list_map, ft_lstnew(line));
		printf("%s\n", list_map->content);
	}
	close(fd);
	return (list_map);

} */

/** PURPOSE : init 42minilibx, open window, and load an image.
 * 1. Define structure game (contains the lib and the window) and image.
 * 2. Define structure image (contains address of the image and parameters).
 * 3. Initialize both structures */
int main(void)
{
	t_program	*game;

	t_data	*sprite_witch;

	char	*path = "./0images/witch2.xpm";
	char	*path_backround = "./0images/forest_floor.xpm";
	char	*path_wall = "./0images/t2.xpm";
	t_vector	dimensions;
	t_vector	window_dimensions;
	dimensions.x = 24;
	dimensions.y = 12;
	int **map;
	map = fix_map(dimensions);


	game = ft_calloc(1,sizeof(*game));
	if (!game)
		ft_shutdown();
	window_dimensions = get_dimensions(dimensions);
	initalize(game, window_dimensions);
	put_background(game, dimensions, path_backround);
	put_walls(game, map, path_wall);

	sprite_witch = ft_newsprite(game, path);
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

