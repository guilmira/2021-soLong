/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:21:07 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/08 11:40:38 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
/* PATH TO MAP */
# define PATH_MAP "./1maps/map3.ber"
/* ANIMATION SETTINGS */
# define ANIMATION_FRAME 1700
# define FACTOR_SPRITE 0.25
/* NUMBER OF IMAGES WITHOUT MOVEMENT */
# define NUMBER_IMAGES 4
# define NUMBER_ANIMATIONS 4
/* PATH TO ANIMATIONS */
# define PATH_CHARACTER1 "./0images/0witch/1.xpm"
# define PATH_CHARACTER2 "./0images/0witch/2.xpm"
# define PATH_CHARACTER3 "./0images/0witch/3.xpm"
# define PATH_CHARACTER4 "./0images/0witch/4.xpm"
/* PATH TO IMAGES */
# define PATH_BACKGROUND "./0images/grass.xpm"
# define PATH_WALL "./0images/wall.xpm"
# define PATH_COLLECTABLE "./0images/potion.xpm"
# define PATH_EXIT "./0images/red_potion.xpm"
/* ERROR MESSAGES */
# define EX		"Error.\n"
# define EX1	"No memory available for allocation.\n"
# define EX11	"No memory available for image allocation.\n"
# define EX2	"Reading file was unsuccessful. File must have content. \n"
# define EX3	"Could not generate new window.\n"
# define EX4	"Map specifications not met. It must be surrounded by walls '1' \
and it must have at least one exit 'E', one collectable 'C' \
and one character 'P'. \n"
# define EX5	"Incorrect shape of map, it must be a rectangle. \n"
# define EX6	"Rows and lines may not be empty and must not bigger than 36 and 19.\n"
/* WINDOW NAME */
# define WINDOW_NAME "Retro Aquelarre"
/* MAXIMUN WINDOW SIZE ALOWED - Mac Screen: 2560 x 1440 */
# define MAX_HEIGHT 19
# define MAX_WIDTH 36
/* TILE DIMENSIONS */
# define UNIT_HEIGHT 70
# define UNIT_WIDTH 70
/* MOUSE KEYS AND MAP CHARACTERS */
# define LEFT 123
# define RIGHT 124
# define UP 125
# define DOWN 126
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
typedef struct	s_data
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
typedef struct	s_program
{
	void		*mlx_pointer;
	void		*window;
	t_vector	array_dimensions;
	t_vector	character_coords;
	char		**map2D;
	t_data		**static_images;
	t_data		**animations;
}				t_program;

/* MAP PARSER */
t_vector	get_dimensions(t_list *list_map);
char		**fix_map(t_list *list_map, t_vector dimensions);
t_list		*read_map(void);
int	parser_map(char **map, t_vector dimensions);
/* STRUCT INIT */
void		init_game(t_program *game);
void		init_window(t_program *game, t_vector window_dimensions);
/* WINDOW SIZE */
t_vector	get_window_dimensions(t_vector dimensions);
/* IMAGE TREATMENT */
void		initalize_image(t_program *game, t_data *image);
void		create_mold(t_data *image);
void		put_pixel(t_data *data, int x, int y, int color);
void		push_image_towindow(t_program *game, t_data *image, t_vector coords);
/* CREATE SPRITES */
t_data	**load_images(t_program *game);
t_data	**load_animations(t_program *game);
t_vector	element_position(char **map, t_vector array_dimensions, char z);
/* PUT BACKGROUND */
void		put_layers(t_program *game);
/* LOOP SPRITE MOVEMENT */
void		put_sprite(t_program *game, t_vector coords);
void	wash_floor(t_program *game, t_vector coords);
int			next_frame(t_program *game);
/* CLEAR MEMORY */
void		clean_exit(t_program *game);
void		full_shutdown(t_program *game, char *string);
/* CHARACTER MOVEMENT */
t_bool	allow_movement(char **map2D, t_vector position, int key);
int	movement_character(int key, t_program *game);

/* RNDM DRAWING */
void		ft_draw(t_program *game, int x, int y, int color);
void		ft_draw_up(t_program *game, int x, int y, int color);
#endif
