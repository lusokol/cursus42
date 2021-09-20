/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:24:31 by lusokol           #+#    #+#             */
/*   Updated: 2020/06/26 14:36:01 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		check_colision_next(t_cub *all, int tmp)
{
	if (tmp == 0 && all->spr.tab[all->spr.n].col == 1
			&& all->spr.goomba.safe == 0)
		if (all->hud.hp > 0)
		{
			all->hud.hp--;
			system("afplay ./sound/hpm.wav&");
		}
}

void		check_colision(t_cub *all, double x, double y)
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

void		ft_check_info(char **str, int i, t_cub *all)
{
	if (str[i][0] == 'R')
		ft_take_res(all, str[i]);
	else if (str[i][0] == 'N' && str[i][1] == 'O')
		all->north = path(all, all->north, info(all, str[i] + 2, i, 0));
	else if (str[i][0] == 'S' && str[i][1] == 'O')
		all->south = path(all, all->south, info(all, str[i] + 2, i, 0));
	else if (str[i][0] == 'W' && str[i][1] == 'E')
		all->west = path(all, all->west, info(all, str[i] + 2, i, 0));
	else if (str[i][0] == 'E' && str[i][1] == 'A')
		all->east = path(all, all->east, info(all, str[i] + 2, i, 0));
	else if (str[i][0] == 'S' && str[i][1] != '1' && str[i][1] != '2')
		all->sprite = path(all, all->sprite, info(all, str[i] + 1, i, 0));
	else if (str[i][0] == 'F')
		all->floor = path(all, all->floor, info(all, str[i] + 1, i, 1));
	else if (str[i][0] == 'C')
		all->ceilling = path(all, all->ceilling, info(all, str[i] + 1, i, 2));
	else if (str[i][0] == 'S' && str[i][1] == '1')
		all->sprite1 = path(all, all->sprite1, info(all, str[i] + 2, i, 0));
	else if (str[i][0] == 'S' && str[i][1] == '2')
		all->sprite2 = path(all, all->sprite2, info(all, str[i] + 2, i, 0));
}

void		check_res(t_cub *all)
{
	int x;
	int y;

	mlx_get_screen_size(all->minilibx.mlx_ptr, &x, &y);
	if (all->res_x < 500)
		all->res_x = 500;
	if (all->res_y < 500)
		all->res_y = 500;
	if (all->res_x > x)
		all->res_x = x;
	if (all->res_y > y)
		all->res_y = y;
}

void		ft_take_res(t_cub *all, char *str)
{
	int i;

	i = 0;
	while (!(ft_isdigit(str[i])))
		i++;
	all->res_x = ft_atoi(str + i);
	while (ft_isdigit(str[i]))
		i++;
	while (!(ft_isdigit(str[i])))
		i++;
	all->res_y = ft_atoi(str + i);
	while (ft_isdigit(str[i]))
		i++;
	if (ft_atoi(str + i) != 0 || !all->res_x || !all->res_x)
	{
		ft_printf("Error\nResolution bad indent.\n");
		ft_exit(all);
	}
	check_res(all);
}
