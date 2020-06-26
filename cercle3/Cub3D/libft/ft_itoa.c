/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:52:57 by lusokol           #+#    #+#             */
/*   Updated: 2020/01/07 17:20:29 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long int	length_n(long long int n)
{
	unsigned long long int length;

	length = (n <= 0) ? 1 : 0;
	while (n > 0 || n < 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

char							*ft_itoa(int long long n)
{
	char						*p;
	char						sign;
	unsigned long long int		length;

	sign = (n < 0) ? '-' : '\0';
	length = length_n(n);
	if (!(p = malloc(sizeof(char) * (length + 1))))
		return (0);
	p[length] = '\0';
	while (length)
	{
		if (n < 0)
			p[--length] = -(n % 10) + '0';
		else
			p[--length] = (n % 10) + '0';
		n = n / 10;
	}
	if (sign)
		p[length] = sign;
	return (p);
}
