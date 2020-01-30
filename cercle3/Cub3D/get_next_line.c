/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:00:34 by lusokol           #+#    #+#             */
/*   Updated: 2020/01/17 16:04:16 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strchr(char *s, char c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != c)
	{
		if (!s[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(str = malloc(sizeof(char) * i)))
		return (NULL);
	i = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	free((void*)s1);
	return (str);
}

int		ft_read(int fd, char *buff, char **stock)
{
	int ret;

	while (!ft_strchr(stock[fd], '\n') &&
		(ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		stock[fd] = ft_strjoin(stock[fd], buff);
	}
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	int			ret;
	int			index;
	static char	*stock[1024];
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!stock[fd])
		stock[fd] = ft_strdup("");
	if ((ret = ft_read(fd, buff, stock) == -1))
		return (-1);
	index = 0;
	while (stock[fd][index] && stock[fd][index] != '\n')
		index++;
	*line = ft_substr(stock[fd], 0, index);
	tmp = (stock[fd][index]) ? ft_strdup(stock[fd] + index + 1) : NULL;
	free(stock[fd]);
	stock[fd] = tmp;
	if (ret != 0 || stock[fd])
		return (1);
	return (0);
}
