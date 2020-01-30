/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:09:33 by lusokol           #+#    #+#             */
/*   Updated: 2020/01/30 13:29:43 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	ft_jouet(void *mlx_ptr, void *win_ptr, t_cub *all)
{
	int x;
	int y;
	int a;
	int b;

	x = 0;
	y = 0;
	while (x < 1000)
	{
		a = x;
		b = y;
		while (a < 1000)
			mlx_pixel_put(mlx_ptr, win_ptr, a++, b++, all->floor);
		x++;
	}
}


void	test(void *mlx_ptr, void *win_ptr, t_cub *all)
{
	double posX = all->coord.x; //12
	double posY = all->coord.y; //3

	// vecteur de direction
	double dirX = -1;
	double dirY = 0;

// vecteur du plan de projection
	double planeX=0;
	double planeY=1;

// taille de la projection
	int w = all->res_x;
	int h = all->res_y;

	int x = 0;
//Position de départ et direction du rayon
	double cameraX;// position de la colonne par rapport au centre de l’écran
	double rayPosX;// position de départ du rayon sur X
	double rayPosY;// position de départ du rayon sur Y
	double rayDirX;// direction du rayon sur X
	double rayDirY;// direction du rayon sur Y

	double deltaDistX;
	double deltaDistY;

	while (x <= w)
	{
		cameraX = (2 * (double)x / w) - 1;
		rayPosX = posX;
		rayPosY = posY;
		rayDirX = dirX + (planeX * cameraX);
		rayDirY = dirY + (planeY * cameraX);

//		printf("cameraX : %f\n", cameraX);
//		printf("dirX : %f, dirY : %f\n", dirX, dirY);

		//case de la camera
		int mapX = (int)rayPosX;
		int mapY = (int)rayPosY;

		//longueur rayon
		double sideDistX;
		double sideDistY;

		//longueur rayon entre chaque intersection
		deltaDistX = sqrt(1 + ((rayDirY * rayDirY) / (rayDirX * rayDirX)));
		deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));

/*		printf("deltaDistX : %f\n", deltaDistX);
		printf("deltaDistY : %f\n", deltaDistY);
		printf("rayDirX    : %f\n", rayDirX);
		printf("rayDirY    : %f\n", rayDirY);*/

		//direction vecteur X/Y
		int stepX;
		int stepY;

		int hit = 0; //rayon touche un mur ou non
		int side; //orientation mur

		double perpWallDist; //dist corrigee du rayon

		if (rayDirX < 0){
			stepX = -1; // vecteur de direction
			sideDistX = (rayPosX - mapX) * deltaDistX;// distance
		}
		else{
			stepX = 1;
			sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX;
		}
		if (rayDirY < 0){
			stepY = -1;
			sideDistY = (rayPosY - mapY) * deltaDistY;
		}
		else{
			stepY = 1;
			sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY;
		}
/*		printf("sideDistX : %f\n", sideDistX);
		printf("sideDistY : %f\n", sideDistY);*/
		//printf("stepX : %d\n", stepX);
		//printf("stepY : %d\n", stepY);
		while (hit == 0)
		{
			//Passe à la case suivante sur X ou Y
			if (sideDistX < sideDistY) {
				sideDistX += deltaDistX;// agrandis le rayon
				mapX += stepX;// prochaine case ou case précédente sur X
				side = 0;// orientation du mur
			}
			else {
				sideDistY += deltaDistY;// agrandis le rayon
					mapY += stepY;// prochaine case ou case précédente sur Y
				side = 1;// orientation du mur
			}
			// si le rayon rencontre un mur
			if ((all->map)[mapX][mapY] == '1') {
				hit=1;// stoppe la boucle 
			}
		}
		// Calcule la distance corrigée pour la projection
		if (side == 0) {
			perpWallDist = fabs(((mapX - rayPosX) + ((1 - stepX) / 2)) / rayDirX);
		} else {
			perpWallDist = fabs(((mapY - rayPosY) + ((1 - stepY) / 2)) / rayDirY);
		}
