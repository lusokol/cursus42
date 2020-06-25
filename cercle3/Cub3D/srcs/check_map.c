/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:36:25 by lusokol           #+#    #+#             */
/*   Updated: 2020/06/25 17:00:22 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_pos(char a, int b)
{
	if (b == 1)
		if (a == 'N' || a == 'S' || a == 'W' || a == 'E')
			return (1);
	if (b == 2)
		if (a == '.')
			return (1);
	if (b == 3)
		if (a == '0' || a == '2' || a == '3' || a == '4' || a == ' ')
			return (1);
	return (0);
}

void	check_fail(int i, int j, char **map)
{
	int tmp;

	tmp = 0;
	if (i > 0 && j >= ft_strlen(map[i - 1]))
	{
		ft_printf("Error\nMap invalid.\n");
		ft_exit(NULL);
	}
	if (map[i + 1] && j >= ft_strlen(map[i + 1]))
	{
		ft_printf("Error\nMap invalid.\n");
		ft_exit(NULL);
	}
}

int		replace_zero(int i, int j, char **map)
{
	int tmp;

	tmp = 0;
	if (i > 0 && j < ft_strlen(map[i - 1]) && (check_pos(map[i - 1][j], 3)))
	{
		map[i - 1][j] = '.';
		tmp = 1;
	}
	if (map[i + 1] && j < ft_strlen(map[i + 1]) && check_pos(map[i + 1][j], 3))
	{
		map[i + 1][j] = '.';
		tmp = 1;
	}
	if (j > 0 && check_pos(map[i][j - 1], 3))
	{
		map[i][j - 1] = '.';
		tmp = 1;
	}
	if (j < ft_strlen(map[i]) && check_pos(map[i][j + 1], 3))
	{
		map[i][j + 1] = '.';
		tmp = 1;
	}
	check_fail(i, j, map);
	return (tmp);
}

int		start_check(char **str)
{
	int i;
	int j;
	int tmp;

	tmp = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (check_pos(str[i][j], 1))
			{
				replace_zero(i, j, str);
				tmp++;
			}
			j++;
		}
		i++;
	}
	return (tmp);
}

void	fill_map(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (check_pos(map[i][j], 2))
				if (replace_zero(i, j, map) == 1)
				{
					j = 0;
					i = 0;
				}
			j++;
		}
		i++;
	}
}

int		check_point(char **map)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (map[i][++j])
		if (map[i][j] == '.')
			return (0);
	while (map[++i + 1])
		if (map[i][0] == '.' || map[i][ft_strlen(map[i]) - 1] == '.')
			return (0);
	j = -1;
	while (map[i][++j])
		if (map[i][j] == '.')
			return (0);
	return (1);
}

int		check_map(char **map)
{
	int res;

	if ((res = start_check(map)) > 1)
	{
		ft_printf("Error\nMultiple start position.\n");
		ft_exit(NULL);
	}
	else if (res == 0)
	{
		ft_printf("Error\nMissing start position.\n");
		ft_exit(NULL);
	}
	fill_map(map);
	return (check_point(map));
}
