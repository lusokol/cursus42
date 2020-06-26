/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 16:31:04 by lusokol           #+#    #+#             */
/*   Updated: 2020/06/26 17:32:04 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		set_header(unsigned char *header, int param)
{
	header[0] = (unsigned char)(param);
	header[1] = (unsigned char)(param >> 8);
	header[2] = (unsigned char)(param >> 16);
	header[3] = (unsigned char)(param >> 24);
}

void		imgbmp(t_cub *all, t_bmp *bmp)
{
	int i;
	int j;
	int x;
	int y;

	j = -1;
	while (++j < all->res_y)
	{
		i = -1;
		while (++i < all->res_x)
		{
			x = i;
			y = all->res_y - 1 - j;
			bmp->color = all->minilibx.img_data[x + y * all->res_x];
			write(bmp->fd, &bmp->color, 3);
		}
		i = -1;
		while (++i < (4 - (all->res_x * 3) % 4) % 4)
			write(bmp->fd, &bmp->pad, 1);
	}
}

void		ft_header(t_cub *all, t_bmp *bmp)
{
	int i;

	i = 0;
	while (i < 14)
		bmp->header[i++] = 0;
	bmp->header[0] = 'B';
	bmp->header[1] = 'M';
	bmp->header[10] = 54;
	i = 0;
	while (i < 40)
		bmp->info[i++] = 0;
	bmp->info[0] = 40;
	bmp->info[12] = 1;
	bmp->info[14] = 24;
	i = 0;
	while (i < 3)
		bmp->pad[i++] = 0;
	set_header(&bmp->header[2], bmp->size);
	set_header(&bmp->info[4], all->res_x);
	set_header(&bmp->info[8], all->res_y);
	write(bmp->fd, bmp->header, 14);
	write(bmp->fd, bmp->info, 40);
}

void		ft_bmp(t_cub *all)
{
	t_bmp	bmp;
	int		imgsize;

	imgsize = 3 * all->res_x * all->res_y;
	bmp.size = 54 + imgsize;
	bmp.img = malloc((sizeof(char) * imgsize));
	ft_memset(bmp.img, 0, imgsize);
	bmp.fd = open("img.bmp", O_CREAT | O_WRONLY, S_IRWXU);
	ft_header(all, &bmp);
	imgbmp(all, &bmp);
	free(bmp.img);
	close(bmp.fd);
}
