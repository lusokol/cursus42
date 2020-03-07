/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:13:04 by lusokol           #+#    #+#             */
/*   Updated: 2020/03/07 12:22:14 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_calcfloor(t_cub *all)
{
	if (all->info.side == 1)
		all->floceil.wallx = all->info.rayposx + ((all->info.mapy - all->info.rayposy + (1 - all->info.stepy) * (0.5)) / all->info.raydiry) * all->info.raydirx;
	else
		all->floceil.wallx = all->info.rayposy + ((all->info.mapx - all->info.rayposx + (1 - all->info.stepx) * (0.5)) / all->info.raydirx) * all->info.raydiry;
	all->floceil.wallx -= floor(all->floceil.wallx);
	if (all->info.side == 0 && all->info.raydirx > 0)
	{
		all->floceil.floorxwall = all->info.mapx;
		all->floceil.floorywall = all->info.mapy + all->floceil.wallx;
	} 
	else if (all->info.side == 0 && all->info.raydirx < 0)
	{
		all->floceil.floorxwall = all->info.mapx + 1.0;
		all->floceil.floorywall = all->info.mapy + all->floceil.wallx;
	}
	else if (all->info.side == 1 && all->info.raydiry > 0)
	{
		all->floceil.floorxwall = all->info.mapx + all->floceil.wallx;
		all->floceil.floorywall = all->info.mapy;
	}
	else
	{
		all->floceil.floorxwall = all->info.mapx + all->floceil.wallx;
		all->floceil.floorywall = all->info.mapy + 1.0;
	}
}

int		ft_texture_floor(t_cub *all, t_text *text)
{
	all->floceil.currentdist = (double)((double)all->res_y / (((double)all->draw.floor / (0.5 + all->coord.z)) - (double)all->res_y));//dist
	all->floceil.coeff = all->floceil.currentdist / all->info.perpwalldist;// coef
	all->floceil.currentfloorx = all->floceil.coeff * all->floceil.floorxwall + (1.0 - all->floceil.coeff) * all->coord.x;
	all->floceil.currentfloory = all->floceil.coeff * all->floceil.floorywall + (1.0 - all->floceil.coeff) * all->coord.y;
	all->floceil.currentfloorx=(int)(all->floceil.currentfloorx * text->w) % text->w;
	all->floceil.currentfloory=(int)(all->floceil.currentfloory * text->h) % text->h;
	all->floceil.currentfloorx = fabs(all->floceil.currentfloorx);
	all->floceil.currentfloory = fabs(all->floceil.currentfloory);
	return (text->data[(int)(all->floceil.currentfloory + text->w * all->floceil.currentfloorx)]);
}

int		ft_texture(t_cub *all)
{
	if (all->info.side == 1)
	{
		if (all->info.raydiry > 0)
			return (ft_color_texture(all, all->minilibx.west.data, &all->minilibx.west, 0));
		if (all->info.raydiry < 0)
			return (ft_color_texture(all, all->minilibx.east.data, &all->minilibx.east, 0));
	}
	else
	{
		if (all->info.raydirx > 0)
			return (ft_color_texture(all, all->minilibx.south.data, &all->minilibx.south, 1));
		if (all->info.raydirx < 0)
			return (ft_color_texture(all, all->minilibx.north.data, &all->minilibx.north, 1));
	}
	return (0);
}

int		ft_color_texture(t_cub *all, int *ptr, t_text *text, int i)
{
	int line;
	int column;
	double	tmp;

	line = (((double)all->draw.y - (double)((int)(-(all->draw.hauteurligne) * (0.5 - all->coord.z)) + (int)(all->res_y * (0.5 + all->coord.z)))) / (double)all->draw.hauteurligne) * (double)((double)text->h);
	if (i == 1)
		tmp = (all->info.rayposy + all->info.perpwalldist * all->info.raydiry); 
	if (i == 0)
		tmp = (all->info.rayposx + all->info.perpwalldist * all->info.raydirx); 
	tmp -= floor(tmp);
	column = tmp * ((double)text->w - 1);
	if (column <= 0)
		column = text->w - column;
	(void)ptr;
	if (line >= text->h)
		line = text->h - 1;
	line = abs(line);
//	return (50000);
//	printf("column : %d\nline : %d\ntext.w : %d\ntext.h : %d\n\n", column, line, text->w, text->h);
	return (ptr[column + text->w * line]);
}

t_text	take_text(t_cub *all, char *text_addr)
{
	t_text texture;

	if (!(texture.ptr = mlx_xpm_file_to_image(all->minilibx.mlx_ptr, text_addr, &texture.w, &texture.h)))
	{
		printf("Error\nIncorrect texture path.");
		//ft_exit(all);
	}
	if (!(texture.data = (int*)mlx_get_data_addr(texture.ptr,
					&texture.bpp, &texture.line_size, &texture.endian)))
	{
		printf("Error\nmlx_get_data_addr texture");
		//ft_exit(all);
	}
	return (texture);
}

void	init_text(t_cub *all)
{
	all->minilibx.north = take_text(all, all->north);
	all->minilibx.south = take_text(all, all->south);
	all->minilibx.west = take_text(all, all->west);
	all->minilibx.east = take_text(all, all->east);
	all->minilibx.floor = take_text(all, all->floor);
	all->minilibx.skybox = take_text(all, all->ceilling);
	all->minilibx.sprite = take_text(all, all->sprite);
	all->skybox.ok = 1;
}
