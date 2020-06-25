/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:13:29 by lusokol           #+#    #+#             */
/*   Updated: 2020/06/25 19:15:58 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	sprite_timer(t_cub *all, int n)
{
	all->spr.end = clock();
	all->spr.millis = (double)(all->spr.end - g_begin) / CLOCKS_PER_SEC;
	while (all->spr.millis > 2)
		all->spr.millis -= 2;
	all->spr.millis = floor(all->spr.millis / 2 * all->spr.tab[n].w);
}

void	timer_calcul(t_cub *all, int z, int y, int n)
{
	all->spr.coeffx = all->spr.tab[n].w - all->spr.tab[n].w * ((double)(z -
	all->spr.drawstartx) / (double)(all->spr.drawendx - all->spr.drawstartx));
	all->spr.coeffy = all->spr.tab[n].h * ((double)(y - all->spr.drawstarty)
			/ (double)(all->spr.drawendy - all->spr.drawstarty));
	if (all->spr.coeffx >= all->spr.tab[n].w)
		all->spr.coeffx = all->spr.tab[n].w - 1;
	if (all->spr.coeffx + all->spr.millis <= 0)
		all->spr.millis = all->spr.millis + all->spr.tab[n].w - 1;
	if (all->spr.coeffx + all->spr.millis >= all->spr.tab[n].w)
		all->spr.millis = all->spr.millis - all->spr.tab[n].w;
}

void	check_transparent(t_cub *all, int *img_data, int z, int y)
{
	int tmp;

	if (all->spr.tab[all->spr.n].anim == 1)
		tmp = all->spr.tab[all->spr.n].data[(int)(all->spr.coeffx +
				all->spr.millis + all->spr.coeffy *
				all->spr.tab[all->spr.n].w)];
	else
	{
		if (all->spr.tab[all->spr.n].sens == 1 && all->info.raydiry > 0)
			tmp =
	all->spr.tab[all->spr.n].data[(int)((all->spr.tab[all->spr.n].w -
				all->spr.coeffx - 1) + all->spr.coeffy *
			all->spr.tab[all->spr.n].w)];
		else if (all->spr.tab[all->spr.n].sens == 0 && all->info.raydiry < 0)
			tmp =
	all->spr.tab[all->spr.n].data[(int)((all->spr.tab[all->spr.n].w -
	all->spr.coeffx - 1) + all->spr.coeffy *
	all->spr.tab[all->spr.n].w)];
		else
			tmp = all->spr.tab[all->spr.n].data[(int)(all->spr.coeffx +
		all->spr.coeffy * all->spr.tab[all->spr.n].w)];
	}
	if (tmp == -16777216)
		tmp = img_data[(all->res_x - z - 1) + y * (all->res_x)];
	img_data[(all->res_x - z - 1) + y * (all->res_x)] = tmp;
}

int		spr_fct(t_cub *all)
{
	sprite_pos(all, all->spr.n);
	sprite_dim(all);
	sprite_timer(all, all->spr.n);
	return (((all->spr.drawstartx < 0) ? 0 : all->spr.drawstartx) - 1);
}

void	print_sprite(t_cub *all, int *img_data)
{
	int		z;
	int		y;

	all->spr.n = -1;
	ft_sort_sprite(all, all->spr.nbr);
	while (++all->spr.n < all->spr.nbr)
	{
		z = spr_fct(all);
		while (++z < all->spr.drawendx && z < all->res_x)
			if ((all->spr.spritex * all->spr.spritex + all->spr.spritey *
				all->spr.spritey) < all->info.dist[z] * all->info.dist[z])
			{
				y = ((all->spr.drawstarty < 0) ? 0 : all->spr.drawstarty) - 1;
				while (++y < all->spr.drawendy && y < all->res_y)
					if (z >= 0 && z < all->res_x && y >= 0 && y < all->res_y
							&& all->spr.transformy > 0)
					{
						timer_calcul(all, z, y, all->spr.n);
						check_transparent(all, img_data, z, y);
					}
			}
		if (all->spr.tab[all->spr.n].spr == 4)
			check_colision(all, all->spr.tab[all->spr.n].x,
					all->spr.tab[all->spr.n].y);
	}
}
