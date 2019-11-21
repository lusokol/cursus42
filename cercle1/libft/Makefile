# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lusokol <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/18 20:53:32 by lusokol           #+#    #+#              #
#    Updated: 2019/11/12 15:09:01 by lusokol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c \
       ft_isalpha.c \
       ft_bzero.c \
       ft_isascii.c \
       ft_isalnum.c \
       ft_isdigit.c \
       ft_calloc.c \
       ft_isprint.c \
       ft_itoa.c \
       ft_memccpy.c \
       ft_memchr.c \
       ft_memcpy.c \
       ft_memcmp.c \
       ft_memset.c \
       ft_putchar_fd.c \
       ft_putendl_fd.c \
       ft_putstr_fd.c \
       ft_strchr.c \
       ft_putnbr_fd.c \
       ft_strlcat.c \
       ft_strdup.c \
       ft_strjoin.c \
       ft_strlen.c \
       ft_strncmp.c \
       ft_split.c \
       ft_strrchr.c \
       ft_substr.c \
       ft_strlcpy.c \
       ft_toupper.c \
       ft_tolower.c \
       ft_strtrim.c \
       ft_strmapi.c \
       ft_strnstr.c \
		ft_memmove.c \

BONUS_SRCS	=	ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstclear.c \
			ft_lstlast.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_lstmap.c \

FLAGS = -Wall -Wextra -Werror -g3

all: ${NAME}

$(NAME):
	gcc $(FLAGS) -c $(SRCS) -I .
	ar rc $(NAME) $(SRCS:.c=.o) $^
	ranlib $(NAME)

bonus:
	gcc $(FLAGS) -c $(SRCS) $(BONUS_SRCS) -I .
	ar rc $(NAME) $(BONUS_SRCS:.c=.o) $(SRCS:.c=.o) $^
	ranlib $(NAME)

clean:
	rm -rf $(SRCS:.c=.o)

clean_bonus:
	rm -rf $(BONUS_SRCS:.c=.o)

fclean:	clean clean_bonus
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean clean_bonus fclean re
