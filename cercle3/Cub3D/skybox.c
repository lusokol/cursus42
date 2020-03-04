/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:22:48 by lusokol           #+#    #+#             */
/*   Updated: 2020/03/04 20:24:23 by lusokol          ###   ########.fr       */
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
	coeffy = (double)all->draw.ceilling / ((double)all->res_y * 0.75);
	coeffy = coeffy * (double)all->minilibx.skybox.h;

	rot = all->minilibx.skybox.w;
	i = (atan(all->info.dirx / -all->info.diry) / 2);
	i += 0.7856;
	i = i / (2 * atan(1));
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
	}

	return (all->minilibx.skybox.data[(int)(coeffx + rot + all->minilibx.skybox.w * (int)coeffy)]);
}
