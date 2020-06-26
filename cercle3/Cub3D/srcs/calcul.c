/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 15:38:57 by lusokol           #+#    #+#             */
/*   Updated: 2020/06/26 15:46:58 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_calcfloor_next(t_cub *all)
{
	if (all->info.side == 1)
		all->floceil.wallx = all->info.rayposx + ((all->info.mapy -
					all->info.rayposy + (1 - all->info.stepy) * (0.5))
				/ all->info.raydiry) * all->info.raydirx;
	else
		all->floceil.wallx = all->info.rayposy + ((all->info.mapx -
					all->info.rayposx + (1 - all->info.stepx) * (0.5))
				/ all->info.raydirx) * all->info.raydiry;
	all->floceil.wallx -= floor(all->floceil.wallx);
}

void	ft_calcfloor(t_cub *all)
{
	ft_calcfloor_next(all);
	if (all->info.side == 0 && all->info.raydirx > 0)
	{
		all->floceil.floorxwall = all->info.mapx;
		all->floceil.floorywall = all->info.mapy + all->floceil.wallx;
	}
	else if (all->info.side == 0 && all->info.raydirx < 0)
	{
		all->floceil.floorxwall = all->info.mapx + 1.0;
		all->floceil.floorywall = all->info.mapy + all->floceil.wallx;
	}
	else if (all->info.side == 1 && all->info.raydiry > 0)
	{
		all->floceil.floorxwall = all->info.mapx + all->floceil.wallx;
		all->floceil.floorywall = all->info.mapy;
	}
	else
	{
		all->floceil.floorxwall = all->info.mapx + all->floceil.wallx;
		all->floceil.floorywall = all->info.mapy + 1.0;
	}
}

int		ft_texture(t_cub *all)
{
	if (all->info.side == 1)
	{
		if (all->info.raydiry < 0)
			return (ft_color_texture(all, all->minilibx.west.data,
						&all->minilibx.west, 0));
		else if (all->info.raydiry > 0)
			return (ft_color_texture(all, all->minilibx.east.data,
						&all->minilibx.east, 0));
	}
	else
	{
		if (all->info.raydirx > 0)
			return (ft_color_texture(all, all->minilibx.south.data,
						&all->minilibx.south, 1));
		else if (all->info.raydirx < 0)
			return (ft_color_texture(all, all->minilibx.north.data,
						&all->minilibx.north, 1));
	}
	return (0);
}

void	sprite_pos(t_cub *all, int n)
{
	all->spr.spritex = all->spr.tab[n].x - all->coord.x;
	all->spr.spritey = all->spr.tab[n].y - all->coord.y;
	all->spr.invdet = 1.0 / (all->info.planex * all->info.diry -
			all->info.dirx * all->info.planey);
	all->spr.transformx = all->spr.invdet * (all->info.diry *
			all->spr.spritex - all->info.dirx * all->spr.spritey);
	all->spr.transformy = all->spr.invdet * (-all->info.planey *
			all->spr.spritex + all->info.planex * all->spr.spritey);
	all->spr.spritescreenx = (int)((all->res_x / 2) * (1.0 +
				all->spr.transformx / all->spr.transformy));
}

void	sprite_dim(t_cub *all)
{
	all->spr.spriteheight = abs((int)(all->res_y /
				(all->spr.transformy))) * 0.5;
	all->spr.drawstarty = -all->spr.spriteheight * (0.5 - all->coord.z) +
		all->res_y * (0.5 + all->coord.z) - all->spr.spriteheight *
		all->spr.tab[all->spr.n].size;
	all->spr.drawendy = all->spr.spriteheight * (0.5 + all->coord.z) +
		all->res_y * (0.5 + all->coord.z) - all->spr.spriteheight *
		all->spr.tab[all->spr.n].size;
	all->spr.spritewidth = abs((int)(all->res_y /
				(all->spr.transformy))) * 0.5;
	all->spr.drawstartx = -all->spr.spritewidth * (0.5) +
		all->spr.spritescreenx;
	all->spr.drawendx = all->spr.spritewidth * (0.5) + all->spr.spritescreenx;
}
