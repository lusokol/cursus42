/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:22:48 by lusokol           #+#    #+#             */
/*   Updated: 2020/03/07 13:02:01 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_calcul_skybox(t_cub *all)
{
	all->skybox.i = all->info.dirx;
	all->skybox.rot = all->minilibx.skybox.w;
	all->skybox.i = ((atan(all->info.dirx / -all->info.diry) / 2) + atan(1)) / (2 * atan(1));
	if (all->info.diry >= 0)
		all->skybox.rot *= (1 - ((1 + all->skybox.i) / 2));
	else
		all->skybox.rot *= (1 - (all->skybox.i / 2));
}

int		ft_skybox(t_cub *all, int x)
{
	double	coeffx;
	double	coeffy;

	coeffx = (double)x / (double)all->res_x;
	coeffx = coeffx * (all->minilibx.skybox.w / 4);
	coeffy = (double)all->draw.ceilling / ((double)all->res_y * 1);
	coeffy = coeffy * (double)all->minilibx.skybox.h;

	return (all->minilibx.skybox.data[(int)(coeffx + all->skybox.rot + all->minilibx.skybox.w * (int)coeffy)]);
}
