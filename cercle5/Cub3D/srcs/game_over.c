/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 17:08:59 by lusokol           #+#    #+#             */
/*   Updated: 2020/06/25 17:09:55 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	aff_img(t_cub *all, int *img_ptr)
{
	int		i;
	int		j;
	double	ratiox;
	double	ratioy;

	i = 0;
	j = 0;
	while (i < all->res_x)
	{
		j = 0;
		while (j < all->res_y)
		{
			ratiox = (double)i / (double)all->res_x;
			ratioy = (double)j / (double)all->res_y;
			img_ptr[i + j * all->res_y] = all->hud.fin.data[(int)((int)(ratiox *
	all->hud.fin.w) + (int)(all->hud.fin.w * (int)(ratioy * all->hud.fin.h)))];
			j++;
		}
		i++;
	}
}

void	game_over(t_cub *all, int *img_data)
{
	static char music;

	if (!music)
		music = 'a';
	if (all->hud.hp == 0)
	{
		aff_img(all, img_data);
		if (music == 'a')
		{
			system("killall afplay");
			system("afplay ./sound/dead.wav&");
			music = 'b';
		}
	}
}
