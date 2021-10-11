/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 11:33:37 by macbookpro        #+#    #+#             */
/*   Updated: 2021/10/11 17:20:21 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	my_mlx_pixelput(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	myalgo(t_data *img)
{
	img->img = mlx_new_image(img->mlx, img->size, img->size);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len,
			&img->endian);
	if (img->fractal == 1)
		mandelbrot_iteration(img);
	else if (img->fractal == 2)
		julia_iteration(img);
	else if (img->fractal == 3)
		burningship_iteration(img);
	mlx_destroy_image(img->mlx, img->img);
	img->img = NULL;
}

void	init_struct(t_data *img, char **av)
{
	img->size = SCREEN_SIZE;
	img->all->iteration_max = 50;
	if (ft_strcmp(av[1], "julia") == 0)
	{
		img->fractal = 2;
		img->all->c_r = ft_atof(av[2]);
		img->all->c_i = ft_atof(av[3]);
	}
	else
	{
		if (ft_strcmp(av[1], "mandelbrot") == 0)
			img->fractal = 1;
		else if (ft_strcmp(av[1], "burningship") == 0)
			img->fractal = 3;
		img->all->c_r = 0;
		img->all->c_i = 0;
	}
	img->all->z_r = 0;
	img->all->z_i = 0;
	img->all->zoom_x = 0;
	img->all->zoom_y = 0;
}

int	main(int ac, char **av)
{
	t_data	img;
	t_all	*all;

	if (check_error(ac, av) == 0)
		return (0);
	all = malloc(sizeof(t_all));
	img.all = all;
	init_struct(&img, av);
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, img.size, img.size, "Fract-ol");
	create_gradient(&img);
	myalgo(&img);
	mlx_hook(img.mlx_win, 6, (1L << 6), &key_detect, &img);
	mlx_hook(img.mlx_win, 4, (1L << 2), &click_detect, &img);
	mlx_hook(img.mlx_win, 2, (1L << 0), &key_push, &img);
	mlx_loop(img.mlx);
}
