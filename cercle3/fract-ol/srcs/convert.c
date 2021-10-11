/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:31:55 by macbookpro        #+#    #+#             */
/*   Updated: 2021/10/11 16:35:23 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	rgb_to_hexa(t_color *color)
{
	color->hex = (color->r << 16 | color->g << 8 | color->b);
}

void	hexa_to_rgb(int hexa, t_color *color)
{
	color->hex = hexa;
	color->r = (hexa & 0xFF0000) >> 16;
	color->g = (hexa & 0x00FF00) >> 8;
	color->b = (hexa & 0x0000FF);
}
