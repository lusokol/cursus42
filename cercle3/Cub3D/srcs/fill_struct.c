/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:35:29 by lusokol           #+#    #+#             */
/*   Updated: 2020/06/26 14:34:31 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cub		*ft_get_map(char **str, t_cub *all)
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

char		**create_tab(int fd)
{
	char	**str;
	char	*tmp;
	char	*line;

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

int			ft_take_rgb(char *str)
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

void		*info(t_cub *all, char *str, int i, int type)
{
	int j;

	j = 0;
	if (str[j] == ' ')
		j++;
	else
	{
		ft_printf("Error\nMissing space at the argument %d after\"%c\"\n",
				i + 1, str[-1]);
		ft_exit(all);
	}
	while (str[j] && str[j] == ' ')
		j++;
	if (str[j] == '\n' || str[j] == '\0')
	{
		ft_printf("Error\nMissing argument line %d.\n", i + 1);
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

t_cub		*ft_fill_struct(char **str)
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
