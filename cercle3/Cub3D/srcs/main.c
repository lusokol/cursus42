/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:09:33 by lusokol           #+#    #+#             */
/*   Updated: 2020/06/26 20:07:41 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_screen(t_cub *all, int x, int *img_ptr)
{
	while (all->draw.ceilling < all->draw.drawstart)
	{
		if (all->rgbc == 1)
			img_ptr[x + all->res_x * all->draw.ceilling++] = all->ceil;
		else
			img_ptr[x + all->res_x * all->draw.ceilling++] = ft_skybox(all, x);
	}
	while (all->draw.floor < all->res_y)
	{
		if (all->rgbf == 1)
			img_ptr[x + all->res_x * all->draw.floor++] = all->flo;
		else
			img_ptr[x + all->res_x * all->draw.floor++] = ft_texture_floor(all,
					&all->minilibx.floor);
	}
	while (all->draw.y < all->draw.drawend)
	{
		img_ptr[x + all->res_x * all->draw.y] = ft_texture(all);
		all->draw.y++;
	}
}

void	cub_next(t_cub *all, int *img_data, int x)
{
	calcul(all, x);
	vecteur_dir(all);
	raycasting(all);
	ft_jump(all);
	calcul2(all);
	ft_calcfloor(all);
	print_screen(all, all->res_x - x - 1, img_data);
	all->info.dist[x] = all->info.perpwalldist;
}

void	cubddd(t_cub *all)
{
	int		x;
	void	*img_ptr;
	int		*img_data;
	int		test1;

	x = -1;
	img_ptr = mlx_new_image(all->minilibx.mlx_ptr, all->res_x, all->res_y);
	img_data = (int*)mlx_get_data_addr(img_ptr, &test1, &test1, &test1);
	ft_calcul_skybox(all);
	while (++x < all->res_x)
		cub_next(all, img_data, x);
	anim_goomba(all);
	print_sprite(all, img_data);
	hud(all, img_data);
	game_over(all, img_data);
	all->minilibx.img_data = img_data;
	if (all->save == 0)
	{
		mlx_put_image_to_window(all->minilibx.mlx_ptr,
				all->minilibx.win_ptr, img_ptr, 0, 0);
		mlx_destroy_image(all->minilibx.mlx_ptr, img_ptr);
	}
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
			if (all->map[j][i] == 'N' || all->map[j][i] == 'S' ||
					all->map[j][i] == 'W' || all->map[j][i] == 'E')
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
	t_cub	*all;
	char	**tab;

	g_begin = clock();
	if (ac < 2 || ac > 3)
		return (ft_printf("Error\nNeed 1 or 2 argument.\n"));
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (ft_printf("Error\nInvalid  argument.\n"));
	tab = create_tab(fd);
	all = ft_fill_struct(tab);
	ft_spawnpoint(all);
	init_struct(all);
	ft_spawnpoint(all);
	all->info.dist = malloc(sizeof(double) * all->res_x);
	all->vit.rot = 0.05;
	all->vit.mvt = 1;
	if (!check_map(all->map))
		exit((ft_printf("Error\nMap invalid\n")) == 0);
	all->map2 = all->map;
	ft_get_map(tab, all);
	if (ac == 3)
		check_ac(av, all);
	ft_mlx_init(all);
}
