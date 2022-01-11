/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:54:49 by lusokol           #+#    #+#             */
/*   Updated: 2021/09/20 14:36:17 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **tab, int i)
{
	while (--i)
	{
		free(tab[i]);
		tab[i] = 0;
	}
	free(tab);
	tab = 0;
	return (NULL);
}

static int	ft_taillem(const char *str, int i, char charset)
{
	int	j;

	j = 0;
	while (str[i] != charset && str[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

static int	ft_nbr_mots(const char *str, char charset)
{
	int	i;
	int	nbr_mots;

	i = 0;
	nbr_mots = 0;
	if (!str)
		return (-10);
	while (str[i])
	{
		while (str[i] == charset)
			i++;
		if (str[i])
			nbr_mots++;
		while (str[i] != charset && str[i] != '\0')
			i++;
	}
	return (nbr_mots);
}

char	**ft_split(const char *str, char c)
{
	int			is;
	int			i;
	int			j;
	char		**tab;

	is = 0;
	tab = malloc(sizeof(char *) * (ft_nbr_mots(str, c) + 1));
	if (!tab || !str)
		return (0);
	i = 0;
	while (i < ft_nbr_mots(str, c))
	{
		j = 0;
		while (str[is] == c && str[is])
			is++;
		tab[i] = malloc(sizeof(char) * (ft_taillem(str, is, c) + 1));
		if (!(tab[i]))
			return (ft_free(tab, i));
		while (str[is] != c && str[is])
			tab[i][j++] = str[is++];
		tab[i++][j] = '\0';
	}
	tab[i] = NULL;
	return (tab);
}
