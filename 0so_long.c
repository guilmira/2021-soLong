/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0so_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:20:33 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/07 13:06:22 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leaks(void)
{
	system("leaks so_long");
}

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
	//static_images[2] = ft_newsprite(game, PATH_COLLECT);
	static_images[3] = NULL;
	return (static_images);
}

/** PURPOSE : init 42minilibx, open window, and load an image.
 * 1. Define structure game (contains the lib and the window) and image.
 * 2. Define structure image (contains address of the image and parameters).
 * 3. Initialize both structures. */
int main(void)
{
	t_program	*game;
	t_list		*list_map;

	//atexit(leaks);
	list_map = NULL;
	game = ft_calloc(1, sizeof(*game));
	if (!game)
		ft_shutdown();
	init_game(game);
	list_map = read_map();
	//list_map = NULL;
	if (!list_map)
		full_shutdown(game, EX2);
	game->array_dimensions = get_dimensions(list_map);
	game->map2D = fix_map(list_map, game->array_dimensions);
	ft_fullclear(list_map);
	if (!(game->map2D))
		full_shutdown(game, EX2);
	init_window(game, get_window_dimensions(game->array_dimensions));
	game->static_images = load_images(game);
	put_floor_and_walls(game);
	animation_init(game);
	mlx_key_hook(game->window, movement_character, game);
	mlx_loop_hook(game->mlx_pointer, next_frame, game);
	mlx_loop(game->mlx_pointer);
	return (0);
}

/* los strings (como un emnsaje de error que se pasa x argumento) hay que reservarles
memoria?? o quiza sea mejor meterlos con un define.  */
//El mapa deberá estar cerrado/rodeado de muros, en caso contrario el programa deberá devolver un error.
//El mapa debe tener al menos una salida, un coleccionable y una posición inicial.
//Un contador de movimiento directamente mostrado en pantalla en lugar de en el terminal.
//mostrar nombre de Morgana con letras chulas, movimientos y quiza una barra de vida.
//todo lo quej ahaggas es apra promocionar el juego.


