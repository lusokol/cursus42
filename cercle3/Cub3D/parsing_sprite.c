/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:26:36 by lusokol           #+#    #+#             */
/*   Updated: 2020/03/07 16:51:37 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sprite(char a)
{
	if (a == '2' || a == '3' || a == '4')
		return (1);
	return (0);
}

void	ft_take_sprite(t_cub *all, int j, int i)
{
	
}

void	sprite_pars(t_cub *all)
{
	int		i;
	int		j;
	int		n;//n ieme sprite du tableau de structure

	j = 0;
	while (all->map[j])
	{
		i = 0;
		while (all->map[j][i])
		{
			if (ft_is_sprite(all->map[j][i]))
				ft_take_sprite(all, j, i);
			i++;
		}
		j++;
	}
}
