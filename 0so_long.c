/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0so_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:20:33 by guilmira          #+#    #+#             */
/*   Updated: 2021/09/30 13:27:02 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** PURPOSE : closes program with output signal. */
int	ft_exit(int	output)
{
	exit(output);
}

int	ft_esc_exit(int	keycode, int i)
{
	if (keycode == 53)
		exit(i);
	return (i);
}

int	ft_resize(int i)
{
	printf("resizing...\n");
	return (i);
}

/** PURPOSE : init 42minilibx and open window.
 * 1. mlx_returns a pointer (void *). A lot of the library functions
 * need it in order to work.
 * 2. Open window, save pointer for later use.
 * 3. Establishes closing window hook */
static void	initalize(t_program *game)
{
	game->mlx_pointer = mlx_init();
	game->window = mlx_new_window(game->mlx_pointer, HEIGHT, WIDTH, "ventana");
	if (!game->window || !game->mlx_pointer)
		ft_shutdown();
	mlx_key_hook(game->window, ft_esc_exit, 0);
	mlx_hook(game->window, 17, 0, ft_exit, 0);
	mlx_hook(game->window, 25, 0, ft_resize, 0);

	//mlx_key_hook(game->window, ft_esc_exit, 0);
}

int	ft_frame_right(t_program *game)
{
	static int i;

	i++;
	ft_draw(game, i, 500, 0x0000FF00);
	return (i);
}

int	ft_frame_up(t_program *game)
{
	static int j;

	j++;
	int t = 500;
	ft_draw_up(game, 500, t - j, 0x0000FF00);
	return (0);
}

int	move(int key, t_program	*game)
{
	static int	i;

	if (key == 124)
		i = mlx_loop_hook(game->mlx_pointer, ft_frame_right, game);
	else if (key == 126)
		mlx_loop_hook(game->mlx_pointer, ft_frame_up, game);
	return(0);
}

t_data	*ft_newsprite(t_program *game, char *path)
{
	t_data	*new_image;
	int		img_width = 50;
	int		img_height = 50;

	new_image = ft_calloc(1, sizeof(*new_image));
	if (!new_image)
		ft_shutdown();
	new_image->img = mlx_xpm_file_to_image(game->mlx_pointer, path, &img_width, &img_height);
	push_image_towindow(game, new_image);
	return (new_image);
}

/** PURPOSE : init 42minilibx, open window, and load an image.
 * 1. Define structure game (contains the lib and the window) and image.
 * 2. Define structure image (contains address of the image and parameters).
 * 3. Initialize both structures */
int main(void)
{
	t_program	*game;
	t_data	*sprite_witch;
	char	*path = "./witch.xpm";


	game = ft_calloc(1,sizeof(*game));
	if (!game)
		ft_shutdown();
	initalize(game);
	sprite_witch = ft_newsprite(game, path);
	//eliminar fondo de imagen. emepzar x esta pero dejar el resto para el final
	//para cuando montes el programa bien.

	mlx_key_hook(game->window, move, game);


	mlx_loop(game->mlx_pointer);
	return (0);
}




//for admin ONLY window
/* int ft_close ()
{
	exit(0);
}

t_window	ft_new_window(void *mlx, int widht, int height, char *name)
{
	t_window	window;


	window.reference = mlx_new_window(mlx, widht, height, name);
	window.size.x = widht;
	window.size.y = height;

	// Now we 'hook' the function ft_close() to the closing window event
	mlx_hook(window.reference, 17, 0, ft_close, 0);

	return (window);
} */
