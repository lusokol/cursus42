/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:01:56 by macbookpro        #+#    #+#             */
/*   Updated: 2021/10/11 16:22:22 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	init_burningship(t_data *img, int *init)
{
	img->all->x1 = -2;
	img->all->x2 = 1;
	img->all->y1 = -2;
	img->all->y2 = 1;
	init[0] = 1;
}

void	burningship(int x, int y, t_data *img)
{
	int		i;
	float	tmp;

	img->all->c_r = x / img->all->zoom_x + img->all->x1;
	img->all->c_i = y / img->all->zoom_y + img->all->y1;
	img->all->z_r = 0;
	img->all->z_i = 0;
	i = 0;
	tmp = 0;
	while (pow(img->all->z_r, 2) + pow(img->all->z_i, 2) < 4
		&& i < img->all->iteration_max)
	{
		tmp = img->all->z_r;
		img->all->z_r = pow(img->all->z_r, 2)
			- pow(img->all->z_i, 2) + img->all->c_r;
		img->all->z_i = fabsl(2 * tmp * img->all->z_i) + img->all->c_i;
		i++;
	}
	if (i == img->all->iteration_max)
		my_mlx_pixelput(img, x, y, my_rgb(0, 0, 0));
	else
		my_mlx_pixelput(img, x, y, img->color[i % ((img->cs + 1) * 3)].hex);
}

void	burningship_iteration(t_data *img)
{
	int			y;
	int			x;
	static int	init = 0;

	if (init == 0)
		init_burningship(img, &init);
	x = 0;
	y = 0;
	img->all->zoom_x = img->size / (img->all->x2 - img->all->x1);
	img->all->zoom_y = img->size / (img->all->y2 - img->all->y1);
	while (x < img->size)
	{
		y = -1;
		while (++y < img->size)
			burningship(x, y, img);
		x++;
	}	
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}
