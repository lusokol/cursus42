/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmpbis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 16:30:45 by lusokol           #+#    #+#             */
/*   Updated: 2020/06/26 18:01:21 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initmlx(t_cub *all)
{
	all->minilibx.mlx_ptr = mlx_init();
	init_text(all);
	sprite_pars(all);
	if (!(all->minilibx.img_ptr = mlx_new_image(all->minilibx.mlx_ptr,
					all->res_x, all->res_y)))
	{
		ft_printf("Error\nmlx_new_image");
		exit(0);
	}
	if (!(all->minilibx.img_data =
				(int *)mlx_get_data_addr(all->minilibx.img_ptr,
					&all->minilibx.bits_per_pixel,
					&all->minilibx.size_line, &all->minilibx.endian)))
	{
		ft_printf("Error\nmlx_get_data_addr");
		exit(0);
	}
}

void	ft_bmpinit(t_cub *all)
{
	initmlx(all);
	cubddd(all);
	ft_bmp(all);
	exit(0);
}

void	check_ac(char **av, t_cub *all)
{
	if (ft_strncmp(av[2], "--save", 7) == 0)
	{
		all->save = 1;
		ft_bmpinit(all);
		exit(0);
	}
	else
	{
		ft_printf("Error\n\"%s\" isn't a valid argument.", av[2]);
		exit(0);
	}
}
