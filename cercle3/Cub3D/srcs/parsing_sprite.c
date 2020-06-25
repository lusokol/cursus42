/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:26:36 by lusokol           #+#    #+#             */
/*   Updated: 2020/06/25 18:39:56 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_is_sprite(char a)
{
	if (a == '2' || a == '3' || a == '4')
		return (1);
	return (0);
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

void	ft_take_sprite(t_cub *all, int j, int i, int n)
{
	if (all->map[j][i] == '2')
	{
		all->spr.tab[n] = take_text(all, all->sprite);
		all->spr.tab[n].anim = 1;
		all->spr.tab[n].size = 0.75;
		all->spr.tab[n].spr = 2;
		all->spr.tab[n].sens = -1;
		all->spr.tab[n].alive = 1;
	}
	else if (all->map[j][i] == '3')
	{
		all->spr.tab[n] = take_text(all, all->sprite1);
		all->spr.tab[n].anim = 0;
		all->spr.tab[n].size = 0.75;
		all->spr.tab[n].spr = 3;
		all->spr.tab[n].sens = -1;
		all->spr.tab[n].alive = 1;
	}
	else if (all->map[j][i] == '4')
		ft_take_sprite_next(all, n);
	all->spr.tab[n].x = j + 0.5;
	all->spr.tab[n].y = i + 0.5;
}

void	sprite_pars(t_cub *all)
{
	int		i;
	int		j;
	int		n;

	n = 0;
	j = 0;
	all->spr.tab = malloc(sizeof(t_text) * (all->spr.nbr + 1));
	while (all->map[j])
	{
		i = 0;
		while (all->map[j][i])
		{
			if (ft_is_sprite(all->map[j][i]))
				ft_take_sprite(all, j, i, n++);
			i++;
		}
		j++;
	}
}

double	sort_calc(t_cub *all, int n)
{
	return (((all->coord.x - all->spr.tab[n].x) * (all->coord.x -
			all->spr.tab[n].x) + (all->coord.y - all->spr.tab[n].y)
			* (all->coord.y - all->spr.tab[n].y)));
}

void	ft_sort_sprite_alive(t_cub *all, int nbr)
{
	int		n;
	t_text	tmp;

	n = 0;
	while (n < nbr - 1)
	{
		if ((all->spr.tab[n].alive == 0 && all->spr.tab[n + 1].alive == 1))
		{
			tmp = all->spr.tab[n];
			all->spr.tab[n] = all->spr.tab[n + 1];
			all->spr.tab[n + 1] = tmp;
			n = 0;
		}
		else
			n++;
	}
	n = 0;
	while (all->spr.tab[n].alive == 1)
		n++;
	all->spr.nbr = n;
}

void	ft_sort_sprite(t_cub *all, int nbr)
{
	int		n;
	t_text	tmp;

	n = 0;
	ft_sort_sprite_alive(all, nbr);
	while (n < nbr - 1)
	{
		if ((sort_calc(all, n) < sort_calc(all, n + 1)) &&
				all->spr.tab[n + 1].alive == 1)
		{
			tmp = all->spr.tab[n];
			all->spr.tab[n] = all->spr.tab[n + 1];
			all->spr.tab[n + 1] = tmp;
			n = 0;
		}
		else
			n++;
	}
	n = 0;
	while (all->spr.tab[n].alive == 1)
		n++;
	all->spr.nbr = n;
}
