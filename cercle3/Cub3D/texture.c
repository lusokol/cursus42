/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:13:04 by lusokol           #+#    #+#             */
/*   Updated: 2020/03/04 15:32:25 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_calcfloor(t_cub *all)
{
	if (all->info.side == 1)
		all->floceil.wallx = all->info.rayposx + ((all->info.mapy - all->info.rayposy + (1 - all->info.stepy) / 2) / all->info.raydiry) * all->info.raydirx;
	else
		all->floceil.wallx = all->info.rayposy + ((all->info.mapx - all->info.rayposx + (1 - all->info.stepx) / 2) / all->info.raydirx) * all->info.raydiry;
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
	ft_calcfloor(all);
	all->floceil.currentdist = (double)((double)all->res_y / (2.0 * (double)all->draw.floor - (double)all->res_y));//dist
	all->floceil.coeff = all->floceil.currentdist / all->info.perpwalldist;// coef
	all->floceil.currentfloorx = all->floceil.coeff * all->floceil.floorxwall + (1.0 - all->floceil.coeff) * all->coord.x;// position sur X
	all->floceil.currentfloory = all->floceil.coeff * all->floceil.floorywall + (1.0 - all->floceil.coeff) * all->coord.y;// position sur Y
	all->floceil.currentfloorx=(int)(all->floceil.currentfloorx * text->w) % text->w;// position texel sur X
	all->floceil.currentfloory=(int)(all->floceil.currentfloory * text->h) % text->h;// position texel sur Y
	//printf("currentdist :%5f, coeff :%5f, floorxwall :%5f, floorywall :%5f\n", all->floceil.currentdist, all->floceil.coeff, all->floceil.floorxwall, all->floceil.floorywall);
	return (text->data[(int)(all->floceil.currentfloory + text->w * all->floceil.currentfloorx)]);
}

int		ft_texture(t_cub *all)
{
	if (all->info.side == 1)
	{
		if (all->info.raydiry > 0)
			return (ft_color_texture(all, all->minilibx.west.data, &all->minilibx.west, 0));
		//return (3407667);//west
		if (all->info.raydiry < 0)
			return (ft_color_texture(all, all->minilibx.east.data, &all->minilibx.east, 0));
		//return (10027008);//east
	}
	else
	{
		if (all->info.raydirx > 0)
			return (ft_color_texture(all, all->minilibx.south.data, &all->minilibx.south, 1));
		//return (13369497);//south
		if (all->info.raydirx < 0)
			return (ft_color_texture(all, all->minilibx.north.data, &all->minilibx.north, 1));
		//return (16750899);//north
	}
	return (0);
}

int		ft_color_texture(t_cub *all, int *ptr, t_text *text, int i)
{
	int line;
	int column;
	double	tmp;

	line = (((double)all->draw.y - (double)((-(all->draw.hauteurligne) / 2) + (all->res_y / 2))) / (double)all->draw.hauteurligne * 100.0) * (double)((double)text->h / 100.0);
	//line = ((double)all->draw.drawstart - (double)all->res_y / 2.0 + (double)all->draw.hauteurligne / 2.0) * (double)text->h / (double)all->draw.hauteurligne;
	if (i == 1)
		tmp = (all->info.rayposy + all->info.perpwalldist * all->info.raydiry); 
	if (i == 0)
		tmp = (all->info.rayposx + all->info.perpwalldist * all->info.raydirx); 
	tmp -= floor(tmp);
	column = tmp * (double)text->w;
	//	printf("ptr : %d\n", ptr[column + text->w + line]);
	//	printf("line = %5d, column : %5d, texture->w : %5d\n", line, column, text->w);
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
}
