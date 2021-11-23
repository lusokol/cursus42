/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:28:59 by lusokol           #+#    #+#             */
/*   Updated: 2021/09/20 14:46:43 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_settest(char const *s1, char const *set, int index)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s1[index] == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*mon_malloc(int len, int i)
{
	char	*str;

	if (len <= 0)
		str = malloc(sizeof(char) * 1);
	else
		str = malloc(sizeof(char) * (len - i + 2));
	return (str);
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
	str = mon_malloc(len, i);
	if (!str)
		return (NULL);
	if (len <= 0)
		str[0] = '\0';
	if (len <= 0)
		return (str);
	while (i <= len)
		str[index++] = s1[i++];
	str[index] = '\0';
	return (str);
}
