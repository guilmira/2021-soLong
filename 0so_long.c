/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0so_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:20:33 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/04 15:09:52 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void	put_sprite(t_program *game, t_vector coords)
{
	t_vector	position;
	static int	frame;
	t_data *sprite1 = game->database->sprite1;
	t_data *sprite2 = game->database->sprite2;
	t_data *sprite3 = game->database->sprite3;
	t_data *sprite4 = game->database->sprite4;

	position.x = 60 * coords.x;
	position.y = 60 * coords.y;

/* 	if (!frame)
	{
		push_image_towindow(game, game->floor, position);
		push_image_towindow(game, sprite2, position);
	} */
	//printf("hey\n");
	frame++;
	//push_image_towindow(game, sprite1, position);
	if (frame == ANIMATION_FRAME)
	{
		push_image_towindow(game, game->floor, position);
		push_image_towindow(game, sprite1, position);
	}
	else if (frame == ANIMATION_FRAME * 2)
	{

		push_image_towindow(game, game->floor, position);
		push_image_towindow(game, sprite2, position);
	}
	else if (frame == ANIMATION_FRAME * 3)
	{
		push_image_towindow(game, game->floor, position);
		push_image_towindow(game, sprite3, position);
	}
	else if (frame >= ANIMATION_FRAME * 4)
	{
		push_image_towindow(game, game->floor, position);
		push_image_towindow(game, sprite4, position);
		frame = 0;
	}
}

int	next_frame(t_program *game)
{
	t_vector	coords;
	coords.x = 4;
	coords.y = 4;

	put_sprite(game, coords);
	return (0);
}

/** PURPOSE : init 42minilibx, open window, and load an image.
 * 1. Define structure game (contains the lib and the window) and image.
 * 2. Define structure image (contains address of the image and parameters).
 * 3. Initialize both structures. */
int main(void)
{
	t_program	*game;
	t_list		*list_map;

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
	put_floor_and_walls(game);
	game->database = ft_calloc(game->number_images, sizeof(game->database));
	if(!game->database)
		full_shutdown(game);
	init_database(game);


	game->database->sprite1 = ft_newsprite(game, PATH_CHARACTER);
	game->database->sprite2 = ft_newsprite(game, PATH_CHARACTER2);
	game->database->sprite3 = ft_newsprite(game, PATH_CHARACTER3);
	game->database->sprite4 = ft_newsprite(game, PATH_CHARACTER4);

	mlx_loop_hook(game->mlx_pointer, next_frame, game); //carga las imagenes en la estructura y fuera. puedes probar a enviar dos argumentos CAMBIANDO el prototipo y pasar dos estructuras
	mlx_loop(game->mlx_pointer);
	//finish();
	return (0);
}


//El mapa deberá estar cerrado/rodeado de muros, en caso contrario el programa deberá devolver un error.
//El mapa debe tener al menos una salida, un coleccionable y una posición inicial.
//Un contador de movimiento directamente mostrado en pantalla en lugar de en el terminal.
//mostrar nombre de Morgana con letras chulas, movimientos y quiza una barra de vida.
//todo lo quej ahaggas es apra promocionar el juego.

/* void	finish()
{
	libera tambien memoria en los ft -shutdown
	free(game);
	free(los t_data, sprites, floor)
} */

