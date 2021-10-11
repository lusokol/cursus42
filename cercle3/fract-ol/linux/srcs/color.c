/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:39:18 by macbookpro        #+#    #+#             */
/*   Updated: 2021/10/11 17:19:27 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	init_color(t_data *img)
{
	if (img->fractal == 1)
	{
		img->c1 = COLOR1;
		img->c2 = COLOR2;
		img->c3 = COLOR3;
		img->cs = SIZE1;
	}
	else if (img->fractal == 2)
	{
		img->c1 = COLOR4;
		img->c2 = COLOR5;
		img->c3 = COLOR6;
		img->cs = SIZE2;
	}
	else if (img->fractal == 3)
	{
		img->c1 = COLOR7;
		img->c2 = COLOR8;
		img->c3 = COLOR9;
		img->cs = SIZE3;
	}
}

void	rgb_tmp(t_data *img)
{
	static int	i = 0;
	int			tmp1;
	int			tmp2;

	if (i == 0)
	{
		tmp1 = 0;
		tmp2 = img->cs + 1;
	}
	if (i == 1)
	{
		tmp1 = img->cs + 1;
		tmp2 = (img->cs + 1) * 2;
	}
	if (i == 2)
	{
		tmp1 = (img->cs + 1) * 2;
		tmp2 = 0;
	}
	img->tmp.r = (img->color[tmp1].r - img->color[tmp2].r) / (img->cs + 1);
	img->tmp.g = (img->color[tmp1].g - img->color[tmp2].g) / (img->cs + 1);
	img->tmp.b = (img->color[tmp1].b - img->color[tmp2].b) / (img->cs + 1);
	i++;
}

void	rgb_tmp2(t_data *img, int i, int j)
{
	int			tmp1;
	int			tmp2;

	if (i == 0)
	{
		tmp1 = 0;
		tmp2 = j;
	}
	if (i == 1)
	{
		tmp1 = img->cs + 1;
		tmp2 = j - (img->cs + 1);
	}
	if (i == 2)
	{
		tmp1 = (img->cs + 1) * 2;
		tmp2 = j - ((img->cs * 2) + 1);
	}
	img->color[j].r = img->color[tmp1].r - img->tmp.r * tmp2;
	img->color[j].g = img->color[tmp1].g - img->tmp.g * tmp2;
	img->color[j].b = img->color[tmp1].b - img->tmp.b * tmp2;
	i++;
	rgb_to_hexa(&img->color[j]);
}

void	create_gradient(t_data *img)
{
	int	i;
	int	j;

	init_color(img);
	i = img->cs * 3 + 3;
	img->color = malloc(sizeof(t_color) * i + 1);
	if (!(img->color))
		ft_exit(0, img);
	img->color[0].size = i;
	hexa_to_rgb(img->c1, &img->color[0]);
	hexa_to_rgb(img->c2, &img->color[img->cs + 1]);
	hexa_to_rgb(img->c3, &img->color[(img->cs + 1) * 2]);
	rgb_tmp(img);
	j = 1;
	while (j < img->cs + 1)
		rgb_tmp2(img, 0, j++);
	rgb_tmp(img);
	j = img->cs + 2;
	while (j < (img->cs + 1) * 2)
		rgb_tmp2(img, 1, j++);
	rgb_tmp(img);
	j = (img->cs + 1) * 2 + 1;
	while (j < (img->cs + 1) * 3)
		rgb_tmp2(img, 2, j++);
}
