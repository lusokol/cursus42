/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:39:47 by lusokol           #+#    #+#             */
/*   Updated: 2020/06/26 14:42:19 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calcul(t_cub *all, int x)
{
	all->info.camerax = (2 * (double)x / all->res_x) - 1;
	all->info.rayposx = all->coord.x;
	all->info.rayposy = all->coord.y;
	all->info.raydirx = all->info.dirx + (all->info.planex * all->info.camerax);
	all->info.raydiry = all->info.diry + (all->info.planey * all->info.camerax);
	all->info.mapx = (int)(all->info.rayposx);
	all->info.mapy = (int)(all->info.rayposy);
	all->info.deltadistx = sqrt(1 + ((all->info.raydiry * all->info.raydiry)
				/ (all->info.raydirx * all->info.raydirx)));
	all->info.deltadisty = sqrt(1 + ((all->info.raydirx * all->info.raydirx)
				/ (all->info.raydiry * all->info.raydiry)));
}

void	vecteur_dir(t_cub *all)
{
	if (all->info.raydirx < 0)
	{
		all->info.stepx = -1;
		all->info.sidedistx = (all->info.rayposx - all->info.mapx)
			* all->info.deltadistx;
	}
	else
	{
		all->info.stepx = 1;
		all->info.sidedistx = (all->info.mapx + 1.0 - all->info.rayposx)
			* all->info.deltadistx;
	}
	if (all->info.raydiry < 0)
	{
		all->info.stepy = -1;
		all->info.sidedisty = (all->info.rayposy - all->info.mapy)
			* all->info.deltadisty;
	}
	else
	{
		all->info.stepy = 1;
		all->info.sidedisty = (all->info.mapy + 1.0 - all->info.rayposy)
			* all->info.deltadisty;
	}
}

void	raycasting_next(t_cub *all)
{
	if (all->info.side == 0)
		all->info.perpwalldist = fabs(((all->info.mapx - all->info.rayposx)
					+ ((1 - all->info.stepx) / 2)) / all->info.raydirx);
	else
		all->info.perpwalldist = fabs(((all->info.mapy - all->info.rayposy)
					+ ((1 - all->info.stepy) / 2)) / all->info.raydiry);
}

void	raycasting(t_cub *all)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (all->info.sidedistx < all->info.sidedisty)
		{
			all->info.sidedistx += all->info.deltadistx;
			all->info.mapx += all->info.stepx;
			all->info.side = 0;
		}
		else
		{
			all->info.sidedisty += all->info.deltadisty;
			all->info.mapy += all->info.stepy;
			all->info.side = 1;
		}
		if ((all->map)[all->info.mapx][all->info.mapy] == '1')
			hit = 1;
	}
	raycasting_next(all);
}

void	calcul2(t_cub *all)
{
	all->draw.hauteurligne = abs((int)(all->res_y / all->info.perpwalldist));
	all->draw.drawstart = (int)(-(all->draw.hauteurligne) * (0.5 - all->coord.z)
			+ (int)(all->res_y * (0.5 + all->coord.z)));
	all->draw.drawend = (int)((all->draw.hauteurligne * (0.5 + all->coord.z))
			+ (int)(all->res_y * (0.5 + all->coord.z)));
	if (all->draw.drawstart < 0)
		all->draw.drawstart = 0;
	if (all->draw.drawend >= all->res_y)
		all->draw.drawend = all->res_y;
	all->draw.drawstart = abs(all->draw.drawstart);
	all->draw.drawend = abs(all->draw.drawend);
	all->draw.y = all->draw.drawstart;
	all->draw.ceilling = 0;
	all->draw.floor = all->draw.drawend;
}
