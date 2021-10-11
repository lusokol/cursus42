/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 11:34:02 by macbookpro        #+#    #+#             */
/*   Updated: 2021/10/11 17:19:54 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../minilibx/mlx.h"

/* zoom in and out in percent (1-99) */
# define ZOOM 10

/* screen size in pixel */
# define SCREEN_SIZE 300

/* key number for key binding */
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define ITERATION_MORE 35
# define ITERATION_LESS 41
# define SCROLL_IN 4
# define SCROLL_OUT 5
# define ESCAPE 53

/* Color and size of gradient for fractals */
/* Mandelbrot : */
# define COLOR1 0xFFB200
# define COLOR2 0xF53535
# define COLOR3 0x2513B9
# define SIZE1 10

/* julia : */
# define COLOR4 0xF30000
# define COLOR5 0x0AFFEC
# define COLOR6 0xFBFF00
# define SIZE2 10

/* burningship : */
# define COLOR7 0x1D0100
# define COLOR8 0xEC4D09
# define COLOR9 0xffeb00
# define SIZE3 10

/* error message color */
# define RED "\e[38;5;196m"
# define ORA "\e[38;5;208m"
# define BLU "\e[38;5;45m"
# define END "\e[0m"

typedef struct s_all
{
	int			x;
	int			y;
	long double	c_r;
	long double	c_i;
	long double	z_r;
	long double	z_i;
	long double	x1;
	long double	x2;
	long double	y1;
	long double	y2;
	long double	zoom_x;
	long double	zoom_y;
	int			iteration_max;
}	t_all;

typedef struct s_color
{
	int		hex;
	int		r;
	int		g;
	int		b;
	int		size;
}	t_color;

typedef struct s_tmp
{
	int	r;
	int	g;
	int	b;
}	t_tmp;

/*
** variable fractal		1 = mandelbrot
** in the s_data		2 = julia
** structure			3 = burningship
*/

typedef struct s_data
{
	t_all	*all;
	t_color	*color;
	t_tmp	tmp;
	int		c1;
	int		c2;
	int		c3;
	int		cs;
	int		fractal;
	int		size;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_data;

void		myalgo(t_data *img);
int			my_rgb(int r1, int g1, int b1);
int			key_push(int button, t_data *ptr);
void		mandelbrot(int x, int y, t_data *img);
void		my_mlx_pixelput(t_data *img, int x, int y, int color);
void		zoom(t_data *img, float zoom);
int			click_detect(int button, int x, int y, void *ptr);
int			key_detect(int x, int y, t_data *img);
int			my_rgb(int r1, int g1, int b1);
void		move_plan(int button, t_data *img);
void		julia(int x, int y, t_data *img);
void		burningship(int x, int y, t_data *img);
int			ft_strcmp(const char *s1, const char *s2);
long double	ft_atof(const char *str);
int			ft_isfloat(char *str);
void		mandelbrot_iteration(t_data *img);
void		julia_iteration(t_data *img);
void		burningship_iteration(t_data *img);
void		create_gradient(t_data *img);
void		rgb_to_hexa(t_color *color);
void		hexa_to_rgb(int hexa, t_color *color);
void		move_plan(int button, t_data *img);
int			check_error(int ac, char **av);
void		ft_exit(int exit_code, t_data *img);

#endif