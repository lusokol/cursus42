/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:56:27 by macbookpro        #+#    #+#             */
/*   Updated: 2021/10/11 17:20:44 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	key_push(int button, t_data *ptr)
{
	if (button == ITERATION_MORE)
		ptr->all->iteration_max += 20;
	else if (button == ITERATION_LESS)
		ptr->all->iteration_max -= 20;
	else if (button == KEY_DOWN || button == KEY_UP || button == KEY_LEFT
		|| button == KEY_RIGHT)
		move_plan(button, ptr);
	if (button == KEY_DOWN || button == KEY_UP || button == KEY_LEFT
		|| button == KEY_RIGHT || button == ITERATION_LESS
		|| button == ITERATION_MORE)
		myalgo(ptr);
	if (button == ESCAPE)
		ft_exit(0, ptr);
	return (0);
}

int	click_detect(int button, int x, int y, void *ptr)
{
	(void)x;
	(void)y;
	if (button == SCROLL_IN)
		zoom(ptr, 1 - ((float)ZOOM / 100));
	if (button == SCROLL_OUT)
		zoom(ptr, 1 + ((float)ZOOM / 100));
	myalgo(ptr);
	return (0);
}

int	key_detect(int x, int y, t_data *img)
{
	img->all->x = x;
	img->all->y = y;
	return (0);
}
