/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:07:40 by macbookpro        #+#    #+#             */
/*   Updated: 2021/12/24 01:07:08 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin_char(char const *s1, char const s2)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	if (s1)
		i = ft_strlen(s1) + 2;
	else
		i = 2;
	str = malloc(sizeof(char) * i);
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
		str[j++] = s1[i++];
	str[j++] = s2;
	str[j] = '\0';
	if (s1)
		free((void *)s1);
	return (str);
}

void	read_arg(t_all *lst)
{
	int		ret;
	char	*str;
	char	buf[2];

	ret = 1;
	buf[1] = '\0';
	str = NULL;
	lst->act = NULL;
	while (ret > 0)
	{
		ret = read(0, &buf, 1);
		if (ret > 0)
			str = ft_strjoin_char(str, buf[0]);
	}
	if (!str)
		return ;
	lst->act = ft_split(str, '\n');
	free(str);
}
