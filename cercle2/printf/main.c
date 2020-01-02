/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:36:53 by lusokol           #+#    #+#             */
/*   Updated: 2019/12/13 16:24:31 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

void	ft_printf(const char *test, ...);

int main(void)
{
	char *str = "-abc";
	printf("\"|%%-4s|\"\n");
	printf("printf \t\t: |%.*s|\n", -4, str);
	ft_printf("ft_printf \t: |%.*s|\n", -4, str);
	return 0;
}
