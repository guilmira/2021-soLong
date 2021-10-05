/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0so_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:20:33 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/05 12:04:02 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



t_vector	wall_position(t_vector element, int key)
{
	t_vector	wall;

	wall.y = element.y;
	wall.x = element.x;
	if (key == LEFT)
		wall.x = element.x - 1;
	else if (key == RIGHT)
		wall.x = element.x + 1;
	else if (key == UP)
		wall.y = element.y + 1;
	else if (key == DOWN)
		wall.y = element.y - 1;
	return (wall);
}

t_bool	allow_movement(char **map2D, t_vector position, int key)
{
	t_vector	wall;

	wall = wall_position(position, key);
	if (map2D[wall.y][wall.x] == '1')
		return (0);
	else
		return (1);
}


/** PURPOSE : Give moevement to the sprite. */
void	put_sprite_dir(t_program *game, t_vector coords)
{
	t_vector	position;

	position.x = UNIT_WIDTH * coords.x;
	position.y = UNIT_HEIGHT * coords.y;
	push_image_towindow(game, game->db->sprite4, position);
}

void	execute_movement(t_program *game, t_vector position, int key)
{
	t_vector	offset;

	offset.x = 0;
	offset.y = 0;
	wash_floor(game, position);
	if (key == LEFT)
		offset.x--;
	else if (key == RIGHT)
		offset.x++;
	else if (key == UP)
		offset.y++;
	else if (key == DOWN)
		offset.y--;
	game->character_coords.y = position.y + offset.y;
	game->character_coords.x = position.x + offset.x;
	put_sprite_dir(game, game->character_coords);
}


/** PURPOSE : Separate movements.
 * 123 <<			124 >>
 * 125 vv			126 ^^ */
int	movement_character(int key, t_program *game)
{
	t_vector	position;

	position = game->character_coords;
	if (key == LEFT && allow_movement(game->map2D, position, LEFT))
		execute_movement(game, position, LEFT);
	else if (key == RIGHT && allow_movement(game->map2D, position, RIGHT))
		execute_movement(game, position, RIGHT);
	else if (key == UP && allow_movement(game->map2D, position, UP))
		execute_movement(game, position, UP);
	else if (key == DOWN && allow_movement(game->map2D, position, DOWN))
		execute_movement(game, position, DOWN);
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
	animation_init(game);

	mlx_key_hook(game->window, movement_character, game);

	mlx_loop_hook(game->mlx_pointer, next_frame, game); //carga las imagenes en la estructura y fuera. puedes probar a enviar dos argumentos CAMBIANDO el prototipo y pasar dos estructuras
	mlx_loop(game->mlx_pointer);
	//finish();
	return (0);
}


/* los strings (como un emnsaje de error que se pasa x argumento) hay que reservarles
memoria?? o quiza sea mejor meterlos con un define.  */
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

