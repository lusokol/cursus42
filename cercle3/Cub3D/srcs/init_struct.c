/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:30:03 by lusokol           #+#    #+#             */
/*   Updated: 2020/06/26 17:00:25 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	text_null(t_cub *all)
{
	all->north = NULL;
	all->south = NULL;
	all->east = NULL;
	all->west = NULL;
	all->floor = NULL;
	all->ceilling = NULL;
	all->sprite = NULL;
	all->sprite1 = NULL;
	all->sprite2 = NULL;
	all->minilibx.win_ptr = NULL;
	all->rgbc = 0;
	all->rgbf = 0;
	all->save = 0;
}

int		ft_spawnlettre(t_cub *all, int i, int j, char a)
{
	if (a == 'W')
	{
		all->info.dirx = 0;
		all->info.diry = -1;
	}
	if (a == 'E')
	{
		all->info.dirx = 0;
		all->info.diry = 1;
	}
	if (a == 'S')
	{
		all->info.dirx = 1;
		all->info.diry = 0;
	}
	if (a == 'N')
	{
		all->info.dirx = -1;
		all->info.diry = 0;
	}
	all->coord.x = j + 0.5;
	all->coord.y = i + 0.5;
	return (1);
}

void	init_struct(t_cub *all)
{
	all->info.planex = -0.66 * all->info.diry;
	all->info.planey = 0.66 * all->info.dirx;
	all->key.w = 0;
	all->key.a = 0;
	all->key.s = 0;
	all->key.d = 0;
	all->key.fd = 0;
	all->key.fg = 0;
	all->key.j = 0;
	all->key.exit = 0;
	all->coord.z = 0;
	all->spr.nbr = 0;
	all->hud.hp = 3;
	all->hud.gold = 0;
	all->spr.goomba.frame = 1;
	all->spr.goomba.safe = 0;
	all->spr.goomba.cankill = 0;
	all->sprite2 = NULL;
	all->minilibx.win_ptr = NULL;
}

void	ft_mlx_init(t_cub *all)
{
	all->minilibx.mlx_ptr = mlx_init();
	init_text(all);
	sprite_pars(all);
	all->minilibx.win_ptr = mlx_new_window(all->minilibx.mlx_ptr,
			all->res_x, all->res_y, "Cub3D");
	cubddd(all);
	mlx_hook(all->minilibx.win_ptr, 2, (1L << 0), &key_push, all);
	mlx_hook(all->minilibx.win_ptr, 3, (1L << 1), &key_release, all);
	mlx_loop_hook(all->minilibx.mlx_ptr, &deal_key, all);
	mlx_loop(all->minilibx.mlx_ptr);
}
