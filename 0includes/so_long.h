/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:21:07 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/13 09:53:17 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* LIBS */
# include <stdio.h>
# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
/* PATH TO MAP */
# define PATH_MAP "./1maps/map.ber"
/* ANIMATION SETTINGS */
# define ANIMATION_FRAME 1700
# define ANIMATION_FRAME2 4000
# define FACTOR_SPRITE 0.25
# define FACTOR_CAULDRON 0.1
/* NUMBER OF IMAGES WITHOUT MOVEMENT */
# define NUMBER_IMAGES 4
# define NUMBER_ANIMATIONS 4
# define NUMBER_ANIMATIONS1 4
/* PATH TO ANIMATIONS - Credits: 9EO 9e0.itch.io */
# define PATH_CHARACTER1 "./0images/0witch/1.xpm"
# define PATH_CHARACTER2 "./0images/0witch/2.xpm"
# define PATH_CHARACTER3 "./0images/0witch/3.xpm"
# define PATH_CHARACTER4 "./0images/0witch/4.xpm"
# define PATH_C1 "./0images/1cauldron/caul1.xpm"
# define PATH_C2 "./0images/1cauldron/caul2.xpm"
# define PATH_C3 "./0images/1cauldron/caul3.xpm"
# define PATH_C4 "./0images/1cauldron/caul4.xpm"
/* PATH TO IMAGES */
# define PATH_BACKGROUND "./0images/grass.xpm"
# define PATH_WALL "./0images/wall.xpm"
# define PATH_COLLECTABLE "./0images/potion.xpm"
/* WINDOW NAME */
# define WINDOW_NAME "Retro Aquelarre"
/* MAXIMUN WINDOW SIZE ALLOWED - Mac Screen: 2560 x 1440 */
# define MAX_HEIGHT 19
# define MAX_WIDTH 36
/* TILE DIMENSIONS */
# define UNIT_HEIGHT 70
# define UNIT_WIDTH 70
/* MOUSE KEYS AND MAP CHARACTERS */
# define LEFT 0
# define DOWN 1
# define RIGHT 2
# define UP 13
# define ESCAPE 53
# define CHARACTER 'P'
# define WALL '1'
# define COLLECTABLE 'C'
# define EXIT 'E'

/** PURPOSE : struct of a vector, 2D representation. */
typedef struct s_vector
{
	int	x;
	int	y;
}		t_vector;

/** PURPOSE : struct that stores image data. Coordinates is
 * necessary when working with sprites. */
typedef struct s_data
{
	void		*img;
	char		*addr;
	t_vector	coords;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

/** PURPOSE : struct that stores pointers of the mxl init and
 * the window init. Both pointers will be constantly refered to */
typedef struct s_program
{
	void		*mlx_pointer;
	void		*window;
	t_vector	array_dimensions;
	t_vector	character_coords;
	t_vector	exit_coords;
	char		**map2D;
	t_data		**static_images;
	t_data		**animations;
	t_data		**animations_exit;
	int			total_collectables;
}				t_program;

/* MAP PARSER */
t_vector	get_dimensions(t_list *list_map);
t_list		*read_map(void);
char		**fix_map(t_list *list_map, t_vector dimensions);
int			parser_map(char **map, t_vector dimensions);
int			check_items(char **map, t_vector dimensions, char z);
/* STRUCT INIT */
void		init_game(t_program *game);
void		init_window(t_program *game, t_vector window_dimensions);
/* WINDOW SIZE */
t_vector	get_window_dimensions(t_vector dimensions);
/* IMAGE TREATMENT */
void		initalize_image(t_program *game, t_data *image);
void		create_mold(t_data *image);
void		put_pixel(t_data *data, int x, int y, int color);
void		push_image_towindow(t_program *game, t_data *image, \
			t_vector coords);
/* CREATE SPRITES */
t_data		**load_images(t_program *game);
t_data		**load_animations(t_program *game);
t_data		**load_animations2(t_program *game);
/* PUT BACKGROUND */
void		put_layers(t_program *game);
int			get_collectables(char **map, t_vector dimensions);
/* LOOP SPRITE MOVEMENT */
void		put_sprite(t_program *game, t_vector coords, t_data **animations);
void		wash_floor(t_program *game, t_vector coords);
int			next_frame(t_program *game);
/* CLEAR MEMORY */
void		clean_exit(t_program *game);
void		full_shutdown(t_program *game, int signal);
void		print_error_message(int signal);
void		clear_images(t_program *game);
/* CHARACTER MOVEMENT */
t_bool		allow_movement(t_program *game, t_vector position, int key);
int			movement_character(int key, t_program *game);
t_vector	element_position(char **map, t_vector array_dimensions, char z);

/* ERROR MESSAGES */
# define EX		"Error.\n"
# define EX1	"No memory available for allocation.\n"
# define EX11	"No memory available for image allocation.\n"
# define EX2	"Reading file was unsuccessful. File must have content. \n"
# define EX3	"Could not generate new window.\n"
# define EX5	"Map contains invalid character. \
Only accepts '1', '0', 'P', 'C' and 'E'. \n"
# define EX4	"Incorrect shape of map. It must have the following specs: \n \
-> Must be a rectangle. \n \
-> Must not be empty. \n \
-> No more than 36 rows. \n \
-> No more than 19 lines. \n \
-> No empty lines, including at the end of file. \n"
# define EX6	"Map specifications not met. \n \
-> Must be surrounded by walls '1' \n \
-> Must contain at least one exit 'E' \n \
-> Must contain at least one collectable 'C' \n \
-> Must contain at least one character 'P'. \n"
# define EX7	"By developer choice, map specs only allow for: \n \
-> A single character 'P' \n \
-> A single exit 'E'.\n "

#endif
