/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1control_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:23:27 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/02 14:23:48 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vector	get_window_dimensions(t_vector dimensions)
{
	t_vector	window_dimensions;
	//De los argumentos sacas DIMENSIONS.
	//char	map[unit_hight][unit_width];
	window_dimensions.x = dimensions.x * UNIT_WIDTH;
	window_dimensions.y = dimensions.y * UNIT_HEIGHT;
	return (window_dimensions);
}
