/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:36:25 by lusokol           #+#    #+#             */
/*   Updated: 2020/03/03 12:54:02 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_pos(char a, int b)
{
	if (b == 1)
		if (a == 'N' || a == 'S' || a == 'W' || a == 'E')
			return (1);
	if (b == 2)
		if (a == ' ')
			return (1);
	return (0);
}

int		replace_zero(int i, int j, char **map)
{
	int tmp;

	tmp = 0;
	if (i > 0 && map[i - 1][j] == '0')
	{
		map[i - 1][j] = ' ';
		tmp = 1;
	}
	if (map[i + 1][j] && map[i + 1][j] == '0')
	{
		map[i + 1][j] = ' ';
		tmp = 1;
	}
	if (j > 0 && map[i][j - 1] == '0')
	{
		map[i][j - 1] = ' ';
		tmp = 1;
	}
	if (map[i][j + 1] == '0')
	{
		map[i][j + 1] = ' ';
		tmp = 1;
	}
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

int		check_map(char **map)
{
	int i;
	int j;
	int res;

	if ((res = start_check(map)) > 1)
		return (-1); //ft_exit("Multiple start position."));
	else if (res == 0)
		return (-1); //ft_exit("Need start position."));
	fill_map(map);
	i = 0;
	j = -1;
	while (map[i][++j])
		if (map[i][j] == ' ')
			return (0);
	while (map[++i + 1])
		if (map[i][0] == ' ' || map[i][ft_strlen(map[i]) - 1] == ' ')
			return (0);
	j = -1;
	while (map[i][++j])
		if (map[i][j] == ' ')
			return (0);
	return (1);
}
