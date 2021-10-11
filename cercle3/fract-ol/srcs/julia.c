/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:55:31 by macbookpro        #+#    #+#             */
/*   Updated: 2021/10/11 16:16:54 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	init_julia(t_data *img, int *init)
{
	img->all->x1 = -1;
	img->all->x2 = 1;
	img->all->y1 = -1.2;
	img->all->y2 = 1.2;
	img->all->zoom_x = img->size / (img->all->x2 - img->all->x1);
	img->all->zoom_y = img->size / (img->all->y2 - img->all->y1);
	init[0] = 1;
}

void	julia(int x, int y, t_data *img)
{
	int		i;
	float	tmp;

	img->all->z_r = x / img->all->zoom_x + img->all->x1;
	img->all->z_i = y / img->all->zoom_y + img->all->y1;
	i = 0;
	tmp = 0;
	while (pow(img->all->z_r, 2) + pow(img->all->z_i, 2) < 4
		&& i < img->all->iteration_max)
	{
		tmp = img->all->z_r;
		img->all->z_r = pow(img->all->z_r, 2)
			- pow(img->all->z_i, 2) + img->all->c_r;
		img->all->z_i = 2 * img->all->z_i * tmp + img->all->c_i;
		i++;
	}
	if (i == img->all->iteration_max)
		my_mlx_pixelput(img, x, y, my_rgb(0, 0, 0));
	else
		my_mlx_pixelput(img, x, y, img->color[i % ((img->cs + 1) * 3)].hex);
}

void	julia_iteration(t_data *img)
{
	int			y;
	int			x;
	static int	init = 0;

	if (init == 0)
		init_julia(img, &init);
	x = 0;
	y = 0;
	img->all->zoom_x = img->size / (img->all->x2 - img->all->x1);
	img->all->zoom_y = img->size / (img->all->y2 - img->all->y1);
	while (x < img->size)
	{
		y = -1;
		while (++y < img->size)
			julia(x, y, img);
		x++;
	}	
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}
