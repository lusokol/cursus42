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

void	print_screen(t_cub *all, int x, int *img_ptr)
{
	//int color;

	img_ptr[0] = 1;
	while (all->draw.ceilling < all->draw.drawStart)
		img_ptr[x + all->res_x * all->draw.ceilling++] = 16711680;
	while (all->draw.floor < all->res_y)
		img_ptr[x + all->res_x * all->draw.floor++] = 16777215;
	while (all->draw.y < all->draw.drawEnd) {
		if (all->info.side == 1) {
			img_ptr[x + all->res_x * all->draw.y] = 255;
		}
		else
			img_ptr[x + all->res_x * all->draw.y] = 65280;
		all->draw.y++;
	}
}

void	cubddd(t_cub *all)
{
	int		x;
	void	*img_ptr;
	int	*img_data;
	int	test1;
	int	test2;
	int	test3;

	x = 0;
	img_ptr = mlx_new_image(all->minilibx.mlx_ptr, all->res_x, all->res_y);
	img_data = (int*)mlx_get_data_addr(img_ptr, &test1, &test2, &test3);
	while (x <= all->res_x)
	{
		calcul(all, x);
		vecteur_dir(all);
		rayCasting(all);
		calcul2(all);
		print_screen(all, x, img_data);
		//printf("%d\n%d\n%d\n", test1, test2, test3);
		x++;
	}
	mlx_put_image_to_window(all->minilibx.mlx_ptr, all->minilibx.win_ptr, img_ptr, 0, 0);
	mlx_destroy_image(all->minilibx.mlx_ptr, img_ptr);
}



















int		deal_key(int key, void *param)
{
	t_cub	*all;
	double test;

	all = param;
	printf("key : %d\n", key);
	if (key == 122 && all->map[(int)(all->coord.x - 0.101)][(int)(all->coord.y)] != '1')
	{
		all->coord.x += all->info.dirX / 10;
		all->coord.y += all->info.dirY / 10;
	}
	if (key == 115 && all->map[(int)(all->coord.x + 0.101)][(int)(all->coord.y)] != '1')
	{
		all->coord.x -= all->info.dirX / 10;
		all->coord.y -= all->info.dirY / 10;
	}
	if (key == 113 && all->map[(int)(all->coord.x)][(int)(all->coord.y + 0.101)] != '1')
	{
		all->coord.x -= all->info.planeX / 10;
		all->coord.y -= all->info.planeY / 10;
	}
	if (key == 100 && all->map[(int)(all->coord.x)][(int)(all->coord.y - 0.101)] != '1')
	{
		all->coord.x += all->info.planeX / 10;
		all->coord.y += all->info.planeY / 10;
	}
	if (key == 65361)
	{
		test = all->info.dirX;
		all->info.dirX = all->info.dirX * cos(-all->vit.rot) - all->info.dirY * sin(-all->vit.rot);
		all->info.dirY = test * sin(-all->vit.rot) + all->info.dirY * cos(-all->vit.rot);
		all->info.planeX = -0.66 * all->info.dirY;
		all->info.planeY = 0.66 * all->info.dirX;
	}
	if (key == 65363)
	{
		test = all->info.dirX;
		all->info.dirX = all->info.dirX * cos(all->vit.rot) - all->info.dirY * sin(all->vit.rot);
		all->info.dirY = test * sin(all->vit.rot) + all->info.dirY * cos(all->vit.rot);
		all->info.planeX = -0.66 * all->info.dirY;
		all->info.planeY = 0.66 * all->info.dirX;
	}
	cubddd(all);
	(void)param;
	return (0);
}

int main(int ac, char **av)
{
	int		fd;
	//int		i;
	t_cub	*all;
	//int		res;

	if (ac != 2)
		return (printf("Need 1 argument\n"));
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (printf("Invalid  argument\n"));
	all = ft_fill_struct(create_tab(fd));
	init_struct(all);
	all->coord.x = 12.0;
	all->coord.y = 3.0;
	all->vit.rot = 0.05;
	/*res = */check_map(all->map);

	all->minilibx.mlx_ptr = mlx_init();
	all->minilibx.win_ptr = mlx_new_window(all->minilibx.mlx_ptr, all->res_x, all->res_y, "Cub3D");
	//test(all->minilibx.mlx_ptr, all->minilibx.win_ptr, all);
	cubddd(all);
	mlx_key_hook(all->minilibx.win_ptr, deal_key, all);

	mlx_loop(all->minilibx.mlx_ptr);
}
