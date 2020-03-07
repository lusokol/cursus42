/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:18:32 by lusokol           #+#    #+#             */
/*   Updated: 2020/03/07 16:51:43 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>
# include <time.h>

clock_t g_begin;

typedef struct		s_sprite
{
	t_text			
	double			spritex;
	double			spritey;
	double			invdet;
	double			transformx;
	double			transformy;
	int				spritescreenx;
	int				spriteheight;
	int				spritewidth;
	int				drawstarty;
	int				drawendy;
	int				drawstartx;
	int				drawendx;
	clock_t			end;
	double			millis;
	int				coeffx;
	int				coeffy;
}					t_sprite;

typedef struct		s_skybox
{
	double			coeffx;
	double			coeffy;
	double			i;
	int				rot;
	int				ok;
}					t_skybox;

typedef struct		s_floor
{
	double			currentdist;
	double			coeff;
	double			currentfloorx;
	double			currentfloory;
	double			floorxwall;
	double			floorywall;
	double			wallx;
}					t_floor;

typedef struct		s_texture
{
	double			x;
	double			y;
	void			*ptr;
	int				*data;
	int				w;
	int				h;
	int				line_size;
	int				bpp;
	int				endian;
}					t_text;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_text			north;
	t_text			south;
	t_text			west;
	t_text			east;
	t_text			floor;
	t_text			skybox;
	t_text			sprite;
}					t_mlx;

typedef struct		s_coord
{
	double			x;
	double			y;
	double			z;
}					t_coord;

typedef struct		s_draw
{
	int				drawstart;
	int				drawend;
	int				hauteurligne;
	int				y;
	int				ceilling;
	int				floor;
}					t_draw;

typedef struct		s_key
{
	int				w;
	int				a;
	int				s;
	int				d;
	int				fg;
	int				fd;
	double				j;
}					t_key;

typedef struct		s_info
{
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			camerax;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	double			deltadistx;
	double			deltadisty;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	int				stepx;
	int				stepy;
	int				side;
	double			perpwalldist;
}					t_info;

typedef struct		s_vit
{
	double			rot;
	double			mvt;
}					t_vit;

typedef struct		s_cub
{
	int				res_y;
	int				res_x;

	char			*north;
	char			*south;
	char			*west;
	char			*east;

	char			*sprite;
	char			*floor;
	char			*ceilling;

	char			**map;
	t_coord			coord;
	t_mlx			minilibx;
	t_info			info;
	t_draw			draw;
	t_vit			vit;
	t_key			key;
	t_floor			floceil;
	t_skybox		skybox;
	t_sprite		spr;
	t_text			pars;
}					t_cub;

char				**create_tab(int fd);
t_cub				*ft_fill_struct(char **str);
int					get_next_line(int fd, char **line);
int					check_map(char **map);
void				move_w(t_cub *all);
void				move_a(t_cub *all);
void				move_s(t_cub *all);
void				move_d(t_cub *all);
int					key_push(int key, t_cub *all);
int					key_release(int key, t_cub *all);
int					deal_key(t_cub *all);
void				move_fg(t_cub *all);
void				move_fd(t_cub *all);
void				cubddd(t_cub *all);
int					ft_texture(t_cub *all);
int					ft_color_texture(t_cub *all, int *ptr, t_text *text, int i);
void				init_text(t_cub *all);
int					ft_texture_floor(t_cub *all, t_text *text);
int					ft_skybox(t_cub *all, int x);
void				ft_calcul_skybox(t_cub *all);
void				ft_calcfloor(t_cub *all);
void				print_sprite(t_cub *all, int *img_data);
void				ft_jump(t_cub *all);
void				calcul2(t_cub *all);

#endif