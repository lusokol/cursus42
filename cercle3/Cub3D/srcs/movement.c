/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 12:09:23 by lusokol           #+#    #+#             */
/*   Updated: 2020/06/26 14:29:30 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
