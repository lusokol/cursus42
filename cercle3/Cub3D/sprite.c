/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:13:29 by lusokol           #+#    #+#             */
/*   Updated: 2020/03/07 16:10:42 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_pos(t_cub *all)
{
	all->spr.spritex = 5.5 - all->coord.x;
	all->spr.spritey = 5.5 - all->coord.y;
	all->spr.invdet = 1.0 / (all->info.planex * all->info.diry - all->info.dirx * all->info.planey);
	all->spr.transformx = all->spr.invdet * (all->info.diry * all->spr.spritex - all->info.dirx * all->spr.spritey);
	all->spr.transformy = all->spr.invdet * (-all->info.planey * all->spr.spritex + all->info.planex * all->spr.spritey);
	all->spr.spritescreenx = (int)((all->res_x / 2) * (1.0 + all->spr.transformx / all->spr.transformy));
}

void	sprite_dim(t_cub *all)
{
	all->spr.spriteheight = abs((int)(all->res_y / (all->spr.transformy))) * 0.5;
	all->spr.drawstarty = -all->spr.spriteheight * (0.5 - all->coord.z) + all->res_y * (0.5 + all->coord.z) - all->spr.spriteheight * 0.75;
	all->spr.drawendy = all->spr.spriteheight * (0.5 + all->coord.z)+ all->res_y * (0.5 + all->coord.z) - all->spr.spriteheight * 0.75;
	all->spr.spritewidth = abs((int)(all->res_y / (all->spr.transformy))) * 0.5;
	all->spr.drawstartx = -all->spr.spritewidth * (0.5) + all->spr.spritescreenx;
	all->spr.drawendx = all->spr.spritewidth * (0.5) + all->spr.spritescreenx;
}

void	sprite_timer(t_cub *all)
{
	all->spr.end = clock();
	all->spr.millis = (double)(all->spr.end - g_begin) / CLOCKS_PER_SEC;
	while (all->spr.millis > 2)
		all->spr.millis -= 2;
	all->spr.millis = floor(all->spr.millis / 2 * all->minilibx.sprite.w);
}

void	timer_calcul(t_cub *all, int z, int y)
{
	all->spr.coeffx = all->minilibx.sprite.w - all->minilibx.sprite.w * ((double)(z - all->spr.drawstartx) / (double)(all->spr.drawendx - all->spr.drawstartx));
	all->spr.coeffy = all->minilibx.sprite.h * ((double)(y - all->spr.drawstarty) / (double)(all->spr.drawendy - all->spr.drawstarty));
	if (all->spr.coeffx >= all->minilibx.sprite.w)
		all->spr.coeffx = all->minilibx.sprite.w - 1;
	if (all->spr.coeffx + all->spr.millis <= 0)
		all->spr.millis = all->spr.millis + all->minilibx.sprite.w - 1;
	if (all->spr.coeffx + all->spr.millis >= all->minilibx.sprite.w)
		all->spr.millis = all->spr.millis - all->minilibx.sprite.w;
}

void	print_sprite(t_cub *all, int *img_data)
{
	int		z;
	int		y;
//	int		d;

	sprite_pos(all);
	sprite_dim(all);
	sprite_timer(all);
	z = (all->spr.drawstartx < 0) ? 0 : all->spr.drawstartx;
	while (z < all->spr.drawendx && z < all->res_x)
	{
		y = (all->spr.drawstarty < 0) ? 0 : all->spr.drawstarty;
		while (y < all->spr.drawendy && y < all->res_y)
		{
			if (z >= 0 && z < all->res_x && y >= 0 && y < all->res_y && all->spr.transformy > 0)
			{
				timer_calcul(all, z, y);
				img_data[(all->res_x - z - 1) + y * (all->res_x)] = all->minilibx.sprite.data[(int)(all->spr.coeffx + all->spr.millis + all->spr.coeffy * all->minilibx.sprite.w)];
			}
			y++;
		}
		z++;
	}
}
