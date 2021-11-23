/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:36:17 by lusokol           #+#    #+#             */
/*   Updated: 2021/09/20 14:47:27 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	int				j;
	char			*res;

	i = 0;
	j = -1;
	if ((!s || len == 0) || start > (unsigned int)ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	while (s[i] && i < start)
		i++;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (++j < (int)len)
		res[j] = s[i + j];
	res[j] = '\0';
	return (res);
}
