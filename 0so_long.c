/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0so_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:20:33 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/03 14:44:06 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vector	dimensions;
t_data		*floor1;
t_data	*wall;
char **map;

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


	put_background(game, dimensions, floor1);
	put_walls(game, map, dimensions, wall);
	put_sprite(game, coords);
	return (0);
}

//El mapa deberá estar cerrado/rodeado de muros, en caso contrario el programa deberá devolver un error.
//El mapa debe tener al menos una salida, un coleccionable y una posición inicial.
//Un contador de movimiento directamente mostrado en pantalla en lugar de en el terminal.
//mostrar nombre de Morgana con letras chulas, movimientos y quiza una barra de vida.
//todo lo quej ahaggas es apra promocionar el juego.



/** PURPOSE : init 42minilibx, open window, and load an image.
 * 1. Define structure game (contains the lib and the window) and image.
 * 2. Define structure image (contains address of the image and parameters).
 * 3. Initialize both structures */
int main(void)
{
	t_program	*game;
	t_list		*list_map;
	t_data		*sprite_witch;


	t_vector	window_dimensions;


	map = NULL;

	list_map = read_map();
	dimensions = get_dimensions(list_map);
	map = fix_map(list_map, dimensions);
	window_dimensions = get_window_dimensions(dimensions);
	game = ft_calloc(1, sizeof(*game));
	if (!game)
		ft_shutdown();
	initalize(game, window_dimensions);



	sprite_witch = ft_newsprite(game, PATH_CHARACTER);
	sprite_witch = ft_newsprite(game, PATH_CHARACTER2);
	//push_image_towindow(game, sprite_witch, sprite_witch->coords);


	wall = ft_newsprite(game, PATH_WALL);
	floor1 = ft_newsprite(game, PATH_BACKGROUND);
	mlx_loop_hook(game->mlx_pointer, next_frame, game); //carga las imagenes en la estructura y fuera. puedes probar a enviar dos argumentos CAMBIANDO el prototipo y pasar dos estructuras
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

