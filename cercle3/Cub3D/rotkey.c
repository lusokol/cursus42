/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotKey.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 12:13:36 by lusokol           #+#    #+#             */
/*   Updated: 2020/03/04 20:06:12 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		deal_key(t_cub *all)
{
	if (all->key.a)
		move_a(all);
	if (all->key.s)
		move_s(all);
	if (all->key.w)
		move_w(all);
	if (all->key.d)
		move_d(all);
	if (all->key.fg)
		move_fg(all);
	if (all->key.fd)
		move_fd(all);
	cubddd(all);
	return (0);
}

int		key_push(int key, t_cub *all)
{
	if (key == 13)
		all->key.w = 1;
	if (key == 0)
		all->key.a = 1;
	if (key == 1)
		all->key.s = 1;
	if (key == 2)
		all->key.d = 1;
	if (key == 124)
		all->key.fd = 1;
	if (key == 123)
		all->key.fg = 1;
	return (0);
}

int		key_release(int key, t_cub *all)
{
	if (key == 13)
		all->key.w = 0;
	if (key == 0)
		all->key.a = 0;
	if (key == 1)
		all->key.s = 0;
	if (key == 2)
		all->key.d = 0;
	if (key == 124)
		all->key.fd = 0;
	if (key == 123)
		all->key.fg = 0;
	return (0);
}

void	move_fg(t_cub *all)
{
	double	test;

	test = all->info.dirx;
	all->info.dirx = all->info.dirx * cos(all->vit.rot)
		- all->info.diry * sin(all->vit.rot);
	all->info.diry = test * sin(all->vit.rot) + all->info.diry
		* cos(all->vit.rot);
	all->info.planex = -0.66 * all->info.diry;
	all->info.planey = 0.66 * all->info.dirx;
}

void	move_fd(t_cub *all)
{
	double	test;

	test = all->info.dirx;
	all->info.dirx = all->info.dirx * cos(-all->vit.rot)
		- all->info.diry * sin(-all->vit.rot);
	all->info.diry = test * sin(-all->vit.rot) + all->info.diry
		* cos(-all->vit.rot);
	all->info.planex = -0.66 * all->info.diry;
	all->info.planey = 0.66 * all->info.dirx;
}
