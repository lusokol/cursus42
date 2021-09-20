/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:29:53 by lusokol           #+#    #+#             */
/*   Updated: 2020/06/26 14:30:36 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int		missing_arg(t_cub *all)
{
	if (!all->north)
		ft_printf("Error\nMissing argument : NO\n");
	else if (!all->south)
		ft_printf("Error\nMissing argument : SO\n");
	else if (!all->west)
		ft_printf("Error\nMissing argument : WE\n");
	else if (!all->east)
		ft_printf("Error\nMissing argument : EA\n");
	else if (!all->ceilling)
		ft_printf("Error\nMissing argument : C\n");
	else if (!all->floor)
		ft_printf("Error\nMissing argument : F\n");
	else if (!all->sprite)
		ft_printf("Error\nMissing argument : S\n");
	else if (!all->sprite1)
		ft_printf("Error\nMissing argument : S1\n");
	else if (!all->sprite2)
		ft_printf("Error\nMissing argument : S2\n");
	else
		return (1);
	return (0);
}

void	*path(t_cub *all, void *comp, void *comp2)
{
	if (comp == NULL)
		return (comp2);
	else
	{
		ft_printf("Error\nMultiple path.\n");
		ft_exit(all);
	}
	return (0);
}
