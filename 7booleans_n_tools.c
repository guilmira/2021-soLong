/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7booleans_n_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:09:13 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/13 14:51:15 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** PURPOSE : gives coordinates in destination position. */
static t_vector	destination_position(t_vector element, int key)
{
	t_vector	destination;

	destination.y = element.y;
	destination.x = element.x;
	if (key == LEFT)
		destination.x = element.x - 1;
	else if (key == RIGHT)
		destination.x = element.x + 1;
	else if (key == UP)
		destination.y = element.y - 1;
	else if (key == DOWN)
		destination.y = element.y + 1;
	return (destination);
}

/** PURPOSE : checks whether there is a wall in destination position. */
t_bool	allow_movement(t_program *game, t_vector position, int key)
{
	t_vector	destination;
	char		**map2D;

	map2D = game->map2D;
	destination = destination_position(position, key);
	if (map2D[destination.y][destination.x] == 'C')
	{
		map2D[destination.y][destination.x] = 0;
		game->total_collectables--;
	}
	if (map2D[destination.y][destination.x] == '1')
		return (0);
	if (map2D[destination.y][destination.x] == 'E')
	{
		if (game->total_collectables)
			return (0);
		else
		{
			clean_exit(game);
			exit(0);
		}
	}
	else
		return (1);
}

/** PURPOSE : print appropriate error message to guide user. */
void	print_error_message(int signal)
{
	if (signal == 1)
		ft_putstr_fd(EX1, 1);
	if (signal == 11)
		ft_putstr_fd(EX11, 1);
	if (signal == 2)
		ft_putstr_fd(EX2, 1);
	if (signal == 22)
		ft_putstr_fd(EX22, 1);
	if (signal == 3)
		ft_putstr_fd(EX3, 1);
	if (signal == 4)
		ft_putstr_fd(EX4, 1);
	if (signal == 5)
		ft_putstr_fd(EX5, 1);
	if (signal == 6)
		ft_putstr_fd(EX6, 1);
	if (signal == 7)
		ft_putstr_fd(EX7, 1);
}

/** PURPOSE : Destroy and free memory allocated for imgs. */
void	clear_images(t_program *game)
{
	t_data		*image;
	int			i;

	i = -1;
	while (++i < NUMBER_IMAGES)
	{
		image = game->static_images[i];
		if (image)
		{
			mlx_destroy_image(game->mlx_pointer, image->img);
			free(image);
		}
	}
}
