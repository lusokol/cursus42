/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:09:33 by lusokol           #+#    #+#             */
/*   Updated: 2020/01/30 17:07:10 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	init_struct(t_cub *all)
{
	all->info.dirX = -1;
	all->info.dirY = 0;
	all->info.planeX = 0;
	all->info.planeY = 1;
}

void	calcul(t_cub *all, int x)
{
	all->info.cameraX = (2 * (double)x / all->res_x) - 1;
	all->info.rayPosX = all->coord.x;
	all->info.rayPosY = all->coord.y;
	all->info.rayDirX = all->info.dirX + (all->info.planeX * all->info.cameraX);
	all->info.rayDirY = all->info.dirY + (all->info.planeY * all->info.cameraX);
	all->info.mapX = (int)(all->info.rayPosX);
	all->info.mapY = (int)(all->info.rayPosY);
	all->info.deltaDistX = sqrt(1 + ((all->info.rayDirY * all->info.rayDirY) / (all->info.rayDirX * all->info.rayDirX)));
	all->info.deltaDistY = sqrt(1 + ((all->info.rayDirX * all->info.rayDirX) / (all->info.rayDirY * all->info.rayDirY)));
}

void	vecteur_dir(t_cub *all)
{
	if (all->info.rayDirX < 0){
		all->info.stepX = -1;
		all->info.sideDistX = (all->info.rayPosX - all->info.mapX) * all->info.deltaDistX;
	}
	else{
		all->info.stepX = 1;
		all->info.sideDistX = (all->info.mapX + 1.0 - all->info.rayPosX) * all->info.deltaDistX;
	}
	if (all->info.rayDirY < 0){
		all->info.stepY = -1;
		all->info.sideDistY = (all->info.rayPosY - all->info.mapY) * all->info.deltaDistY;
	}
	else{
		all->info.stepY = 1;
		all->info.sideDistY = (all->info.mapY + 1.0 - all->info.rayPosY) * all->info.deltaDistY;
	}
}

void	rayCasting(t_cub *all)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (all->info.sideDistX < all->info.sideDistY) {
			all->info.sideDistX += all->info.deltaDistX;
			all->info.mapX += all->info.stepX;
			all->info.side = 0;
		}
		else {
			all->info.sideDistY += all->info.deltaDistY;
			all->info.mapY += all->info.stepY;
			all->info.side = 1;
		}
		if ((all->map)[all->info.mapX][all->info.mapY] == '1') {
			hit=1;
		}
	}
	if (all->info.side == 0) {
		all->info.perpWallDist = fabs(((all->info.mapX - all->info.rayPosX) + ((1 - all->info.stepX) / 2)) / all->info.rayDirX);
	} else {
		all->info.perpWallDist = fabs(((all->info.mapY - all->info.rayPosY) + ((1 - all->info.stepY) / 2)) / all->info.rayDirY);
	}
}

void	calcul2(t_cub *all)
{
	all->draw.hauteurLigne = abs((int)(all->res_y / all->info.perpWallDist));
	all->draw.drawStart = (-(all->draw.hauteurLigne) / 2) + (all->res_y / 2);
	all->draw.drawEnd = (all->draw.hauteurLigne / 2) + (all->res_y / 2);
	if (all->draw.drawStart < 0) {
		all->draw.drawStart = 0;
	}
	if (all->draw.drawEnd >= all->res_y) {
		all->draw.drawEnd = all->res_y - 1;
	}
	all->draw.y = all->draw.drawStart;
	all->draw.ceilling = 0;
	all->draw.floor = all->draw.drawEnd;
}

void	print_screen(t_cub *all, int x)
{
	int color;

	while (all->draw.ceilling < all->draw.drawStart)
		mlx_pixel_put(all->minilibx.mlx_ptr, all->minilibx.win_ptr, (int)x, all->draw.ceilling++, 16711680);
	while (all->draw.floor < all->res_y)
		mlx_pixel_put(all->minilibx.mlx_ptr, all->minilibx.win_ptr, (int)x, all->draw.floor++, 16777215);
	while (all->draw.y < all->draw.drawEnd) {
		color = 65280;
		if (all->info.side == 1) {
			color = 255;
		}
		mlx_pixel_put(all->minilibx.mlx_ptr, all->minilibx.win_ptr, (int)x, (int)all->draw.y, color);
		all->draw.y++;
	}
}

void	cubddd(t_cub *all)
{
	int		x;
	void	*img_ptr;

	x = 0;
	init_struct(all);
	while (x <= all->res_x)
	{
		img_ptr = mlx_new_image(all->minilibx.mlx_ptr, all->res_x, all->res_y);
		calcul(all, x);
		vecteur_dir(all);
		rayCasting(all);
		calcul2(all);
		print_screen(all, x);
		mlx_destroy_image(img_ptr);
		x++;
	}
}



















int		deal_key(int key, void *param)
{
	t_cub	*all;

	all = param;
	printf("key : %d\n", key);
	if (key == 13) {
		all->coord.x -= 0.5;
//		test(all->minilibx.mlx_ptr, all->minilibx.win_ptr, param);
		cubddd(all);
	}
	(void)param;
	return (0);
}

int main(int ac, char **av)
{
	int		fd;
	//int		i;
	t_cub	*all;
	int		res;

	if (ac != 2)
		return (printf("Need 1 argument\n"));
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (printf("Invalid  argument\n"));
	all = ft_fill_struct(create_tab(fd));
	all->coord.x = 12.0;
	all->coord.y = 3.0;
	res = check_map(all->map);

	all->minilibx.mlx_ptr = mlx_init();
	all->minilibx.win_ptr = mlx_new_window(all->minilibx.mlx_ptr, all->res_x, all->res_y, "Cub3D");
	//test(all->minilibx.mlx_ptr, all->minilibx.win_ptr, all);
	cubddd(all);
	mlx_key_hook(all->minilibx.win_ptr, deal_key, all);

	mlx_loop(all->minilibx.mlx_ptr);
}
