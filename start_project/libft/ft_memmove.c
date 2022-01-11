/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:49:25 by lusokol           #+#    #+#             */
/*   Updated: 2021/09/20 14:17:20 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (src < dst && src + n > dst)
	{
		while (n > 0)
		{
			n--;
			((char *)dst)[n] = ((char *)src)[n];
		}
		return (dst + n);
	}
	return (ft_memcpy(dst, src, n));
}
