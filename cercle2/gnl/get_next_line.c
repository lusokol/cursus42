/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:51:58 by lusokol           #+#    #+#             */
/*   Updated: 2019/11/22 19:10:37 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_check(int fd, t_gnl *lst)
{
	//printf("test\n");
	while (lst)
	{
		//printf("fd : %d\tlst->fd : %d\n", fd, lst->fd);
		if (lst->fd == fd)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void		ft_reset(t_gnl *lst)
{
	char	buffer[BUFFER_SIZE + 1];
	int		i;

	i = 0;
	while (i <= BUFFER_SIZE)
		buffer[i++] = '\0';
	if ((lst->index) >= (BUFFER_SIZE))
	{
		//if (lst->buffer)
		//	free((lst->buffer));
		lst->ret = read((lst->fd), buffer, BUFFER_SIZE);
		if (lst->buffer)
			free(lst->buffer);
		lst->buffer = ft_strdup(buffer);
		lst->index = 0;
		//printf("test\n");
	}
	else if (lst->buffer)
	{
		if ((lst->buffer)[(lst->index)] == '\0' && (lst->ret > (lst->index) || lst->fd == 0))
		{
			lst->ret = read((lst->fd), buffer, BUFFER_SIZE);
			if (lst->buffer)
				free(lst->buffer);
			lst->buffer = ft_strdup(buffer);
			lst->index = 0;
		}
	}
}

int			ft_create(t_gnl *lst)
{
	char	buffer[BUFFER_SIZE + 1];
	int		i;

	i = 0;
	//if (lst->ligne)
	//	free((lst->ligne));
	ft_reset(lst);
	while (i <= BUFFER_SIZE)
		buffer[i++] = '\0';
	if (!(lst->buffer))
	{
		if ((lst->ret = read((lst->fd), buffer, BUFFER_SIZE)) == -1)
			return (-1);
		if (!(lst->buffer))
			free(lst->buffer);
		lst->buffer = ft_strdup(buffer);
	}
	while((lst->buffer)[(lst->index)] != '\n' && (lst->buffer)[(lst->index)])
	{
		lst->ligne = ft_strjoin((lst->ligne), (lst->buffer)[(lst->index)++]);
		ft_reset(lst);
	}
	if (((lst->buffer)[lst->index] == '\0' && lst->ret != BUFFER_SIZE))
		lst->fin = 0;
	if ((lst->buffer)[lst->index] != '\0')
		lst->index = lst->index + 1;
	//printf("index : %d\n", (lst->index));
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static t_gnl	*lst;
	t_gnl			*tmp;

	if (fd < 0 || !line || BUFFER_SIZE == 0)
		return (-1);
	if (!lst)
		lst = ft_lstnew(fd);
	else if (!ft_check(fd, lst))
		ft_lstadd_back(&lst, ft_lstnew(fd));
	tmp = lst;
	while (tmp->fd != fd)
		tmp = tmp->next;
	if (!(tmp->fin))
		return (0);
	tmp->ligne = ft_strdup("");
	if (tmp->fin)
		if (ft_create(tmp) == -1)
			return (-1);
	if (!(tmp->ligne))
		tmp->ligne = ft_strdup("");
	*line = tmp->ligne;
	if (!(tmp->fin))
		tmp->fd = -1;
	if (!(tmp->fin))
		free(tmp->buffer);
	return ((tmp->fin));
}

/*int		main(int argc, char **argv)
{
	char    *line;
	int        fd;
	int     i = 0;;

	(void)argc;
	//(void)argv;
	fd = open(argv[1], O_RDONLY);
	//fd = 0;
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		//break;
	}
	printf("|%s\n", line);
	free(line);
	return (0);
}*/
