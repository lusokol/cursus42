/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:18:32 by lusokol           #+#    #+#             */
/*   Updated: 2020/09/30 18:04:38 by macbookpro       ###   ########.fr       */
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
# include "../libft/libft.h"
# include "../libft/libftprintf.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include <time.h>

clock_t g_begin;

typedef struct		s_bmp
{
	int				size;
	char			*img;
	unsigned char	header[14];
	unsigned char	info[40];
	unsigned char	pad[3];
	int				color;
	int				fd;
}					t_bmp;

typedef struct		s_texture
{
	int				alive;
	int				col;
	int				sens;
	int				spr;
	double			size;
	int				anim;
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

typedef struct		s_number
{
	t_text			num[10];
}					t_number;

typedef struct		s_goomba
{
	int				safe;
	int				cankill;
	int				frame;
	t_text			frame1;
	t_text			frame2;
	t_text			frame3;
	t_text			frame4;
}					t_goomba;

typedef struct		s_sprite
{
	t_text			*tab;
	t_goomba		goomba;
	int				n;
	int				nbr;
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
	t_text			sprite1;
	t_text			sprite2;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	void			*img_ptr;
	int				*img_data;
}					t_mlx;

typedef struct		s_coord
{
	double			x;
	double			y;
	double			z;
}					t_coord;

typedef struct		s_draw
{
	double			jump;
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
	int				exit;
	double			j;
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
	double			*dist;
}					t_info;

typedef struct		s_vit
{
	double			rot;
	double			mvt;
}					t_vit;

typedef struct		s_hud
{
	t_text			cv;
	t_text			cp;
	t_text			coin;
	t_text			fin;
	t_number		number;
	int				hp;
	int				gold;
	int				drawstart;
	int				drawend;
}					t_hud;

typedef struct		s_cub
{
	int				res_y;
	int				res_x;
	int				rgbc;
	int				rgbf;

	char			*north;
	char			*south;
	char			*west;
	char			*east;

	char			*sprite;
	char			*sprite1;
	char			*sprite2;
	void			*floor;
	int				flo;
	void			*ceilling;
	int				ceil;
	int				save;

	char			**map;
	char			**map2;
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
	t_hud			hud;
}					t_cub;

void				calcul(t_cub *all, int x);
void				check_ac(char **av, t_cub *all);
void				ft_bmp(t_cub *all);
void				vecteur_dir(t_cub *all);
void				raycasting(t_cub *all);
void				ft_mlx_init(t_cub *all);
int					ft_spawnlettre(t_cub *all, int i, int j, char a);
void				sprite_pos(t_cub *all, int n);
int					gold_next(t_cub *all, int img);
void				ft_take_sprite_next(t_cub *all, int n);
void				ft_take_res(t_cub *all, char *str);
void				*path(t_cub *all, void *comp, void *comp2);
void				*info(t_cub *all, char *str, int i, int type);
int					start_check(char **str);
void				fill_map(char **map);
int					check_point(char **map);
double				sort_calc(t_cub *all, int n);
void				sprite_dim(t_cub *all);
void				text_null(t_cub *all);
void				ft_check_info(char **str, int i, t_cub *all);
void				check_fail(int i, int j, char **map);
int					missing_arg(t_cub *all);
void				init_struct(t_cub *all);
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
int					ft_is_sprite(char a);
void				sprite_pars(t_cub *all);
t_text				take_text(t_cub *all, char *text_addr);
void				ft_sort_sprite(t_cub *all, int nbr);
void				hud(t_cub *all, int *img_data);
void				anim_goomba(t_cub *all);
void				check_colision(t_cub *all, double x, double y);
int					kill_goomba(t_cub *all, int n);
void				ft_exit(t_cub *all);
void				game_over(t_cub *all, int *img_data);
t_cub				*ft_get_map(char **str, t_cub *all);

#endif