//		printf("perpwalldist : %f\n", perpWallDist);
//		printf("sideDistX : %f\n", sideDistX);
//		printf("sideDistY : %f\n", sideDistY);
//		printf("deltaDistX : %f\n", deltaDistX);
//		printf("deltaDistY : %f\n", deltaDistY);
//		printf("raydirY      : %d\n", rayDirY);
//		printf("raydirX      : %d\n", rayDirX);
//		printf("mapX   : %d\n", mapX);
//		printf("mapY   : %f\n", mapY);
//		printf("rayPosX   : %f\n", rayPosX);
//		printf("rayPosY   : %f\n", rayPosY);
//		printf("stepX   : %d\n", stepX);
//		printf("stepY   : %d\n", stepY);
//		printf("side         : %d\n", side);
//		printf("calcul  : %f\n", fabs(((mapX - rayPosX + (1 - stepX)) / 2) / rayDirX));
//		perpWallDist = 3;
		//Calcule la hauteur de la ligne à tracer
		int hauteurLigne = abs((int)(h / perpWallDist));

		//Calcule les pixels max haut et max bas de la colonne à tracer
		int drawStart = (-hauteurLigne / 2) + (h / 2);
		int drawEnd = (hauteurLigne / 2) + (h / 2);

		// limite les zones de tracé à l'écran uniquement
		if (drawStart < 0) {
			drawStart = 0;
		}
		if (drawEnd >= h) {
			drawEnd = h - 1;
		}
//		printf("perpwalldist : %f\n", perpWallDist);
//		printf("side         : %d\n", side);
//		printf("drawend      : %d\n", drawEnd);
//		printf("drawstart    : %d\n", drawStart);
//		printf("hauteurLigne : %d\n", hauteurLigne);
//		printf("h            : %d\n", h);
//		printf("rayDirY      : %d\n", rayDirY);
//		printf("rayDirX      : %d\n", rayDirX);
//
		// tracer la colonne
		int y=drawStart;
		int ceilling;
		int floor;

		ceilling = 0;
		floor = drawEnd;
		while (ceilling < drawStart)
			mlx_pixel_put(mlx_ptr, win_ptr, (int)x, ceilling++, 16711680);
		while (floor < h)
			mlx_pixel_put(mlx_ptr, win_ptr, (int)x, floor++, 16777215);
		while (y < drawEnd) {
			double color = 65280;// couleur du pixel pour un mur Nord/Sud
		if (side == 1) {
			color = 255;// couleur du pixel pour un mur Est/Ouest
		}
		mlx_pixel_put(mlx_ptr, win_ptr, (int)x, (int)y, (int)color);//trace le pixel
		y++;// incrémente la position Y du prochain pixel à tracer
		}
		printf("x : %d\n", x);
		x++;
	}
	printf("Done !\n");
}

int		deal_key(int key, void *param)
{
	t_cub	*all;

	all = param;
	printf("key : %d\n", key);
	if (key == 13) {
		all->coord.x -= 0.5;
		test(all->minilibx.mlx_ptr, all->minilibx.win_ptr, param);
	}
	(void)param;
	return (0);
}

int main(int ac, char **av)
{
	int		fd;
	//int		i;
	t_cub	*all;
	int		res;

	if (ac != 2)
		return (printf("Need 1 argument\n"));
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (printf("Invalid  argument\n"));
	all = ft_fill_struct(create_tab(fd));
	all->coord.x = 12.0;
	all->coord.y = 3.0;
	res = check_map(all->map);

	all->minilibx.mlx_ptr = mlx_init();
	all->minilibx.win_ptr = mlx_new_window(all->minilibx.mlx_ptr, all->res_x, all->res_y, "Cub3D");
	test(all->minilibx.mlx_ptr, all->minilibx.win_ptr, all);

	mlx_key_hook(all->minilibx.win_ptr, deal_key, all);

	mlx_loop(all->minilibx.mlx_ptr);

//aff params
	/*
	printf("RX : |%d|\n", all->res_x);
	printf("RY : |%d|\n", all->res_y);
	printf("NO : |%s|\n", all->north);
	printf("SO : |%s|\n", all->south);
	printf("WE : |%s|\n", all->west);
	printf("EA : |%s|\n", all->east);
	printf("S  : |%s|\n", all->sprite);
	printf("F  : |%d|\n", all->floor);
	printf("C  : |%d|\n", all->ceilling);
	*/

//aff map
	
	//i = -1;
	//while (all->map[++i])
	//	printf("%s\n", all->map[i]);
	//(res == 1) ? printf("Map valide.\n") : printf("Map non valide.\n") ;

}
