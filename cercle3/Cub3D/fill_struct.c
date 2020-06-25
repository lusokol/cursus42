/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:35:29 by lusokol           #+#    #+#             */
/*   Updated: 2020/03/10 14:26:18 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cub	*ft_get_map(char **str, t_cub *all)
{
	int i;
	int j;
	int k;

	i = 0;
	while (str[i] && str[i][0] != '0' && str[i][0] != '1' && str[i][0] != ' ')
		i++;
	j = i;
	while (str[i] && (str[i][0] == '0' || str[i][0] == '1' || str[i][0] == ' '))
		i++;
	all->map = malloc(sizeof(char*) * (i - j + 1));
	k = -1;
	while (++k < (i - j))
		(all->map)[k] = ft_strdup(str[j + k]);
	(all->map)[k] = NULL;
	return (all);
}

char	**create_tab(int fd)
{
	char **str;
	char *tmp;
	char *line;

	tmp = ft_strdup("");
	while (get_next_line(fd, &line) > 0)
	{
		tmp = ft_strjoin(tmp, "\n");
		tmp = ft_strjoin(tmp, line);
		free(line);
	}
	int j = -1;
	printf("str : \"%s\"\n", tmp);
	printf("\n\n\n");
	str = ft_split(tmp, '\n');
	while (str[++j])
			printf("str : \"%s\"\n", str[j]);
	return (str);
}

void	check_res(t_cub *all)
{
	int x;
	int y;

	mlx_get_screen_size(all->minilibx.mlx_ptr, &x, &y);
	if (all->res_x < 500)
		all->res_x = 500;
	if (all->res_y < 500)
		all->res_y = 500;
	if (all->res_x > x)
		all->res_x = x;
	if (all->res_y > y)
		all->res_y = y;
	printf("resx: %d\nresy: %d\n", all->res_x, all->res_y);
}

void	ft_take_res(t_cub *all, char *str)
{
	int i;

	i = 0;
	while (!(ft_isdigit(str[i])))
		i++;
	all->res_x = ft_atoi(str + i);
	while (ft_isdigit(str[i]))
		i++;
	while (!(ft_isdigit(str[i])))
		i++;
	all->res_y = ft_atoi(str + i);
	while (ft_isdigit(str[i]))
		i++;
	if (ft_atoi(str + i) != 0 || !all->res_x || !all->res_x)
	{
		printf("Error\nResolution bad indent.\n");
		ft_exit(all);
	}
	check_res(all);
}

int		ft_take_rgb(char *str)
{
	int res;
	int j;
	int i;
	int rgb;
	int tmp;

	rgb = 2;
	i = 0;
	j = 0;
	res = 0;
	while (str[i])
	{
		while (str[i] && !ft_isdigit(str[i]))
			i++;
		if (ft_isdigit(str[i]))
			j = ft_atoi(str + i);
		while (str[i] && ft_isdigit(str[i]))
			i++;
		tmp = rgb;
		while (tmp--)
			j *= 256;
		rgb--;
		res += j;
	}
	printf("res : %i\n", res);
	return (res);
}

void	*take_info(t_cub *all, char *str, int i, int type)
{
	int j;

	j = 0;
	if (str[j] == ' ')
			j++;
	else
	{
		printf("Error\nMissing space at the argument %d after \"%c\"\n", i + 1, str[-1]);
		ft_exit(all);
	}
	while (str[j] && str[j] == ' ')
			j++;
	if (str[j] == '\n' || str[j] == '\0')
	{
		printf("Error\nMissing argument line %d.\n", i + 1);
		ft_exit(all);
	}
	all->rgbf = (type == 1 && ft_isdigit(str[j])) ? 1 : all->rgbf;
	all->rgbc = (type == 2 && ft_isdigit(str[j])) ? 1 : all->rgbc;
	if (type == 1 && ft_isdigit(str[j]))
		all->flo = ft_take_rgb(&str[j]);
	if (type == 2 && ft_isdigit(str[j]))
		all->ceil = ft_take_rgb(&str[j]);
	return (ft_strdup(&str[j]));
}

void	*ft_add_path(t_cub *all, void *comp, void *comp2)
{
	if (comp == NULL)
		return (comp2);
	else
	{
		printf("Error\nMultiple path.\n");
		ft_exit(all);
	}
	return (0);
}

void	text_null(t_cub *all)
{
	all->north = NULL;
	all->south = NULL;
	all->east = NULL;
	all->west = NULL;
	all->floor = NULL;
	all->ceilling = NULL;
	all->sprite = NULL;
	all->sprite1 = NULL;
	all->sprite2 = NULL;
	all->minilibx.win_ptr = NULL;
	all->rgbc = 0;
	all->rgbf = 0;
}

void	ft_check_info(char **str, int i, t_cub *all)
{
	if (str[i][0] == 'R')
		ft_take_res(all, str[i]);
	else if (str[i][0] == 'N' && str[i][1] == 'O')
		all->north = ft_add_path(all, all->north, take_info(all, str[i] + 2, i, 0));
	else if (str[i][0] == 'S' && str[i][1] == 'O')
		all->south = ft_add_path(all, all->south, take_info(all, str[i] + 2, i, 0));
	else if (str[i][0] == 'W' && str[i][1] == 'E')
		all->west = ft_add_path(all, all->west, take_info(all, str[i] + 2, i, 0));
	else if (str[i][0] == 'E' && str[i][1] == 'A')
		all->east = ft_add_path(all, all->east, take_info(all, str[i] + 2, i, 0));
	else if (str[i][0] == 'S' && str[i][1] != '1' && str[i][1] != '2')
		all->sprite = ft_add_path(all, all->sprite, take_info(all, str[i] + 1, i, 0));
	else if (str[i][0] == 'F')
		all->floor = ft_add_path(all, all->floor, take_info(all, str[i] + 1, i, 1));
	else if (str[i][0] == 'C')
		all->ceilling = ft_add_path(all, all->ceilling, take_info(all, str[i] + 1, i, 2)); 
	else if (str[i][0] == 'S' && str[i][1] == '1')
		all->sprite1 = ft_add_path(all, all->sprite1, take_info(all, str[i] + 2, i, 0));
	else if (str[i][0] == 'S' && str[i][1] == '2')
		all->sprite2 = ft_add_path(all, all->sprite2, take_info(all, str[i] + 2, i, 0));
}

int		missing_arg(t_cub *all)
{
	if (!all->north)
		printf("Missing argument : NO\n");
	else if (!all->south)
		printf("Missing argument : SO\n");
	else if (!all->west)
		printf("Missing argument : WE\n");
	else if (!all->east)
		printf("Missing argument : EA\n");
	else if (!all->ceilling)
		printf("Missing argument : C\n");
	else if (!all->floor)
		printf("Missing argument : F\n");
	else if (!all->sprite)
		printf("Missing argument : S\n");
	else if (!all->sprite1)
		printf("Missing argument : S1\n");
	else if (!all->sprite2)
		printf("Missing argument : S2\n");
	else
		return (1);
	return (0);
}

t_cub	*ft_fill_struct(char **str)
{
	int		i;
	t_cub	*all;

	i = -1;
	if (!(all = malloc(sizeof(t_cub))))
		return (NULL);
	text_null(all);
	while (str[++i] && str[i][0] != ' ' && str[i][0] != '0' && str[i][0] != '1')
		ft_check_info(str, i, all);
	if (!missing_arg(all))
		ft_exit(all);
	return (ft_get_map(str, all));
}
