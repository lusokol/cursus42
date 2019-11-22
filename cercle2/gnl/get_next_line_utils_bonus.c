/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:14:29 by lusokol           #+#    #+#             */
/*   Updated: 2019/11/22 18:56:44 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_strlen(const char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char		*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	i = 0;
	if (!(dest = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_strjoin(char *s1, char const s2)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = ft_strlen(s1) + 2;
	if (!(str = malloc(sizeof(char) * i)))
		return (NULL);
	i = 0;
	if (s1)
		while (s1[i])
			str[j++] = s1[i++];
	str[j++] = s2;
	str[j] = '\0';
	free(s1);
	return (str);
}

t_gnl		*ft_lstnew(int content)
{
	t_gnl	*new;

	if (!(new = malloc(sizeof(t_gnl))))
		return (NULL);
	new->fd = content;
	new->next = NULL;
	new->fin = 1;
	new->buffer = NULL;
	new->ligne = NULL;
	new->index = 0;
	return (new);
}

void		ft_lstadd_back(t_gnl **alst, t_gnl *new)
{
	t_gnl	*tmp;

	if (!new)
		return ;
	if (*alst)
	{
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->next = 0;
	}
	else
		*alst = new;
}
