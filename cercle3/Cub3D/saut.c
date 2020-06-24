/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saut.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:14:18 by lusokol           #+#    #+#             */
/*   Updated: 2020/03/11 19:51:41 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		select_sprite(t_cub *all, int x, int y)
{
	int n;

	n = 0;
	while ((int)all->spr.tab[n].x != x || (int)all->spr.tab[n].y != y || all->map[(int)all->coord.x][(int)all->coord.y] != '3' || all->spr.tab[n].spr != 2)
		n++;
	if (all->hud.hp < 3 && all->hud.hp > 0)
	{
		all->hud.hp++;
		system("afplay ./sound/hpp.wav&");
	}
	return (n);
}

void	change_sprite(t_cub *all, int x, int y)
{
	int		n;
	double	tmpsize;
	double	tmpx;
	double	tmpy;
	int		alive;

	n = select_sprite(all, x, y);
//	mlx_destroy_image(all->minilibx.mlx_ptr, all->spr.tab[n].ptr);
//	free(all->spr.tab[n].data);
	tmpx = all->spr.tab[n].x;
	tmpy = all->spr.tab[n].y;
	alive = all->spr.tab[n].alive;
	tmpsize = all->spr.tab[n].size;
	all->spr.tab[n] = take_text(all, all->sprite1);
	all->spr.tab[n].x = tmpx;
	all->spr.tab[n].y = tmpy;
	all->spr.tab[n].alive = alive;
	all->spr.tab[n].size = tmpsize;
}

int		ft_timer(t_cub *all, clock_t jump)
{
	clock_t	timer;
	double	diff;

	timer = clock();
	diff = (double)(timer - jump) / CLOCKS_PER_SEC;
	if (diff < 0.25 && all->map[(int)all->coord.x][(int)all->coord.y] == '2')
	{
		all->map[(int)all->coord.x][(int)all->coord.y] = '3';
		change_sprite(all, (int)all->coord.x, (int)all->coord.y);
	}
	all->coord.z = fabs(sin(diff * M_PI) / 10);
	if (diff > 0.25 && diff < 0.75)
		all->spr.goomba.safe = 1;
	else
		all->spr.goomba.safe = 0;
	if (diff > 0.5 && diff < 0.75)
		all->spr.goomba.cankill = 1;
	else
		all->spr.goomba.cankill = 0;
	if (diff >= 1)
		return (1);
	return (0);
}

void	ft_jump(t_cub *all)
{
	static int		ok;
	static clock_t	jump;
	int				tmp;

	if (ok != 1 && ok != 0)
		ok = 0;
	if (ok == 0)
		jump = clock();
	tmp = ok;
	if (all->key.j == 1)
		ok = 1;
	if (ok == 1)
		if (ft_timer(all, jump))
			ok = 0;
	if (ok == 1 && tmp == 0)
		system("afplay ./sound/saut.wav&");
}
