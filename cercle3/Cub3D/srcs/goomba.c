/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goomba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:20:42 by lusokol           #+#    #+#             */
/*   Updated: 2020/06/25 17:24:31 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_next_frame2(t_cub *all, int i)
{
	if (all->spr.goomba.frame == 1)
		all->spr.tab[i] = all->spr.goomba.frame1;
	if (all->spr.goomba.frame == 2)
		all->spr.tab[i] = all->spr.goomba.frame2;
	if (all->spr.goomba.frame == 3)
		all->spr.tab[i] = all->spr.goomba.frame3;
	if (all->spr.goomba.frame == 4)
		all->spr.tab[i] = all->spr.goomba.frame4;
}

void	ft_next_frame(t_cub *all, int i)
{
	double	tmpx;
	double	tmpy;
	int		sens;
	int		col;
	int		alive;

	tmpx = all->spr.tab[i].x;
	tmpy = all->spr.tab[i].y;
	sens = all->spr.tab[i].sens;
	col = all->spr.tab[i].col;
	alive = all->spr.tab[i].alive;
	ft_next_frame2(all, i);
	all->spr.tab[i].sens = sens;
	all->spr.tab[i].x = tmpx;
	all->spr.tab[i].y = tmpy;
	all->spr.tab[i].spr = 4;
	all->spr.tab[i].size = -0.5;
	all->spr.tab[i].col = col;
	all->spr.tab[i].alive = alive;
}

void	frame_calc(t_cub *all, double diff)
{
	if (diff >= 0 && diff < 0.5)
		all->spr.goomba.frame = 1;
	else if (diff >= 0.5 && diff < 1)
		all->spr.goomba.frame = 2;
	else if (diff >= 1.0 && diff < 1.5)
		all->spr.goomba.frame = 3;
	else if (diff >= 1.5 && diff < 2.0)
		all->spr.goomba.frame = 4;
}

void	ft_move_goomba(t_cub *all, int i)
{
	double tmpx;

	tmpx = all->spr.tab[i].x;
	if (all->spr.tab[i].sens == 1)
	{
		all->spr.tab[i].x += 0.02;
		if (all->map[(int)(all->spr.tab[i].x + 0.35)]
				[(int)all->spr.tab[i].y] == '1')
		{
			all->spr.tab[i].sens = 0;
			all->spr.tab[i].x = tmpx;
		}
	}
	else if (all->spr.tab[i].sens == 0)
	{
		all->spr.tab[i].x -= 0.02;
		if (all->map[(int)(all->spr.tab[i].x - 0.35)]
				[(int)all->spr.tab[i].y] == '1')
		{
			all->spr.tab[i].sens = 1;
			all->spr.tab[i].x = tmpx;
		}
	}
}

void	anim_goomba(t_cub *all)
{
	int		i;
	clock_t	time;
	double	diff;

	i = 0;
	time = clock();
	diff = (double)(time - g_begin) / CLOCKS_PER_SEC;
	while (diff > 2)
		diff -= 2;
	frame_calc(all, diff);
	while (i < all->spr.nbr)
	{
		if (all->spr.tab[i].spr == 4)
		{
			ft_next_frame(all, i);
			ft_move_goomba(all, i);
		}
		i++;
	}
}
