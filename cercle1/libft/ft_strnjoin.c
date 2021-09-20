/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:09:28 by lusokol           #+#    #+#             */
/*   Updated: 2021/03/18 11:40:03 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
char	*ft_strnjoin(char *s1, char *s2, int n)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ((ft_strlen(s2) > n) ? n : ft_strlen(s2)) + 1;
	if (!(str = malloc(sizeof(char) * i)))
		return (NULL);
	i = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i] && n-- > 0)
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}
