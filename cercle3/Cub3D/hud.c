/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 10:49:35 by lusokol           #+#    #+#             */
/*   Updated: 2020/03/11 18:49:06 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		take_heart(int heart, t_cub *all, double i, double ratio)
{
	if (heart <= all->hud.hp)
		return (all->hud.cp.data[(int)(ratio * all->hud.cp.w + all->hud.cp.w * (int)(i * all->hud.cp.h))]);
	else
		return (all->hud.cv.data[(int)(ratio * all->hud.cv.w + all->hud.cv.w * (int)(i * all->hud.cv.h))]);
}

int		take_gold(t_cub *all, int img, double ratioy, double ratiox)
{
	if (img == 0)
		return (all->hud.coin.data[(int)((int)(ratiox * all->hud.coin.w)  + (int)(all->hud.coin.w * (int)(ratioy * all->hud.coin.h)))]);
	else if (img == 1)
		return (all->hud.number.num[all->hud.gold / 10].data[(int)((int)(ratiox * all->hud.number.num[all->hud.gold / 10].w) + (int)(all->hud.number.num[all->hud.gold / 10].w * (int)(ratioy * all->hud.number.num[all->hud.gold / 10].h)))]);
	else
		return (all->hud.number.num[all->hud.gold % 10].data[(int)((int)(ratiox * all->hud.number.num[all->hud.gold % 10].w) + (int)(all->hud.number.num[all->hud.gold % 10].w * (int)(ratioy * all->hud.number.num[all->hud.gold % 10].h)))]);
}

void	gold(t_cub *all, int *img_data)
{
	int		width;
	int		img;
	int		y;
	int		i;
	int		tmp;

	img = 0;
	while (img < 3)
	{
		width = all->res_x / 10;
		all->hud.drawstart = width * img - ((img == 2) ? width * 0.4 : 0);
		all->hud.drawend = all->hud.drawstart + width;
		y = all->hud.drawstart;
		while (y < all->hud.drawend)
		{
			i = 0;
			while (i < width - 1)
			{
				//printf("ds : %d, de : %d, y : %d, i : %d, w : %d\n", all->hud.drawstart, all->hud.drawend, y, i, width);
				double ratiox = (double)(y - all->hud.drawstart) / (double)(all->hud.drawend - all->hud.drawstart);
				double ratioy = (double)i / (double)width;
				//printf("ratiox : %f, ratioy : %f\n", ratiox, ratioy);
				tmp = take_gold(all, img, ratioy, ratiox);
				//tmp = take_gold(all, 0, (double)i / ((double)width), (double)(y - all->hud.drawstart) / (double)(all->hud.drawend - all->hud.drawstart));
				if (tmp == -16777216)
					tmp = img_data[y + all->res_x * i];
				img_data[y + all->res_x * i] = tmp;
				i++;
			}
			y++;
		}
		img++;
	}
}

void	hud(t_cub *all, int *img_data)
{
	int		width;
	int		heart;
	int		y;
	int		i;
	int		tmp;

	gold(all, img_data);
	heart = 3;
	while (heart > 0)
	{
		width = all->res_x / 10;
		all->hud.drawstart = all->res_x - width * heart;
		all->hud.drawend = all->hud.drawstart + width;
		y = all->hud.drawstart;
		while (y < all->hud.drawend)
		{
			i = 0;
			while (i < width)
			{
				tmp = take_heart(heart, all, (double)i / (double)width, (double)(y - all->hud.drawstart) / (double)(all->hud.drawend - all->hud.drawstart));
				if (tmp == -16777216)
					tmp = img_data[y + all->res_x * i];
				img_data[y + all->res_x * i] = tmp;
				i++;
			}
			y++;
		}
		heart--;
	}
}
