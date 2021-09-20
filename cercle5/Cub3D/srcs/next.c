/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 15:25:24 by lusokol           #+#    #+#             */
/*   Updated: 2020/06/26 20:09:17 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit(t_cub *all)
{
	if (all && all->minilibx.mlx_ptr && all->minilibx.win_ptr)
	{
		mlx_clear_window(all->minilibx.mlx_ptr, all->minilibx.win_ptr);
		mlx_destroy_window(all->minilibx.mlx_ptr, all->minilibx.win_ptr);
	}
	exit(0);
}

int		gold_next(t_cub *all, int img)
{
	int width;

	width = all->res_x / 10;
	all->hud.drawstart = width * img - ((img == 2) ? width * 0.4 : 0);
	all->hud.drawend = all->hud.drawstart + width;
	return (all->hud.drawstart);
}

void	ft_take_sprite_next(t_cub *all, int n)
{
	all->spr.tab[n] = all->spr.goomba.frame1;
	all->spr.tab[n].anim = 0;
	all->spr.tab[n].size = -0.5;
	all->spr.tab[n].spr = 4;
	all->spr.tab[n].sens = 1;
	all->spr.tab[n].col = 0;
	all->spr.tab[n].alive = 1;
}

double	sort_calc(t_cub *all, int n)
{
	return (((all->coord.x - all->spr.tab[n].x) * (all->coord.x -
			all->spr.tab[n].x) + (all->coord.y - all->spr.tab[n].y)
			* (all->coord.y - all->spr.tab[n].y)));
}
