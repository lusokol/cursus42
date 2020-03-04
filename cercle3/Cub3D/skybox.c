/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:22:48 by lusokol           #+#    #+#             */
/*   Updated: 2020/03/04 20:06:10 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_skybox(t_cub *all, int x)
{
	double	coeffx;
	double	coeffy;
	double	i = all->info.dirx;
	int		rot = 0;

	coeffx = (double)x / (double)all->res_x;
	coeffx = coeffx * (all->minilibx.skybox.w / 4);
	coeffy = (double)all->draw.ceilling / ((double)all->res_y / 2);
	//printf("coeffy : %f, skybox.h : %d\n", coeffy, all->minilibx.skybox.w);
	//printf("dirx : %f\n", all->info.dirx);
	coeffy = coeffy * (double)all->minilibx.skybox.h;

	//printf("planey * dirx: %f\n", (i + all->info.planey * all->info.dirx) / 2);
	//printf("atan(dirx/diry) = %f\n", ((atan(-all->info.dirx/all->info.diry)) / 2) * 360);

	//rot = all->minilibx.skybox.w - all->res_x;
	rot = all->minilibx.skybox.w;
//	if (all->info.diry > 0)
	i = (atan(all->info.dirx / -all->info.diry) / 2);
//	else
//		i = (atan(all->info.dirx / -all->info.diry) / 2);
	//i = i / 2;
	i += 0.7856;
	i = i / (2 * atan(1));
	//rot = rot * i;
	if (all->info.diry > 0)
	{
		i = (1 + i) / 2;
		i = 1 - i;
		rot = rot * i;
	}
	else
	{
		i = i / 2;
		i = 1 - i;
		rot = rot * i;
		//rot = (rot / 2) + (rot / 2) * (1 - i);
	}
	//rot -= all->res_x / 2;
	//if (rot + coeffx > all->minilibx.skybox.w)
	//	rot -= all->minilibx.skybox.w;
	//if (rot + coeffx < 0)
	//	rot += all->minilibx.skybox.w;
//	printf("rot : %d, i = %f\n", rot, i);

	return (all->minilibx.skybox.data[(int)(coeffx + rot + all->minilibx.skybox.w * (int)coeffy)]);
}
