/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:52:57 by lusokol           #+#    #+#             */
/*   Updated: 2021/09/20 14:56:29 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	unsigned long long int	length_n(long long int n)
{
	unsigned long long int	length;

	if (n <= 0)
		length = 1;
	else
		length = 0;
	while (n > 0 || n < 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int long long n)
{
	char						*p;
	char						sign;
	unsigned long long int		length;

	if (n < 0)
		sign = '-';
	else
		sign = '\0';
	length = length_n(n);
	p = malloc(sizeof(char) * (length + 1));
	if (!p)
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
