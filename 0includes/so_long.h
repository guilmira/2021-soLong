/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:21:07 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/07 10:16:53 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# define UNIT_HEIGHT 70
# define UNIT_WIDTH 70
# define FACTOR_SPRITE 0.25
# define WINDOW_NAME "Aquelarre"
# define ANIMATION_FRAME 2000
# define LEFT 123
# define RIGHT 124
# define UP 125
# define DOWN 126
# define CHARACTER 'P'

/* PATH TO MAP */
# define PATH_MAP "./1maps/map2.ber"
/* PATH TO IMAGES */
# define PATH_CHARACTER "./0images/0witch/1.xpm"
# define PATH_CHARACTER2 "./0images/0witch/2.xpm"
# define PATH_CHARACTER3 "./0images/0witch/3.xpm"
# define PATH_CHARACTER4 "./0images/0witch/4.xpm"
# define PATH_BACKGROUND "./0images/grass.xpm"
# define PATH_WALL "./0images/wall.xpm"
/* ERROR MESSAGES */
# define EX		"Error.\n"
# define EX1	"No memory available for allocation.\n"
# define EX2	"Reading file was unsuccessful. File must have content. \n"
# define EX3	"Could not generate new window.\n"

//1920, 1080
//2560, 1440 mac screen
//36 de largo
//70 x 70

/** PURPOSE : struct of a vector, 2D representation. */
typedef struct s_vector
{
	int	x;
	int	y;
}		t_vector;

/** PURPOSE : struct that stores image data. */
typedef struct	s_data
{
	void		*img;
	char		*addr;
	t_vector	coords;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_databaseimages
{
	t_data		*sprite1;
	t_data		*sprite2;
	t_data		*sprite3;
	t_data		*sprite4;
}				t_imagedb;

/** PURPOSE : struct that stores pointers of the mxl init and
 * the window init. Both pointers will be constantly refered to */
typedef struct	s_program
{
	void		*mlx_pointer;
	void		*window;
	t_vector	array_dimensions;
	t_vector	character_coords;
	char		**map2D;
	t_data		*floor;
	t_data		*wall;
	t_data		*collectible;
	t_imagedb	*db;
}				t_program;


/* MAP PARSER */
t_vector	get_dimensions(t_list *list_map);
char		**fix_map(t_list *list_map, t_vector dimensions);
t_list		*read_map(void);
/* STRUCT INIT */
void		init_game(t_program *game);
/* WINDOW CONTROL INIT AND HOOKS */
void		init_window(t_program *game, t_vector window_dimensions);
/* WINDOW SIZE */
t_vector	get_window_dimensions(t_vector dimensions);
/* IMAGE TREATMENT */
void		initalize_image(t_program *game, t_data *image);
void		create_mold(t_data *image);
void		put_pixel(t_data *data, int x, int y, int color);
void		push_image_towindow(t_program *game, t_data *image, t_vector coords);
/* CREATE SPRITES */
t_data		*ft_newsprite(t_program *game, char *path);
void	animation_init(t_program *game);
t_vector	element_position(char **map, t_vector array_dimensions, char z);
/* PUT BACKGROUND */
void		put_floor_and_walls(t_program *game);
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
