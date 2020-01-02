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
	//char *str = "-abc";
	int a = -1;
	printf("\"|%%-1.0s|\"\n");
	while (a < 5)
	{
		printf("a : %d\n", a);
		printf("printf \t\t: |%*c|\n", a, 0);
		ft_printf("ft_printf \t: |%*c|\n", a, 0);
		a++;
	}
	return 0;
}
