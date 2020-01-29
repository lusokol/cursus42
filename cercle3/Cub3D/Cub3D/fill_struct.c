/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:35:29 by lusokol           #+#    #+#             */
/*   Updated: 2020/01/29 15:28:46 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

t_cub	*ft_get_map(char **str, t_cub *all)
{
	int i;
	int j;
	int k;

	i = 0;
	while (str[i] && str[i][0] != '0' && str[i][0] != '1')
		i++;
	j = i;
	while (str[i] && (str[i][0] == '0' || str[i][0] == '1'))
		i++;
	all->map = malloc(sizeof(char*) * (i - j + 1));
	k = -1;
	while (++k < (i - j))
		(all->map)[k] = str[j + k];
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
	str = ft_split(tmp, '\n');
	return (str);
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
	all->res_y = ft_atoi(str + i);
//	if (all->res_x < 500)
//		all->res_x = 500;
//	if (all->res_y < 500)
//		all->res_y = 500;
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
	return (res);
}

t_cub	*ft_fill_struct(char **str)
{
	int		i;
	t_cub	*all;

	i = -1;
	if (!(all = malloc(sizeof(t_cub))))
		return (NULL);
	while (str[++i])
	{
		if (str[i][0] == 'R')
			ft_take_res(all, str[i]);
		else if (str[i][0] == 'N' && str[i][1] == 'O')
			all->north = ft_strdup(str[i] + 3);
		else if (str[i][0] == 'S' && str[i][1] == 'O')
			all->south = ft_strdup(str[i] + 3);
		else if (str[i][0] == 'W' && str[i][1] == 'E')
			all->west = ft_strdup(str[i] + 3);
		else if (str[i][0] == 'E' && str[i][1] == 'A')
			all->east = ft_strdup(str[i] + 3);
		else if (str[i][0] == 'S' && str[i][1] != 'O')
			all->sprite = ft_strdup(str[i] + 2);
		else if (str[i][0] == 'F')
			all->floor = ft_take_rgb(str[i] + 2);
		else if (str[i][0] == 'C')
			all->ceilling = ft_take_rgb(str[i] + 2);
	}
	return (ft_get_map(str, all));
}
