/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:09:33 by lusokol           #+#    #+#             */
/*   Updated: 2020/03/11 19:39:56 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct(t_cub *all)
{
	all->info.planex = -0.66 * all->info.diry;
	all->info.planey = 0.66 * all->info.dirx;
	all->key.w = 0;
	all->key.a = 0;
	all->key.s = 0;
	all->key.d = 0;
	all->key.fd = 0;
	all->key.fg = 0;
	all->key.j = 0;
	all->coord.z = 0;
	all->spr.nbr = 0;
	all->hud.hp = 3;
	all->hud.gold = 0;
	all->spr.goomba.frame = 1;
	all->spr.goomba.safe = 0;
	all->spr.goomba.cankill = 0;
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
	//all->draw.jump = ((double)all->draw.hauteurligne / 3.0) * (all->coord.z * 10);
	all->draw.drawstart = (int)(-(all->draw.hauteurligne) * (0.5 - all->coord.z) + (int)(all->res_y * (0.5 + all->coord.z)))/* + all->draw.jump*/;
	all->draw.drawend = (int)((all->draw.hauteurligne * (0.5 + all->coord.z)) + (int)(all->res_y * (0.5 + all->coord.z)))/* + all->draw.jump*/;
	//printf("z : %f\n", all->coord.z);
	if (all->draw.drawstart < 0) {
		all->draw.drawstart = 0;
	}
	if (all->draw.drawend >= all->res_y) {
		all->draw.drawend = all->res_y;
	}
	all->draw.drawstart = abs(all->draw.drawstart);
	all->draw.drawend = abs(all->draw.drawend);
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
		//img_ptr[x + all->res_x * all->draw.floor++] = 123456;
		img_ptr[x + all->res_x * all->draw.floor++] = ft_texture_floor(all, &all->minilibx.floor);
	//	img_ptr[x + all->res_x * all->draw.floor++] = 16777215;
	while (all->draw.y < all->draw.drawend) {
		img_ptr[x + all->res_x * all->draw.y] = ft_texture(all);
//		img_ptr[x + all->res_x * all->draw.y] = 456123;
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
//	if (all->skybox.ok)
	ft_calcul_skybox(all);
	while (x < all->res_x)
	{
		calcul(all, x);
		vecteur_dir(all);
		rayCasting(all);
		ft_jump(all);
		calcul2(all);
		ft_calcfloor(all);
		print_screen(all, all->res_x - x - 1, img_data);
		//printf("%d\n%d\n%d\n", test1, test2, test3);
		x++;
	}
	anim_goomba(all);
	print_sprite(all, img_data);
	hud(all, img_data);
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
	all->spr.nbr = 0;
	while (all->map[j])
	{
		i = 0;
		while (all->map[j][i])
		{
			if (all->map[j][i] == 'N' || all->map[j][i] == 'S' || all->map[j][i] == 'W' || all->map[j][i] == 'E')
				ft_spawnlettre(all, i, j, all->map[j][i]);
			if (ft_is_sprite(all->map[j][i]))
				all->spr.nbr++;
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

	g_begin = clock();
	if (ac != 2)
		return (printf("Need 1 argument\n"));
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (printf("Invalid  argument\n"));
	all = ft_fill_struct(create_tab(fd));
	ft_spawnpoint(all);
	init_struct(all);
	ft_spawnpoint(all);
	all->vit.rot = 0.05;
	all->vit.mvt = 1;
	/*res = */check_map(all->map);

	int i = 0;

	while (all->map[i])
		printf("%s\n", all->map[i++]);
	all->minilibx.mlx_ptr = mlx_init();
	init_text(all);
	sprite_pars(all);
	all->minilibx.win_ptr = mlx_new_window(all->minilibx.mlx_ptr, all->res_x, all->res_y, "Cub3D");
	cubddd(all);
	mlx_hook(all->minilibx.win_ptr, 2, (1L << 0), &key_push, all);
	mlx_hook(all->minilibx.win_ptr, 3, (1L << 1), &key_release, all);
	mlx_loop_hook(all->minilibx.mlx_ptr, &deal_key, all);
	mlx_loop(all->minilibx.mlx_ptr);
}
