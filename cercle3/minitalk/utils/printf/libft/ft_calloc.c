/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:48:11 by lusokol           #+#    #+#             */
/*   Updated: 2021/09/20 14:07:07 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if (count == 0 || size == 0)
	{
		size = 1;
		count = 1;
	}
	str = malloc(size * count);
	if (!str)
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}
