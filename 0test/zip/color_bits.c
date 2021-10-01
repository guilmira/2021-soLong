/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:01:25 by guilmira          #+#    #+#             */
/*   Updated: 2021/09/29 15:03:12 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** The term pixel is a truncation of the phrase “picture element”
 * which is exactly what a pixel is. A pixel is the smallest block
 * of color in a digital picture. The resolution of an image refers
 * to the number of pixels used to display an image. A higher
 * resolution image uses more pixels and allows for more detail
 * to be seen in the picture*/

/** PURPOSE : return a single int with info of the colour.
 * Each byte contains 2^8 values and RGB values range from 0 to 255,
 * We can perfectly fit a integer (as an int is 4 bytes).
 * In order to set the values programatically -> bitshifting
 * Example of use: get full color green, half red and a 1/25 transparent.
 * Create_trgb(10, 127, 255, 0)*/
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/** Because ints are stored from right to left,
 * we need to bitshift each value the according amount of bits backwards */

/** PURPOSE : do the exact opposite
 * and retrieve integer values from a encoded TRGB integer*/
int	get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int	get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int	get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}
