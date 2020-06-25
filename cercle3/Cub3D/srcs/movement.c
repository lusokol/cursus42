/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 12:09:23 by lusokol           #+#    #+#             */
/*   Updated: 2020/06/25 18:32:34 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_colision_next(t_cub *all, int tmp)
{
	if (tmp == 0 && all->spr.tab[all->spr.n].col == 1
			&& all->spr.goomba.safe == 0)
		if (all->hud.hp > 0)
		{
			all->hud.hp--;
			system("afplay ./sound/hpm.wav&");
		}
}

void	check_colision(t_cub *all, double x, double y)
{
	double	diff;
	int		tmp;

	diff = 0.3;
	tmp = all->spr.tab[all->spr.n].col;
	if (x - diff < all->coord.x && x + diff > all->coord.x)
	{
		if (y - diff < all->coord.y && y + diff > all->coord.y)
		{
			if (all->spr.goomba.safe == 0)
				all->spr.tab[all->spr.n].col = 1;
			else if (all->spr.goomba.cankill == 1 &&
					all->spr.tab[all->spr.n].spr == 4)
			{
				all->spr.tab[all->spr.n].alive = 0;
				all->hud.gold++;
				system("afplay ./sound/piece.wav&");
			}
		}
		else
			all->spr.tab[all->spr.n].col = 0;
	}
	else
		all->spr.tab[all->spr.n].col = 0;
	check_colision_next(all, tmp);
}

void	move_w(t_cub *all)
{
	double tmp_x;
	double tmp_y;

	tmp_x = all->coord.x;
	tmp_y = all->coord.y;
	all->coord.x += all->info.dirx / 10 * all->vit.mvt;
	all->coord.y += all->info.diry / 10 * all->vit.mvt;
	if (all->map[(int)all->coord.x][(int)tmp_y] == '1')
		all->coord.x = tmp_x;
	if (all->map[(int)tmp_x][(int)all->coord.y] == '1')
		all->coord.y = tmp_y;
}

void	move_d(t_cub *all)
{
	double tmp_x;
	double tmp_y;

	tmp_x = all->coord.x;
	tmp_y = all->coord.y;
	all->coord.x -= all->info.planex / 10 * all->vit.mvt;
	all->coord.y -= all->info.planey / 10 * all->vit.mvt;
	if (all->map[(int)all->coord.x][(int)tmp_y] == '1')
		all->coord.x = tmp_x;
	if (all->map[(int)tmp_x][(int)all->coord.y] == '1')
		all->coord.y = tmp_y;
}

void	move_s(t_cub *all)
{
	double tmp_x;
	double tmp_y;

	tmp_x = all->coord.x;
	tmp_y = all->coord.y;
	all->coord.x -= all->info.dirx / 10 * all->vit.mvt;
	all->coord.y -= all->info.diry / 10 * all->vit.mvt;
	if (all->map[(int)all->coord.x][(int)tmp_y] == '1')
		all->coord.x = tmp_x;
	if (all->map[(int)tmp_x][(int)all->coord.y] == '1')
		all->coord.y = tmp_y;
}

void	move_a(t_cub *all)
{
	double tmp_x;
	double tmp_y;

	tmp_x = all->coord.x;
	tmp_y = all->coord.y;
	all->coord.x += all->info.planex / 10 * all->vit.mvt;
	all->coord.y += all->info.planey / 10 * all->vit.mvt;
	if (all->map[(int)all->coord.x][(int)tmp_y] == '1')
		all->coord.x = tmp_x;
	if (all->map[(int)tmp_x][(int)all->coord.y] == '1')
		all->coord.y = tmp_y;
}
