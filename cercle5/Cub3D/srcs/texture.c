/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:13:04 by lusokol           #+#    #+#             */
/*   Updated: 2020/06/26 15:45:31 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_texture_floor(t_cub *all, t_text *text)
{
	all->floceil.currentdist = (double)((double)all->res_y /
	((((double)all->draw.floor) / (0.5 + all->coord.z)) - (double)all->res_y));
	all->floceil.coeff = all->floceil.currentdist / all->info.perpwalldist;
	all->floceil.currentfloorx = all->floceil.coeff * all->floceil.floorxwall
		+ (1.0 - all->floceil.coeff) * all->coord.x;
	all->floceil.currentfloory = all->floceil.coeff * all->floceil.floorywall
		+ (1.0 - all->floceil.coeff) * all->coord.y;
	all->floceil.currentfloorx = (int)(all->floceil.currentfloorx * text->w)
		% text->w;
	all->floceil.currentfloory = (int)(all->floceil.currentfloory * text->h)
		% text->h;
	all->floceil.currentfloorx = fabs(all->floceil.currentfloorx);
	all->floceil.currentfloory = fabs(all->floceil.currentfloory);
	all->draw.jump = ((double)all->draw.hauteurligne / 3.0)
		* (all->coord.z * 10);
	return (text->data[(int)(all->floceil.currentfloorx + text->w *
				all->floceil.currentfloory)]);
}

int		ft_color_texture(t_cub *all, int *ptr, t_text *text, int i)
{
	int		line;
	int		column;
	double	tmp;

	line = (((double)all->draw.y - (double)((int)(-(all->draw.hauteurligne) *
			(0.5 - all->coord.z)) + (int)(all->res_y * (0.5 + all->coord.z))))
			/ (double)all->draw.hauteurligne) * (double)((double)text->h);
	if (i == 1)
		tmp = (all->info.rayposy + all->info.perpwalldist * all->info.raydiry);
	if (i == 0)
		tmp = (all->info.rayposx + all->info.perpwalldist * all->info.raydirx);
	tmp -= floor(tmp);
	column = (tmp * ((double)text->w) - 1);
	if (column < 0)
		column = text->w - column;
	(void)ptr;
	if (line >= text->h)
		line = text->h - 1;
	line = abs(line);
	return (ptr[column + text->w * line]);
}

t_text	take_text(t_cub *all, char *text_addr)
{
	t_text texture;

	if (!(texture.ptr = mlx_xpm_file_to_image(all->minilibx.mlx_ptr,
					text_addr, &texture.w, &texture.h)))
	{
		printf("Error\n\"%s\" is an incorrect texture path.\n", text_addr);
		ft_exit(all);
	}
	if (!(texture.data = (int*)mlx_get_data_addr(texture.ptr,
					&texture.bpp, &texture.line_size, &texture.endian)))
	{
		printf("Error\nmlx_get_data_addr texture\n");
		ft_exit(all);
	}
	return (texture);
}

void	init_text_next(t_cub *all)
{
	all->hud.number.num[0] = take_text(all, "./textures/numbers/font0.xpm");
	all->hud.number.num[1] = take_text(all, "./textures/numbers/font1.xpm");
	all->hud.number.num[2] = take_text(all, "./textures/numbers/font2.xpm");
	all->hud.number.num[3] = take_text(all, "./textures/numbers/font3.xpm");
	all->hud.number.num[4] = take_text(all, "./textures/numbers/font4.xpm");
	all->hud.number.num[5] = take_text(all, "./textures/numbers/font5.xpm");
	all->hud.number.num[6] = take_text(all, "./textures/numbers/font6.xpm");
	all->hud.number.num[7] = take_text(all, "./textures/numbers/font7.xpm");
	all->hud.number.num[8] = take_text(all, "./textures/numbers/font8.xpm");
	all->hud.number.num[9] = take_text(all, "./textures/numbers/font9.xpm");
}

void	init_text(t_cub *all)
{
	all->minilibx.north = take_text(all, all->north);
	all->minilibx.south = take_text(all, all->south);
	all->minilibx.west = take_text(all, all->west);
	all->minilibx.east = take_text(all, all->east);
	if (all->rgbf != 1)
		all->minilibx.floor = take_text(all, all->floor);
	if (all->rgbc != 1)
		all->minilibx.skybox = take_text(all, all->ceilling);
	all->minilibx.sprite = take_text(all, all->sprite);
	all->minilibx.sprite1 = take_text(all, all->sprite1);
	all->spr.goomba.frame1 = take_text(all, "./textures/goomba1.xpm");
	all->spr.goomba.frame2 = take_text(all, "./textures/goomba2.xpm");
	all->spr.goomba.frame3 = take_text(all, "./textures/goomba3.xpm");
	all->spr.goomba.frame4 = take_text(all, "./textures/goomba4.xpm");
	all->hud.cp = take_text(all, "./textures/coeur_plein.xpm");
	all->hud.cv = take_text(all, "./textures/coeur_vide.xpm");
	all->hud.coin = take_text(all, "./textures/piece2.xpm");
	all->hud.fin = take_text(all, "./textures/gameover.xpm");
	all->skybox.ok = 1;
	init_text_next(all);
}
