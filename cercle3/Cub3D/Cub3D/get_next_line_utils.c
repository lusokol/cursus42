/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:48:38 by lusokol           #+#    #+#             */
/*   Updated: 2020/01/17 16:05:18 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	if (!(dest = (char *)malloc(ft_strlen(src) * sizeof(char) + 1)))
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t			i;
	int				j;
	char			*res;

	i = 0;
	j = -1;
	if ((!s || len == 0) || start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	while (s[i] && i < start)
		i++;
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (++j < (int)len)
		res[j] = s[i + j];
	res[j] = '\0';
	return (res);
}
