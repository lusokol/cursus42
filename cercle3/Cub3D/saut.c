/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saut.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:14:18 by lusokol           #+#    #+#             */
/*   Updated: 2020/03/06 20:22:14 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_timer(t_cub *all, clock_t jump)
{
	clock_t	timer;
	double	diff;

	timer = clock();
	diff = (double)(timer - jump) / CLOCKS_PER_SEC;
	//calcul
	all->coord.z = sin(diff * M_PI) / 10;
	(void)all;
	if (diff >= 1)
		return (1);
	return (0);
}

void	ft_jump(t_cub *all)
{
	static int ok;
	static clock_t jump;

	if (ok != 1 && ok != 0)
		ok = 0;
	if (ok == 0)
		jump = clock();
	if (all->key.j == 1)
		ok = 1;
	if (ok == 1)
		if (ft_timer(all, jump))
			ok = 0;
}
