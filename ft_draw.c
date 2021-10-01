/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:15:29 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/01 10:44:42 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw(t_program *game, int x, int y, int color)
{
	t_data	*image;
	int		i;
	int		j;

	image = ft_calloc(1,sizeof(*image));
	if (!image)
		ft_shutdown();
	initalize_image(game, image);
	create_mold(image);
	i = x - 1000;
	while (++i < x)
	{
		j = y;
		while (++j < y + 10)
			put_pixel(image, x + i, y + j, color);
	}
	push_image_towindow(game, image);
}

void	ft_draw_up(t_program *game, int x, int y, int color)
{
	t_data	*image;
	int		i;
	int		j;

	image = ft_calloc(1, sizeof(*image));
	if (!image)
		ft_shutdown();
	initalize_image(game, image);
	create_mold(image);

	j = y - 1000;
	while (++j < y)
	{
		i = x;
		while (++i < x + 10)
			put_pixel(image, x + i, y + j, color);
	}
	push_image_towindow(game, image);
}
