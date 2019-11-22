/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:18:19 by lusokol           #+#    #+#             */
/*   Updated: 2019/11/22 18:56:12 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "get_next_line.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_gnl
{
	int				fd;
	int				index;
	char			*ligne;
	int				fin;
	char			*buffer;
	int				ret;
	struct s_gnl	*next;
}					t_gnl;

char				*ft_strjoin(char *s1, char const s2);
char				*ft_strdup(const char *src);
int					get_next_line(int fd, char **line);
int					ft_strlen(const char *s);
char				*ft_search(int fd, t_gnl *lst);
int					ft_check(int fd, t_gnl *lst);
t_gnl				*ft_lstnew(int content);
void				ft_lstadd_back(t_gnl **alst, t_gnl *new);

#endif
