/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:24:32 by lusokol           #+#    #+#             */
/*   Updated: 2021/09/20 14:38:17 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*len;

	if (!s)
		return (NULL);
	len = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!len)
		return (NULL);
	i = 0;
	while (s[i])
	{
		len[i] = (*f)(i, s[i]);
		i++;
	}
	len[i] = '\0';
	return (len);
}
