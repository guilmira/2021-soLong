/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0so_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:20:33 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/13 19:55:17 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** PURPOSE : recieve argumens, build map2D and execute parser.
 * 1. Declare list and read file.ber.
 * 2. Get dimensions of map and built it into a 2D array.
 * 3. Clear list.
 * 4. Exceute parser of map. */
static void	parser_and_management(t_program *game)
{
	int		parser;
	t_list	*list_map;

	parser = 0;
	list_map = NULL;
	list_map = read_map(game->map_path);
	if (!list_map)
		full_shutdown(game, 22);
	game->array_dimensions = get_dimensions(list_map);
	game->map2D = fix_map(list_map, game->array_dimensions);
	ft_fullclear(list_map);
	parser = parser_map(game->map2D, game->array_dimensions);
	if (!(game->map2D))
		full_shutdown(game, 2);
	if (parser)
		full_shutdown(game, parser);
	game->total_collectables = get_collectables(game->map2D, \
	game->array_dimensions);
}

/** PURPOSE : load images, animations, and write both into screen. */
static void	images_and_layers(t_program *game)
{
	game->static_images = load_images(game);
	game->animations = load_animations(game);
	game->animations_exit = load_animations2(game);
	game->character_coords = element_position(game->map2D, \
	game->array_dimensions, CHARACTER);
	game->exit_coords = element_position(game->map2D, \
	game->array_dimensions, EXIT);
	put_layers(game);
}

/** PURPOSE : execute main routine of program */
static void	hooks_and_loops(t_program *game)
{
	mlx_key_hook(game->window, movement_character, game);
	mlx_loop_hook(game->mlx_pointer, next_frame, game);
	mlx_loop(game->mlx_pointer);
}

/** PURPOSE : evaluate single input to program and creat path to folder.
 * 1. File name must be ended in '.ber'.
 * 2. File name must not contain spaces. */
char	*parser_argument(int argc, char *file_name)
{
	int		i;
	char	*path;
	int		length;

	if (argc != 2)
	{
		ft_putstr_fd(EX, 1);
		print_error_message(2);
		ft_shutdown();
	}
	length = ft_strlen(file_name);
	i = -1;
	while (++i < length - 4)
		if (ft_isspaces(file_name[i]))
			return (NULL);
	if (file_name[i] != '.' || file_name[i + 1] != 'b' || \
	file_name[i + 2] != 'e' || file_name[i + 3] != 'r')
		return (NULL);
	path = ft_strjoin(FOLDER_PATH, file_name);
	if (!path)
		return (NULL);
	return (path);
}

/** PURPOSE : init 42minilibx, open window, and load an image.
 * 1. Define structure game (contains the lib and the window) and image.
 * 2. Define structure image (contains address of the image and parameters).
 * 3. Initialize both structures. */
int	main(int argc, char *argv[])
{
	t_program	*game;
	char		*map_path;

	game = ft_calloc(1, sizeof(*game));
	if (!game)
		full_shutdown(game, 1);
	map_path = NULL;
	game->map_path = parser_argument(argc, argv[1]);
	if (!game->map_path)
		full_shutdown(game, 2);
	init_game(game);
	parser_and_management(game);
	init_window(game, get_window_dimensions(game->array_dimensions));
	images_and_layers(game);
	hooks_and_loops(game);
	return (0);
}
