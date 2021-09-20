/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:28:59 by lusokol           #+#    #+#             */
/*   Updated: 2019/11/12 14:57:10 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_settest(char const *s1, char const *set, int index)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (s1[index] == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*str;
	int		index;

	index = 0;
	i = 0;
	if (!s1 || !set)
		return (0);
	len = ft_strlen(s1) - 1;
	while (ft_settest(s1, set, i))
		i++;
	while (ft_settest(s1, set, len))
		len--;
	if (!(str = malloc(sizeof(char) * ((len <= 0) ? 1 : (len - i + 2)))))
		return (NULL);
	if (len <= 0)
	{
		str[0] = '\0';
		return (str);
	}
	while (i <= len)
		str[index++] = s1[i++];
	str[index] = '\0';
	return (str);
}
