/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:50:03 by lusokol           #+#    #+#             */
/*   Updated: 2019/11/21 18:50:18 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (dest[i] && size > 0)
	{
		size--;
		i++;
	}
	while (*src && size > 1)
	{
		dest[i++] = *src++;
		size--;
	}
	if (size > 0)
		dest[i] = '\0';
	while (*src++)
		i++;
	return (i);
}
