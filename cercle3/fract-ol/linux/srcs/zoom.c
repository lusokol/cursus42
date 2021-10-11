/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:53:10 by macbookpro        #+#    #+#             */
/*   Updated: 2021/10/11 16:33:48 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	move_plan(int button, t_data *img)
{
	long double	interval_x;
	long double	interval_y;

	interval_x = img->all->x2 - img->all->x1;
	interval_y = img->all->y2 - img->all->y1;
	if (button == KEY_LEFT)
	{
		img->all->x1 = img->all->x1 - (interval_x / 10);
		img->all->x2 = img->all->x2 - (interval_x / 10);
	}
	else if (button == KEY_RIGHT)
	{
		img->all->x1 = img->all->x1 + (interval_x / 10);
		img->all->x2 = img->all->x2 + (interval_x / 10);
	}
	else if (button == KEY_DOWN)
	{
		img->all->y1 = img->all->y1 + (interval_y / 10);
		img->all->y2 = img->all->y2 + (interval_y / 10);
	}
	else if (button == KEY_UP)
	{
		img->all->y1 = img->all->y1 - (interval_y / 10);
		img->all->y2 = img->all->y2 - (interval_y / 10);
	}
}

void	zoom(t_data *img, float zoom)
{
	long double	test1;
	long double	test2;

	test1 = img->all->x / (img->size / (img->all->x2 - img->all->x1))
		+ img->all->x1;
	test2 = img->all->y / (img->size / (img->all->y2 - img->all->y1))
		+ img->all->y1;
	img->all->x1 = test1 + ((img->all->x1 - test1) * zoom);
	img->all->x2 = test1 + ((img->all->x2 - test1) * zoom);
	img->all->y1 = test2 + ((img->all->y1 - test2) * zoom);
	img->all->y2 = test2 + ((img->all->y2 - test2) * zoom);
}
