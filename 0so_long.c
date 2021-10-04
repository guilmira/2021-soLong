/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0so_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:20:33 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/04 11:32:28 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void	put_sprite(t_program *game, t_vector coords)
{
	t_data		*sprite1;
	//t_data		*sprite2;
	t_vector	position;
	static int	e;

	position.x = 50 * coords.x;
	position.y = 50 * coords.y;
	if (e % 2)
	{
		sprite1 = ft_newsprite(game, PATH_CHARACTER);
		push_image_towindow(game, sprite1, position);
	}
	else
	{
		sprite1 = ft_newsprite(game, PATH_CHARACTER);
		push_image_towindow(game, sprite1, position);
	}

	e++;

}

int	next_frame(t_program *game)
{
	//t_data		*floor;
	t_vector	coords;
	coords.x = 4;
	coords.y = 4;

	put_sprite(game, coords);
	return (0);
}

//El mapa deberá estar cerrado/rodeado de muros, en caso contrario el programa deberá devolver un error.
//El mapa debe tener al menos una salida, un coleccionable y una posición inicial.
//Un contador de movimiento directamente mostrado en pantalla en lugar de en el terminal.
//mostrar nombre de Morgana con letras chulas, movimientos y quiza una barra de vida.
//todo lo quej ahaggas es apra promocionar el juego.

void	put_floor_and_walls(t_program *game)
{
	t_data	*floor;
	t_data	*wall;

	floor = ft_newsprite(game, PATH_BACKGROUND);
	put_background(game, game->array_dimensions, floor);
	wall = ft_newsprite(game, PATH_WALL);
	put_walls(game, game->map2D, game->array_dimensions, wall);
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


	game = ft_calloc(1, sizeof(*game));
	if (!game)
		ft_shutdown();
	init_game(game);
	list_map = read_map();
	if (!list_map)
		full_shutdown(game);
	game->array_dimensions = get_dimensions(list_map);
	game->map2D = fix_map(list_map, game->array_dimensions);
	ft_fullclear(list_map); //quiza no reventar lista
	init_window(game, get_window_dimensions(game->array_dimensions));


	//push_image_towindow(game, sprite_witch, sprite_witch->coords);

	put_floor_and_walls(game);


	sprite_witch = ft_newsprite(game, PATH_CHARACTER);
	sprite_witch = ft_newsprite(game, PATH_CHARACTER2);
	//mlx_loop_hook(game->mlx_pointer, next_frame, game); //carga las imagenes en la estructura y fuera. puedes probar a enviar dos argumentos CAMBIANDO el prototipo y pasar dos estructuras
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

