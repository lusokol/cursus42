/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:09:33 by lusokol           #+#    #+#             */
/*   Updated: 2020/03/04 15:40:05 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct(t_cub *all)
{
	//all->info.dirx = -1;
	//all->info.diry = 0;
	all->info.planex = -0.66 * all->info.diry;
	all->info.planey = 0.66 * all->info.dirx;
	all->key.w = 0;
	all->key.a = 0;
	all->key.s = 0;
	all->key.d = 0;
	all->key.fd = 0;
	all->key.fg = 0;
}

void	calcul(t_cub *all, int x)
{
	all->info.camerax = (2 * (double)x / all->res_x) - 1;
	all->info.rayposx = all->coord.x;
	all->info.rayposy = all->coord.y;
	all->info.raydirx = all->info.dirx + (all->info.planex * all->info.camerax);
	all->info.raydiry = all->info.diry + (all->info.planey * all->info.camerax);
	all->info.mapx = (int)(all->info.rayposx);
	all->info.mapy = (int)(all->info.rayposy);
	all->info.deltadistx = sqrt(1 + ((all->info.raydiry * all->info.raydiry) / (all->info.raydirx * all->info.raydirx)));
	all->info.deltadisty = sqrt(1 + ((all->info.raydirx * all->info.raydirx) / (all->info.raydiry * all->info.raydiry)));
}

void	vecteur_dir(t_cub *all)
{
	if (all->info.raydirx < 0){
		all->info.stepx = -1;
		all->info.sidedistx = (all->info.rayposx - all->info.mapx) * all->info.deltadistx;
	}
	else{
		all->info.stepx = 1;
		all->info.sidedistx = (all->info.mapx + 1.0 - all->info.rayposx) * all->info.deltadistx;
	}
	if (all->info.raydiry < 0){
		all->info.stepy = -1;
		all->info.sidedisty = (all->info.rayposy - all->info.mapy) * all->info.deltadisty;
	}
	else{
		all->info.stepy = 1;
		all->info.sidedisty = (all->info.mapy + 1.0 - all->info.rayposy) * all->info.deltadisty;
	}
}

void	rayCasting(t_cub *all)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (all->info.sidedistx < all->info.sidedisty) {
			all->info.sidedistx += all->info.deltadistx;
			all->info.mapx += all->info.stepx;
			all->info.side = 0;
		}
		else {
			all->info.sidedisty += all->info.deltadisty;
			all->info.mapy += all->info.stepy;
			all->info.side = 1;
		}
		if ((all->map)[all->info.mapx][all->info.mapy] == '1') {
			hit=1;
		}
	}
	if (all->info.side == 0) {
		all->info.perpwalldist = fabs(((all->info.mapx - all->info.rayposx) + ((1 - all->info.stepx) / 2)) / all->info.raydirx);
	} else {
		all->info.perpwalldist = fabs(((all->info.mapy - all->info.rayposy) + ((1 - all->info.stepy) / 2)) / all->info.raydiry);
	}
}

void	calcul2(t_cub *all)
{
	all->draw.hauteurligne = abs((int)(all->res_y / all->info.perpwalldist));
	all->draw.drawstart = (-(all->draw.hauteurligne) / 2) + (all->res_y / 2);
	all->draw.drawend = (all->draw.hauteurligne / 2) + (all->res_y / 2);
	if (all->draw.drawstart < 0) {
		all->draw.drawstart = 0;
	}
	if (all->draw.drawend >= all->res_y) {
		all->draw.drawend = all->res_y;
	}
	all->draw.y = all->draw.drawstart;
	all->draw.ceilling = 0;
	all->draw.floor = all->draw.drawend;
}

void	print_screen(t_cub *all, int x, int *img_ptr)
{
	while (all->draw.ceilling < all->draw.drawstart)
		img_ptr[x + all->res_x * all->draw.ceilling++] = ft_skybox(all, x);
		//img_ptr[x + all->res_x * all->draw.ceilling++] = 16711680;
	while (all->draw.floor < all->res_y)
		img_ptr[x + all->res_x * all->draw.floor++] = ft_texture_floor(all, &all->minilibx.floor);
		//img_ptr[x + all->res_x * all->draw.floor++] = 16777215;
	while (all->draw.y < all->draw.drawend) {
//		if (all->info.side == 1) {
		img_ptr[x + all->res_x * all->draw.y] = ft_texture(all);//255;
//		}
//		else
//			img_ptr[x + all->res_x * all->draw.y] = 65280;
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
	while (x < all->res_x)
	{
		calcul(all, x);
		vecteur_dir(all);
		rayCasting(all);
		calcul2(all);
		print_screen(all, all->res_x - x - 1, img_data);
		//printf("%d\n%d\n%d\n", test1, test2, test3);
		x++;
	}
	mlx_put_image_to_window(all->minilibx.mlx_ptr, all->minilibx.win_ptr, img_ptr, 0, 0);
	mlx_destroy_image(all->minilibx.mlx_ptr, img_ptr);
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
	printf("i = %d\nj = %d\n", i, j);
	all->coord.x = j + 0.5;
	all->coord.y = i + 0.5;
	return (1);
}

void	ft_spawnpoint(t_cub *all)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (all->map[j])
	{
		i = 0;
		while (all->map[j][i])
		{
			if (all->map[j][i] == 'N' || all->map[j][i] == 'S' || all->map[j][i] == 'W' || all->map[j][i] == 'E')
				ft_spawnlettre(all, i, j, all->map[j][i]);
			i++;
		}
		j++;
	}
}

int		main(int ac, char **av)
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
	ft_spawnpoint(all);
	init_struct(all);
	all->vit.rot = 0.05;
	/*res = */check_map(all->map);

	int i = 0;

	while (all->map[i])
	{
		printf("%s\n", all->map[i++]);
	}
	all->minilibx.mlx_ptr = mlx_init();
	init_text(all);
	printf("x : %f\ny : %f\n\n", all->coord.x, all->coord.y);
	all->minilibx.win_ptr = mlx_new_window(all->minilibx.mlx_ptr, all->res_x, all->res_y, "Cub3D");
	cubddd(all);
	mlx_hook(all->minilibx.win_ptr, 2, (1L << 0), &key_push, all);
	mlx_hook(all->minilibx.win_ptr, 3, (1L << 1), &key_release, all);
	mlx_loop_hook(all->minilibx.mlx_ptr, &deal_key, all);
	mlx_loop(all->minilibx.mlx_ptr);
}
