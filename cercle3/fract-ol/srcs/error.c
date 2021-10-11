/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:58:46 by macbookpro        #+#    #+#             */
/*   Updated: 2021/10/11 17:23:27 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_exit(int exit_code, t_data *img)
{
	if (img->img)
		mlx_destroy_image(img->mlx, img->img);
	if (img->mlx_win)
		mlx_destroy_window(img->mlx, img->mlx_win);
	exit(exit_code);
}

void	print_error(int i, char *str)
{
	printf(RED);
	if (i != 3)
		printf("Invalid argument\nIt must be : ");
	printf(ORA);
	if (i == 1)
		printf("./fract-ol [mandelbrot | julia | burningship]\n");
	else if (i == 2)
		printf("./fract-ol julia [number 1] [number 2]\n");
	else if (i == 3)
	{
		printf(RED);
		printf("Invalid argument : \"%s\"\n", str);
		printf(ORA);
		printf("It must be an ");
		printf(BLU);
		printf("INT");
		printf(ORA);
		printf(" or a ");
		printf(BLU);
		printf("FLOAT\n");
	}
	printf(END);
}

int	check_error(int ac, char **av)
{
	if (ac != 2 && ac != 4)
		print_error(1, av[1]);
	else if (ac == 2 && ft_strcmp(av[1], "mandelbrot") && ft_strcmp(av[1],
			"julia") && ft_strcmp(av[1], "burningship"))
		print_error(1, av[1]);
	else if ((ac == 2 && ft_strcmp(av[1], "julia") == 0) || (ac == 4
			&& ft_strcmp(av[1], "julia")))
		print_error(2, av[1]);
	else if (ac == 4 && ft_strcmp(av[1], "julia") == 0
		&& (ft_isfloat(av[2]) == 0 || ft_isfloat(av[3]) == 0))
	{
		if (ft_isfloat(av[2]) == 0)
			print_error(3, av[2]);
		if (ft_isfloat(av[3]) == 0)
			print_error(3, av[3]);
	}
	else
		return (1);
	return (0);
}
