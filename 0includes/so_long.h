/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:21:07 by guilmira          #+#    #+#             */
/*   Updated: 2021/09/30 12:07:02 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "mlx.h"
# include "libft.h"
# define HEIGHT 1920
# define WIDTH 1080

/** PURPOSE : struct that stores pointers of the mxl init and
 * the window init. Both pointers will be constantly refered to */
typedef struct s_program
{
	void	*mlx_pointer;
	void	*window;
}			t_program;

/** PURPOSE : struct that stores image data. */
typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

/* IMAGE TREATMENT */
void	initalize_image(t_program *game, t_data *image);
void	create_mold(t_data *image);
void	put_pixel(t_data *data, int x, int y, int color);
void	push_image_towindow(t_program *game, t_data *image);


void	ft_draw(t_program *game, int x, int y, int color);
void	ft_draw_up(t_program *game, int x, int y, int color);
#endif
